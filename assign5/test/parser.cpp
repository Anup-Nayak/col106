/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "parser.h"

//Write your code below this line

Parser::Parser(){
    symtable = new SymbolTable();
    last_deleted = -1;
}

void Parser::parse(vector<string> expression){
    vector<ExprTreeNode*> st;
    ExprTreeNode* root = new ExprTreeNode();
    root->id = ":=";
    root->num = 1;
    root->type = "";

    ExprTreeNode* leftChild = new ExprTreeNode();
    //changes
    if(expression[0]=="ret"){
        leftChild->type="RET";
    }else if(expression[0]=="del"){
        leftChild->type="DEL";
    }else{
        leftChild->id = expression[0];
        leftChild->type = "VAR";
    }
    

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
            //change
            curr->id = expression[i];
            ExprTreeNode* pr = new ExprTreeNode();
            int n = st.size();
            pr = st[n - 1];
            st.pop_back();
            curr = pr;
            
        }else{
            curr->type = "VAL";
            curr->num = stoi(expression[i]);
            curr->id = expression[i];
            ExprTreeNode* pr = new ExprTreeNode();
            int n = st.size();
            pr = st[n - 1];
            st.pop_back();
            curr = pr;
            
        }
    }

    expr_trees.push_back(root);

    if(leftChild->type=="VAR"){
        int oo = symtable->search(leftChild->id);
        if(oo == -2){
            symtable->insert(leftChild->id);
        }
    }else if(leftChild->type=="DEL"){
        last_deleted = symtable->search(leftChild->id);
        symtable->remove(leftChild->id);

    }
}

Parser::~Parser(){
    expr_trees.clear();
    delete symtable;
}

#include<iostream>
using namespace std;

int main() {
    vector<string> code = {"a", ":=", "(", "(", "2", "*", "4",")","+", "10", ")"};
    Parser P;
    cout << "worksing" << endl;
    P.parse(code);
    ExprTreeNode *root = P.expr_trees.back();
    cout << root->type << endl;
    cout << root->left->type << endl;
    cout << root->right->type << endl;
    cout << root->right->right->type << endl;
    cout << root->right->left->type << endl;

    return 0;
}