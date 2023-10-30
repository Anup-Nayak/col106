#include <iostream>
#include <vector>
#include <stack>
#include <string>

using namespace std;

// Define a simple binary tree node structure
struct TreeNode {
    string value;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        value = "";
        left = NULL;
        right = NULL;
    }

    TreeNode(string val){
        value = val;
        left = NULL;
        right = NULL;
    }
};

// Function to build the parse tree
TreeNode* buildParseTree(vector<string> expression) {
    vector<TreeNode*> st;
    TreeNode* root = new TreeNode(expression[1]);
    TreeNode* leftChild = new TreeNode(expression[0]);
    TreeNode* rightChild = new TreeNode();
    root->left = leftChild;
    root->right = rightChild;
    st.push_back(rightChild);
    TreeNode* curr = new TreeNode();
    curr = rightChild;
    
    for(int i=2;i<expression.size();i++){
        if(expression[i] == "("){
            TreeNode* temp = new TreeNode();
            curr->left = temp;
            st.push_back(curr);
            curr = curr->left;
        }else if(expression[i] == "+" or expression[i] == "-" or expression[i] == "/" or expression[i] == "*"){
            curr->value = expression[i];
            TreeNode* r = new TreeNode();
            curr->right = r;
            st.push_back(curr);
            curr = curr->right;
        }else if(expression[i] == ")"){
            int n = st.size();
            TreeNode* pr = new TreeNode();
            pr = st[n - 1];
            curr = pr;
            st.pop_back();
        }else if((expression[i][0] >= 'a' and expression[i][0] <= 'z') or (expression[i][0] >= 'A' and expression[i][0] <= 'Z') or (expression[i][0] == '_')){
            curr->value = expression[i];
            int n = st.size();
            TreeNode* pr = new TreeNode();
            pr = st[n - 1];
            st.pop_back();
            curr = pr;
        }else{
            curr->value = expression[i];
            int n = st.size();
            TreeNode* pr = new TreeNode();
            pr = st[n - 1];
            st.pop_back();
            curr = pr;
        }
    }

    return root;



}

// Function to perform postorder traversal and print the tree
void inorder(TreeNode* node) {
    if(node == NULL){
        return;
    }
    
    inorder(node->left);
    cout << node->value << " ";
    inorder(node->right);
        
    
}

int main() {
    vector<string> expression = {"v", ":=", "(", "13", "+", "(", "v", "+", "(", "2", "/", "SSfvdj", ")", ")"};
    TreeNode* parseTree = buildParseTree(expression);
    inorder(parseTree);
    cout << endl;

    // Clean up the memory allocated for the tree
    // Implement a function to free the tree nodes (not shown in this example).

    return 0;
}
