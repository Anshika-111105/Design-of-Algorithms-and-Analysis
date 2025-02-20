/*#include <stdio.h>
#include <stdlib.h>
#define MAX 20

// Graph represented using adjacency matrix
int graph[MAX][MAX];
int visited[MAX];
int vertices;

// Function to add an edge to the graph
void addEdge(int start, int end) {
    if (start >= 0 && start < vertices && end >= 0 && end < vertices) {
        graph[start][end] = 1;
        graph[end][start] = 1; // For undirected graph
    } else {
        printf("Invalid vertices!\n");
    }
}

// Function to perform DFS
void DFS(int vertex) {
    printf("%d ", vertex);
    visited[vertex] = 1;

    for (int i = 0; i < vertices; i++) {
        if (graph[vertex][i] == 1 && !visited[i]) {
            DFS(i);
        }
    }
}
// Function to reset visited array
void resetVisited() {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
}

int main() {
    int choice, startVertex;

    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);

    // Initialize graph and visited array
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            graph[i][j] = 0;
        }
        visited[i] = 0;
    }

    do {
        printf("*****************************");
        printf("\n           Menu:           \n");
        printf("1. Add Edge\n");
        printf("2. Perform DFS\n");
        printf("3. Exit\n");
        printf("*****************************\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                {
                    int start, end;
                    printf("Enter the start and end vertices of the edge: ");
                    scanf("%d %d", &start, &end);
                    addEdge(start, end);
                }
                break;

            case 2:
                printf("Enter the starting vertex for DFS: ");
                scanf("%d", &startVertex);
                if (startVertex < 0 || startVertex >= vertices) {
                    printf("Invalid starting vertex!\n");
                } else {
                    printf("DFS traversal starting from vertex %d: ", startVertex);
                    resetVisited();
                    DFS(startVertex);
                    printf("\n");
                }
                break;

            case 3:
                printf("Exiting program.\n");
                break;

            default:
                printf("Invalid choice!\n");
                break;
        }
    } while (choice != 3);

    return 0;
}
*/
// DFS algorithm in C

#include <stdio.h>
#include <stdlib.h>

struct node {
  int vertex;
  struct node* next;
};

struct node* createNode(int v);

struct Graph {
  int numVertices;
  int* visited;

  // We need int** to store a two dimensional array.
  // Similary, we need struct node** to store an array of Linked lists
  struct node** adjLists;
};

// DFS algo
void DFS(struct Graph* graph, int vertex) {
  struct node* adjList = graph->adjLists[vertex];
  struct node* temp = adjList;

  graph->visited[vertex] = 1;
  printf("%d ", vertex);

  while (temp != NULL) {
    int connectedVertex = temp->vertex;

    if (graph->visited[connectedVertex] == 0) {
      DFS(graph, connectedVertex);
    }
    temp = temp->next;
  }
}

// Create a node
struct node* createNode(int v) {
  struct node* newNode = malloc(sizeof(struct node));
  newNode->vertex = v;
  newNode->next = NULL;
  return newNode;
}

// Create graph
struct Graph* createGraph(int vertices) {
  struct Graph* graph = malloc(sizeof(struct Graph));
  graph->numVertices = vertices;

  graph->adjLists = malloc(vertices * sizeof(struct node*));

  graph->visited = malloc(vertices * sizeof(int));

  int i;
  for (i = 0; i < vertices; i++) {
    graph->adjLists[i] = NULL;
    graph->visited[i] = 0;
  }
  return graph;
}

// Add edge
void addEdge(struct Graph* graph, int src, int dest) {
  // Add edge from src to dest
  struct node* newNode = createNode(dest);
  newNode->next = graph->adjLists[src];
  graph->adjLists[src] = newNode;

  // Add edge from dest to src
  newNode = createNode(src);
  newNode->next = graph->adjLists[dest];
  graph->adjLists[dest] = newNode;
}

// Print the graph
void printGraph(struct Graph* graph) {
  int v;
  for (v = 0; v < graph->numVertices; v++) {
    struct node* temp = graph->adjLists[v];
    printf("\n Adjacency list of vertex %d : ", v);
    while (temp) {
      printf("(%d,%d) ",v, temp->vertex);
      temp = temp->next;
    }
    printf("\n");
  }
  printf("\n");
}

int main() {
  struct Graph* graph = createGraph(4);
  addEdge(graph, 0, 1);
  addEdge(graph, 0, 2);
  addEdge(graph, 1, 2);
  addEdge(graph, 2, 3);

  printGraph(graph);

  DFS(graph, 2);

  return 0;
}