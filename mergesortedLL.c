// C Program to merge two sorted linked list using
// recursion
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;
Node* createNode(int x) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

// Takes two lists sorted in increasing order, and splices
// their nodes together to make one big sorted list which is
// returned
Node* mergeSortedList(Node* a, Node* b) {
    Node* result = NULL;

    // Base cases
    if (a == NULL)
        return b;
    else if (b == NULL)
        return a;

    // Pick either a or b, and recur
    if (a->data <= b->data) {
        result = a;
        result->next = mergeSortedList(a->next, b);
    }
    else {
        result = b;
        result->next = mergeSortedList(a, b->next);
    }
    return result;
}

// Driver code
int main() {
  
    // Create a hard-coded linked list:
    // 2 -> 4 -> 8 -> 9
    Node* a = createNode(2);
    a->next = createNode(4);
    a->next->next = createNode(8);
    a->next->next->next = createNode(9);

    // Create another hard-coded linked list:
    // 1 -> 3 -> 8 -> 10
    Node* b = createNode(1);
    b->next = createNode(3);
    b->next->next = createNode(8);
    b->next->next->next = createNode(10);

    Node* res = mergeSortedList(a, b);

    Node* temp = res;
      printf("Merged Link List is:\n");
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    return 0;
}