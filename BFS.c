#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100
// Queue implementation for BFS
int queue[MAX], front=-1, rear=-1;
void enqueue(int value) {
    if(rear==MAX-1){
        printf("Queue Overflow\n");
        return;
    }
    if(front==-1){
        front=0;
    }
    queue[++rear]=value;
}

int dequeue() {
    if (front==-1 || front>rear) {
        printf("Queue Underflow\n");
        return -1;
    }
    return queue[front++];
}

bool isQueueEmpty() {
    return front==-1 || front>rear;
}

// BFS Function
void BFS(int graph[MAX][MAX], int n, int start) {
    bool visited[MAX]={false};
    printf("BFS Traversal starting from vertex %d:\n", start);
    enqueue(start);
    visited[start]=true;
    while (!isQueueEmpty()){
        int current=dequeue();
        printf("%d ",current);

        for(int i=0;i<n;i++){
            if (graph[current][i] == 1 && !visited[i]) {
                enqueue(i);
                visited[i]=true;
            }
        }
    }
    printf("\n");
}

// Function to display the adjacency matrix
void displayGraph(int graph[MAX][MAX], int n) {
    printf("Adjacency Matrix:\n");
    for (int i=0;i<n;i++) {
        for (int j=0;j<n;j++){
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int graph[MAX][MAX] = {0};
    int n, choice;
    printf("Enter the number of vertices in the graph: ");
    scanf("%d", &n);
    while (1){
        printf("**************************");
        printf("\n        Menu:         \n");
        printf("1. Add Edge\n");
        printf("2. Display Graph\n");
        printf("3. Perform BFS\n");
        printf("4. Exit\n");
        printf("**************************\n");
        printf("Enter your choice: ");
        
        scanf("%d", &choice);
        switch (choice) {
        case 1: {
            int u, v;
            printf("Enter the source and destination vertices (u v): ");
            scanf("%d %d", &u, &v);
            if (u >= 0 && u < n && v >= 0 && v < n) {
                graph[u][v] = 1;
                graph[v][u] = 1; // Assuming an undirected graph
            } else {
                printf("Invalid vertices. Please try again.\n");
            }
            break;
        }
        case 2:
            displayGraph(graph, n);
            break;
        case 3: {
            int start;
            printf("Enter the starting vertex for BFS: ");
            scanf("%d", &start);
            if (start >= 0 && start < n) {
                BFS(graph, n, start);
            } else {
                printf("Invalid starting vertex.\n");
            }
            break;
        }
        case 4:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice. Please try again.\n");
        }
    }

    return 0;
}
