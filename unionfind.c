#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    int Emp_Id;
    char Name[50];
    struct Node* next;
}Node;

// Function to create a new node
Node* createNode(int emp_id, char* name) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    newNode->Emp_Id=emp_id;
    strcpy(newNode->Name, name);
    newNode->next=NULL;
    return newNode;
}

// Function to insert a node at the end of the list
Node* insert(Node* head,int emp_id, char* name) {
    Node* newNode=createNode(emp_id, name);
    if (head==NULL) {
        return newNode;
    }
    Node* temp=head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=newNode;
    return head;
}

// Function to check if an employee ID exists in the list
int exists(Node* head, int emp_id) {
    Node* temp=head;
    while (temp!=NULL) {
        if (temp->Emp_Id==emp_id) {
            return 1; // Found
        }
        temp=temp->next;
    }
    return 0; // Not found
}

// Function to find the union of two linked lists
Node* unionLists(Node* head1, Node* head2) {
    Node* unionHead = NULL;
    Node* temp=head1;
    // Add all elements of the first list to the union list
    while (temp != NULL) {
        unionHead = insert(unionHead, temp->Emp_Id, temp->Name);
        temp = temp->next;
    }
    // Add only non-duplicate elements from the second list
    temp=head2;
    while (temp!=NULL) {
        if (!exists(unionHead,temp->Emp_Id)) {
            unionHead = insert(unionHead, temp->Emp_Id, temp->Name);
        }
        temp=temp->next;
    }

    return unionHead;
}

// Function to display the linked list
void display(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("Emp_Id: %d, Name: %s\n", temp->Emp_Id, temp->Name);
        temp=temp->next;
    }
}

int main() {
    Node* list1 =NULL;
    Node* list2=NULL;
    int n, emp_id;
    char name[50];
    printf("Enter number of employees in List 1: ");
    scanf("%d",&n);
    for (int i=0;i<n; i++){
        printf("Enter Emp_Id and Name for employee %d: ", i + 1);
        scanf("%d %[^\n]", &emp_id, name);
        list1=insert(list1, emp_id, name);
    }
    printf("\n");
    printf("Enter number of employees in List 2: ");
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        printf("Enter Emp_Id and Name for employee %d: ", i + 1);
        scanf("%d %[^\n]", &emp_id, name);
        list2=insert(list2, emp_id, name);
    }

    printf("\nList 1:\n");
    display(list1);
    printf("\nList 2:\n");
    display(list2);
    Node* unionList = unionLists(list1, list2);
    printf("\nUnion of the two lists:\n");
    display(unionList);

    return 0;
}