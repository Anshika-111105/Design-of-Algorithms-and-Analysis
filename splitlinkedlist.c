#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}node;
// Function to create a new node
node* createNode(int data){
    node* newNode=(node*)malloc(sizeof(node));
    newNode->data=data;
    newNode->next=NULL;
    return newNode;
}
// Function to insert a node at the end of the linked list
void insert(node** head,int data) {
    node* newNode=createNode(data);
    if(*head==NULL){
        *head=newNode;
        return;
    }
    node* temp=(*head);
    while(temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
}
// Function to print the linked list
void display(node* head){
    node* temp=head;
    while (temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}
// Function to split linked list P into Q (odd positions) and R (even positions)
void split(node* P,node** Q,node** R) {
    int position=1;
    while (P!=NULL) {
        if (position % 2!=0) {
            insert(Q,P->data); // Add to Q if position is odd
        } else {
            insert(R,P->data); // Add to R if position is even
        }
        P=P->next;
        position++;
    }
}
int main() {
    node* P=NULL;
    node* Q=NULL;
    node* R=NULL;
    int n, value;
    // Input linked list P
    printf("Enter the number of elements in linked list P: ");
    scanf("%d",&n);
    printf("Enter the elements of linked list P: \n");
    for (int i=0; i<n;i++){
        printf("Enter element:");
        scanf("%d",&value);
        insert(&P,value);
    }
    // Split the list into Q and R
    split(P, &Q, &R);
    printf("Original linked list P: \n");
    display(P);
    printf("Linked list Q (odd positions): \n");
    display(Q);
    printf("Linked list R (even positions): \n");
    display(R);
    return 0;
}