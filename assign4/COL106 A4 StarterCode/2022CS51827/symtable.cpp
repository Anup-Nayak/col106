/* Do NOT add/remove any includes statements from this header file */
/* unless EXPLICTLY clarified on Piazza. */
#include "symtable.h"

SymEntry* MIN(SymEntry *node){
    SymEntry *current = node;
    while (current->left != NULL){
        current = current->left;
    }
    return current;
}

SymEntry* REMOVE(SymEntry *node, string k){
    if (node == NULL){
        return node;
    }

    if (k < node->key){
        node->left = REMOVE(node->left, k);
    }else if (k > node->key){
        node->right = REMOVE(node->right, k);
    }else{
        if (node->left == NULL){
            SymEntry *temp = node->right;
            delete node;
            return temp;
        }else if (node->right == NULL){
            SymEntry *temp = node->left;
            delete node;
            return temp;
        }

        SymEntry *temp = MIN(node->right);

        node->key = temp->key;
        node->val = temp->val;

        node->right = REMOVE(node->right, temp->key);
    }
    return node;
}


SymEntry* SEARCH(SymEntry *node, string k){
    if (node == NULL){
        return NULL; 
    }

    if (k == node->key){
        return node;
    }else if (k < node->key){
        return SEARCH(node->left, k);
    }else{
        return SEARCH(node->right, k);
    }
}

SymbolTable::SymbolTable(){
    size = 0;
    root = NULL;
};

SymbolTable::~SymbolTable(){
    root->right = NULL;
    root->left = NULL;
    root->key = "";
    root->~SymEntry();
};

SymEntry* INSERT(SymEntry *node, string k, UnlimitedRational *v){
    if (node == NULL){
        return new SymEntry(k, v);
    }
    if (k < node->key){
        node->left = INSERT(node->left, k, v);
    }
    else if (k > node->key){
        node->right = INSERT(node->right, k, v);
    }

    return node;
}

void SymbolTable::insert(string k, UnlimitedRational *v){
    if (root == NULL){
        root = new SymEntry(k, v);
    }else{
        root = INSERT(root, k, v);
    }
    size++;
}


void SymbolTable::remove(string k){
    root = REMOVE(root, k);
    size--;
}


UnlimitedRational* SymbolTable::search(string k){
    SymEntry* node = SEARCH(root, k);
    if (node != NULL){
        return node->val;
    }else{
        UnlimitedInt* minus_one = new UnlimitedInt(-1);
        UnlimitedInt* one = new UnlimitedInt(1);
        UnlimitedRational* minus_1 = new UnlimitedRational(minus_one, one);
        delete minus_one;
        delete one;
        
        return minus_1;
    }
}

int SymbolTable::get_size(){
    return size;
}

SymEntry* SymbolTable::get_root(){
    return root;
}