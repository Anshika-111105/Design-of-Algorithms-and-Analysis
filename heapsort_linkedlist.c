#include <stdio.h>
#include <stdlib.h>

// Node structure for the doubly linked list
typedef struct Node {
    int id;
    struct Node* next;
    struct Node* prev;
}Node;

// Priority queue structure
typedef struct PriorityQueue{
    Node* head;
}PriorityQueue;

// Function to create a new node
Node* createNode(int id) {
    Node* newNode=(Node*)malloc(sizeof(Node));
    if(!newNode){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->id=id;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

// Function to initialize a priority queue
PriorityQueue* createQueue(){
    PriorityQueue* pq=(PriorityQueue*)malloc(sizeof(PriorityQueue));
    if(!pq){
        printf("Memory allocation failed.\n");
        exit(1);
    }
    pq->head=NULL;
    return pq;
}
// Function to insert an element into the priority queue
void insert(PriorityQueue* pq, int id) {
    Node* newNode=createNode(id);
    if (!pq->head || pq->head->id>id){ // Insert at the head if it has the highest priority
        newNode->next=pq->head;
        if(pq->head){
            pq->head->prev=newNode;
        }
        pq->head=newNode;
    }else{
        Node* current=pq->head;
        while (current->next && current->next->id<=id) {
            current=current->next;
        }
        newNode->next=current->next;
        if(current->next){
            current->next->prev=newNode;
        }
        newNode->prev=current;
        current->next=newNode;
    }
    printf("Inserted ID %d into the queue.\n", id);
}

// Function to delete the highest-priority element from the queue
void delete(PriorityQueue* pq) {
    if(!pq->head){
        printf("The queue is empty.\n");
        return;
    }
    Node* temp=pq->head;
    pq->head=pq->head->next;
    if(pq->head){
        pq->head->prev=NULL;
    }
    printf("Deleted ID %d from the queue.\n", temp->id);
    free(temp);
}

// Function to display the elements of the queue
void display(PriorityQueue* pq) {
    if (!pq->head) {
        printf("The queue is empty.\n");
        return;
    }
    Node* current=pq->head;
    printf("Queue elements: ");
    while(current){
        printf("%d ",current->id);
        current=current->next;
    }
    printf("\n");
}

// Main function
int main() {
    PriorityQueue* pq=createQueue();
    int choice, id;
    while (1){
		printf("*************************\n");
        printf("Priority Queue Menu:\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
		printf("*************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter ID to insert: ");
                scanf("%d", &id);
                insert(pq, id);
                break;
            case 2:
                delete(pq);
                break;
            case 3:
                display(pq);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
