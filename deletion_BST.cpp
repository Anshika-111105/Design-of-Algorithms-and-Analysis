#include<iostream>
using  namespace std;
typedef struct BST{
    int key;
    struct BST *left;
    struct BST *right;
}node;
node* inorderSuccessor(node *root)
node* deletenode(node* root,int value){
    if(root->key>value){
        root->left=deletenode(root->left,value);
    }
    else if(root->key<value){
        root->right=deletenode(root->right,value);
    }else{   
        if(root->left == NULL && root->right == NULL){
            return NULL;        //leaf node 
        }
        if(root->right==NULL){  //one child
            return root->left;
        }
        else if(root->left=NULL){   //one child
            return root->right;
        }

    }

}
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
void Inorder(node* root){ //left->root->right
    if(root==NULL){
        return ;
    }
    Inorder(root->left);
    cout<<root->key<<" ";
    Inorder(root->right);
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