#include<iostream>
using  namespace std;
typedef struct BST{
    int key;
    struct BST *left;
    struct BST *right;
}node;
bool search(node* root,int value){
    if(root==NULL){
        return false;
    }
    if(root->key==value){
        return true;
    }
    if(root->key>value){
        search(root->left,value);
    }
    else if(root->key>value){
        search(root->right,value);
    } 
}

