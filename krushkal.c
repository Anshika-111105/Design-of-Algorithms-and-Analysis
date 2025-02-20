#include <stdio.h>
#include <stdlib.h>

#define MAX 100
// Structure to represent an edge
typedef struct{
    int u,v,weight;
}Edge;
// Structure to represent a subset for union-find
typedef struct {
    int parent;
    int rank;
} Subset;
Edge edges[MAX];      // Array to store graph edges
Edge result[MAX];     // Array to store the MST edges
int edgeCount = 0;    // Number of edges in the graph

// Compare function for qsort
int compareEdges(const void *a, const void *b) {
    Edge *e1=(Edge *)a;
    Edge *e2=(Edge *)b;
    return e1->weight-e2->weight;
}

// Find function for union-find
int find(Subset subsets[], int i){
    if(subsets[i].parent!=i){
        subsets[i].parent=find(subsets, subsets[i].parent);
    }
    return subsets[i].parent;
}
// Union function for union-find
void unionSubsets(Subset subsets[], int x, int y) {
    int rootX=find(subsets,x);
    int rootY=find(subsets,y);
    if (subsets[rootX].rank<subsets[rootY].rank){
        subsets[rootX].parent=rootY;
    }else if(subsets[rootX].rank>subsets[rootY].rank){
        subsets[rootY].parent=rootX;
    }else{
        subsets[rootY].parent=rootX;
        subsets[rootX].rank++;
    }
}
// Kruskal's algorithm
void kruskal(int V) {
    int mstEdges = 0;      // Number of edges in MST
    int totalWeight = 0;   // Total weight of the MST

    // Sort edges by weight
    qsort(edges, edgeCount, sizeof(Edge), compareEdges);
    // Create subsets for union-find
    Subset *subsets = (Subset *)malloc(V * sizeof(Subset));
    for (int v=0;v<V;v++){
        subsets[v].parent=v;
        subsets[v].rank=0;
    }
    // Process edges
    for (int i = 0;i<edgeCount && mstEdges<V-1;i++) {
        Edge nextEdge = edges[i];
        int uSet=find(subsets, nextEdge.u);
        int vSet=find(subsets, nextEdge.v);

        // If the edge doesn't form a cycle, include it in the MST
        if (uSet!=vSet) {
            result[mstEdges++]=nextEdge;
            totalWeight+=nextEdge.weight;
            unionSubsets(subsets,uSet,vSet);
        }
    }

    // Print the MST
    printf("Edges in the MST:\n");
    for (int i=0;i<mstEdges;i++){
        printf("%d -- %d == %d\n", result[i].u, result[i].v, result[i].weight);
    }
    printf("Total weight of MST: %d\n",totalWeight);

    free(subsets);
}

int main() {
    int V, E;  // Number of vertices and edges
    printf("Enter the number of vertices and edges: ");
    scanf("%d %d", &V, &E);

    printf("Enter the edges (u v weight):\n");
    for(int i=0;i<E;i++){
        int u, v, weight;
        scanf("%d %d %d", &u, &v, &weight);
        edges[edgeCount++]=(Edge){u, v, weight};
    }
    kruskal(V);
    return 0;
}