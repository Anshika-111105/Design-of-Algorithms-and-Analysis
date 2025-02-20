#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure to represent a node in the adjacency list
typedef struct AdjListNode{
    int dest;
    int weight;
    struct AdjListNode* next;
}AdjListNode;
// Structure to represent the adjacency list of a vertex
struct AdjList{
    struct AdjListNode* head; // Pointer to the head of the list
};
// Structure to represent the entire graph
typedef struct Graph{
    int vertices;
    struct AdjList* array; // Array of adjacency lists
}graph;
// Function to create a new adjacency list node
AdjListNode* createNode(int dest, int weight){
    AdjListNode* newNode=(AdjListNode*)malloc(sizeof(AdjListNode));
    newNode->dest=dest;
    newNode->weight=weight;
    newNode->next=NULL;
    return newNode;
}
// Function to create a graph with `vertices` vertices
graph* createGraph(int vertices){
    graph* g=(graph*)malloc(sizeof(graph));
    g->vertices=vertices;
    // Create an array of adjacency lists
    g->array=(struct AdjList*)malloc(vertices*sizeof(struct AdjList));
    // Initialize each adjacency list as empty
    for (int i=0;i<vertices;i++) {
        g->array[i].head=NULL;
    }
    return g;
}
// Function to add an edge to the graph
void addEdge(graph* g, int src, int dest, int weight){
    // Add an edge from src to dest
    AdjListNode* newNode=createNode(dest, weight);
    newNode->next=g->array[src].head;
    g->array[src].head=newNode;
    // Add an edge from dest to src for undirected graph (optional)
    // Comment this part if the graph is directed
    newNode=createNode(src, weight);
    newNode->next=g->array[dest].head;
    g->array[dest].head=newNode;
}
// Function to display the graph
void displayGraph(graph* g){
    for (int i=0;i<g->vertices;i++){
        AdjListNode* temp=g->array[i].head;
        printf("Vertex %d:\n",i);
        while(temp){
            printf(" -> %d (weight: %d)",temp->dest, temp->weight);
            temp=temp->next;
        }
        printf("\n");
    }
}
int main()
{
    int vertices, edges, src, dest, weight;
    //Input number of vertices and edges
    printf("Enter the number of vertices: ");
    scanf("%d",&vertices);
    struct Graph* graph=createGraph(vertices);
    printf("\nEnter the number of edges: ");
    scanf("%d",&edges);
    printf("\nEnter the edges(source destination weight):\n");
    for(int i=0;i<edges;i++){
        scanf("%d %d %d",&src,&dest,&weight);
        addEdge(graph,src,dest,weight);
    }
    printf("\nGraph representation:\n");
    displayGraph(graph);
    return 0;
}
