#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int data;
    struct Node *left, *right;
}Node;
Node* createNode(int data) {
    struct Node *newNode=(struct Node *)malloc(sizeof(struct Node));
    newNode->data=data;
    newNode->left=newNode->right=NULL;
    return newNode;
}
// Function to insert a node into the BST
Node* insert(Node *root,int data){
    if(root == NULL){
        return createNode(data);
    }
    if(data<root->data){
        root->left=insert(root->left,data);
    }else if(data>root->data){
        root->right=insert(root->right, data);
    }
    return root;
}
// Function to find the node with the smallest data
Node* findsmallest(Node *root){
    while(root && root->left!=NULL) {
        root=root->left;
    }
    return root;
}

// Function to delete a node from the BST
Node *deleteNode(Node *root,int key) {
    if (root==NULL) return root;
    if (key < root->data) {
        root->left=deleteNode(root->left, key);
    }else if(key>root->data){
        root->right=deleteNode(root->right, key);
    }else{
        if(root->left==NULL){
            Node *temp=root->right;
            free(root);
            return temp;
        }else if (root->right==NULL){
            Node *temp = root->left;
            free(root);
            return temp;
        }

        Node *temp=findsmallest(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right, temp->data);
    }
    return root;
}
// Function to count nodes having a common parent
int countCommonParent(Node *root) {
    if (root==NULL || (root->left==NULL && root->right==NULL)) {
        return 0;
    }
    int count = 0;
    if (root->left!=NULL && root->right!=NULL) {
        count++;
    }
    return count + countCommonParent(root->left) + countCommonParent(root->right);
}
// Function to find the height of the BST
int findHeight(Node *root) {
    if (root == NULL) return -1;
    int leftHeight=findHeight(root->left);
    int rightHeight=findHeight(root->right);
    return (leftHeight>rightHeight?leftHeight:rightHeight) + 1;
}
// Function to count total nodes on the right-hand side of the root
int countRightNodes(Node *root) {
    if (root==NULL|| root->right==NULL) return 0;
    int count=1;
    Node *current=root->right;
    while(current!=NULL){
        count++;
        if(current->left!=NULL)count++;
        current=current->right;
    }
    return count;
}
// Function to display the tree in-order
void inOrder(Node *root) {
    if(root != NULL){
        inOrder(root->left);
        printf("%d ",root->data);
        inOrder(root->right);
    }
}
int main() {
    Node *root = NULL;
    int choice, value;
    while (1) {
        printf("************************************\n");
        printf("..............MENU....................\n");
        printf("1. Insert \n");
        printf("2. Find Smallest\n");
        printf("3. Delete Node\n");
        printf("4. Count Common Parent Nodes\n");
        printf("5. Find Height\n");
        printf("6. Count Right Nodes\n");
        printf("7. Display In-Order\n");
        printf("8. Exit\n");
        printf("************************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root=insert(root, value);
            break;
        case 2:
            if (root==NULL) {
                printf("Tree is empty.\n");
            } else {
                struct Node *minNode=findsmallest(root);
                printf("Smallest value in BST: %d\n",minNode->data);
            }
            break;

        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root=deleteNode(root, value);
            break;

        case 4:
            printf("Number of nodes with common parent: %d\n", countCommonParent(root));
            break;

        case 5:
            printf("Height of the tree: %d\n", findHeight(root));
            break;

        case 6:
            printf("Total nodes on the right side of the root: %d\n", countRightNodes(root));
            break;

        case 7:
            printf("In-Order Traversal: ");
            inOrder(root);
            printf("\n");
            break;

        case 8:
            exit(0);

        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
