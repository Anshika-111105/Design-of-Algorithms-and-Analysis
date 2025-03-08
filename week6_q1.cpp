#include <iostream>
#include <vector>
using namespace std;
class Graph {
    int V;
    vector<vector<int>> adj;
    bool dfs(int src, int dest, vector<bool>& visited) {
        if (src == dest) return true;
        
        visited[src] = true;
        
        for (int neighbor : adj[src]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, dest, visited)) {
                    return true;
                }
            }
        }
        return false;
    }

public:
    Graph(int V) {
        this->V = V;
        adj.resize(V);
    }
    
    void addEdge(int u, int v) {
        adj[u].push_back(v); // Directed graph
        // adj[v].push_back(u); // Uncomment this for an undirected graph
    }
    
    bool isPathExists(int src, int dest) {
        vector<bool> visited(V, false);
        return dfs(src, dest, visited);
    }
};

int main() {
    int V, E;
    cin >> V >> E;
    Graph g(V);
    
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        g.addEdge(u, v);
    }
    
    int src, dest;
    cin >> src >> dest;
    
    if (g.isPathExists(src, dest)) {
        cout << "Yes Path Exists" << endl;
    } else {
        cout << "No Such Path Exists" << endl;
    }
    
    return 0;
}
