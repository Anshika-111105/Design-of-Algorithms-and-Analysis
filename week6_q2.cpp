#include <iostream>
#include <vector>
#include <queue>
using namespace std;
bool isBipartite(int V, const vector<vector<int>>& adj) {
    vector<int> color(V, -1);
    for (int start = 0; start < V; ++start) {
        if (color[start] != -1) continue;  // already colored
        queue<int> q;
        color[start] = 0;
        q.push(start);
        while (!q.empty()) {
            int v = q.front(); 
            q.pop();
            for (int w : adj[v]) {
                if (color[w] == -1) {
                    // Assign opposite color
                    color[w] = 1 - color[v];
                    q.push(w);
                }
                else if (color[w] == color[v]) {
                    // Same color on both ends ⇒ not bipartite
                    return false;
                }
            }
        }
    }
    return true;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int V, E;
    cin >> V >> E;
    vector<vector<int>> adj(V);
    for (int i = 0; i < E; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);  // undirected graph
    }
    cout << (isBipartite(V, adj) ? "Graph is Bipartite\n": "Graph is NOT Bipartite\n");
    return 0;
}
