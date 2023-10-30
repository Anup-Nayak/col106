/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "evaluator.h"

// Function to build the parse tree

Evaluator::Evaluator(){
    symtable = new SymbolTable();
};

Evaluator::~Evaluator(){
    expr_trees.clear();
    delete symtable;
};

// Read an input vector of tokens (strings)
// Parse it and convert it to a parse tree
// Push the root of the tree in the expr_trees
void Evaluator::parse(vector<string> code){

    vector<string> expression = code;

    vector<ExprTreeNode*> st;
    ExprTreeNode* root = new ExprTreeNode();

    ExprTreeNode* leftChild = new ExprTreeNode();
    leftChild->id = expression[0];
    leftChild->type = "VAR";

    ExprTreeNode* rightChild = new ExprTreeNode();

    root->left = leftChild;
    root->right = rightChild;
    st.push_back(rightChild);

    ExprTreeNode* curr = new ExprTreeNode();
    curr = rightChild;
    int n = expression.size();
    
    for(int i=2;i<n;i++){
        if(expression[i] == "("){
            ExprTreeNode* temp = new ExprTreeNode();
            curr->left = temp;
            st.push_back(curr);
            curr = curr->left;
        }else if(expression[i] == "+" or expression[i] == "-" or expression[i] == "/" or expression[i] == "*"){
            if(expression[i] == "+"){
                curr->type = "ADD";
            }else if(expression[i] == "-"){
                curr->type = "SUB";
            }else if(expression[i] == "*"){
                curr->type = "MUL";
            }else if(expression[i] == "/"){
                curr->type = "DIV";
            }
            
            ExprTreeNode* r = new ExprTreeNode();
            curr->right = r;
            st.push_back(curr);
            curr = curr->right;
        }else if(expression[i] == ")"){
            int n = st.size();
            ExprTreeNode* pr = new ExprTreeNode();
            pr = st[n - 1];
            curr = pr;
            st.pop_back();
            

        }else if((expression[i][0] >= 'a' and expression[i][0] <= 'z') or (expression[i][0] >= 'A' and expression[i][0] <= 'Z') or (expression[i][0] == '_')){
            curr->type = "VAR";
            UnlimitedRational* v = symtable->search(expression[i]);
            curr->val = v;
            curr->id = expression[i];
            ExprTreeNode* pr = new ExprTreeNode();
            int n = st.size();
            pr = st[n - 1];
            st.pop_back();
            curr = pr;
            
        }else{
            curr->type = "VAL";
            UnlimitedInt *v = new UnlimitedInt(expression[i]);
            UnlimitedInt *one = new UnlimitedInt(1);
            curr->val = new UnlimitedRational(v, one);
            ExprTreeNode* pr = new ExprTreeNode();
            int n = st.size();
            pr = st[n - 1];
            st.pop_back();
            curr = pr;
            delete v;
            delete one;
            
        }
    }

    expr_trees.push_back(root);

};

// Evaluate the last element of the expr_trees
// This function is guaranteed to be called immediately 
// after a call to parse, and will be only called ONCE
// for a tree
// Also populate the symbol tables

UnlimitedRational* EVALUATE(ExprTreeNode* root, SymbolTable* symtable){

    UnlimitedInt *one = new UnlimitedInt(0);
    UnlimitedInt *zero = new UnlimitedInt(1);

    UnlimitedRational *rzero = new UnlimitedRational(one, zero);
    delete one;
    delete zero;

    if (root == NULL){
        return rzero;
    }
        

    // leaf node i.e, an integer or variable
    if (root->left== NULL and root->right== NULL){
        if(root->type=="VAL"){
            root->evaluated_value= root->val;
            return root->val;
        }else if(root->type=="VAR"){
            UnlimitedRational* temp = symtable->search(root->id);
            root->evaluated_value = temp;
            return temp;
        }
    }
        

    // Evaluate left subtree
    UnlimitedRational* leftVal = EVALUATE(root->left,symtable);

    // Evaluate right subtree
    UnlimitedRational* rightVal = EVALUATE(root->right,symtable);

    // Check which operator to apply
    UnlimitedRational* temp = new UnlimitedRational();

    if (root->type=="ADD"){
        temp = temp->UnlimitedRational::add(leftVal,rightVal);
        
    }else if (root->type=="SUB"){
        temp = temp->UnlimitedRational::sub(leftVal,rightVal);
        
    }else if (root->type=="MUL"){
        temp = temp->UnlimitedRational::mul(leftVal,rightVal);
        
    }else if (root->type=="DIV"){
        temp = temp->UnlimitedRational::div(leftVal,rightVal);
        
    }
    root->evaluated_value= temp;
    return temp;

};

void Evaluator::eval(){
    int size = expr_trees.size();
    ExprTreeNode* root = expr_trees[size-1];
    ExprTreeNode* leftChild = root->left;
    ExprTreeNode* rightChild = root->right;

    UnlimitedRational* result = EVALUATE(rightChild,symtable);
    symtable->insert(leftChild->id,result);

};