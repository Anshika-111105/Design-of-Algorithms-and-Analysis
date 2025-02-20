#include<iostream>
using  namespace std;
typedef struct BST{
    int key;
    struct BST *left;
    struct BST *right;
}node;
node* insert(node* root,int value){
    if(root==NULL){
        node* newnode=(node*)malloc(sizeof(node));
        newnode->key=value;
        return newnode;
    }
    if(root->key>value){
        root->left=insert(root->left,value);
    }else{
        root->right=insert(root->right,value);
    }
    return root;
}
void Preorder(node* root){ //root->left->right
    if(root==NULL){
        return ;
    }
    cout<<root->key<<" ";
    Preorder(root->left);
    Preorder(root->right);
}
void Inorder(node* root){ //left->root->right
    if(root==NULL){
        return ;
    }
    Inorder(root->left);
    cout<<root->key<<" ";
    Inorder(root->right);
}
void Postorder(node* root){ //left->right->root
    if(root==NULL){
        return ;
    }
    Postorder(root->left);
    Postorder(root->right);
    cout<<root->key<<" ";
}
int main(){
    int values[]={5,1,3,4,2,7};
    int n=sizeof(values)/sizeof(values[0]);
    node* root=NULL;
    for(int i=0;i<n;i++){
        root=insert(root,values[i]);
    }
    Inorder(root);
    cout<<endl;
    return 0;
}