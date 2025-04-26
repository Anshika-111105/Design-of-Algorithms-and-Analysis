#include <iostream>
#include <vector>
#include <climits>
using namespace std;
struct Edge {
    int src, dest, weight;
};
void bellmanFord(int V, int start, vector<vector<pair<int,int>>>& adj, int src) {
    vector<int> dist(V, INT_MAX);
    dist[src] = 0;
    for (int i = 1; i <= V - 1; i++) { //v-1 times
        for (int j = 0; j < V; j++) {
            if(dist[j]==INT_MAX)continue;
            for(auto neighbour:adj[j]){
                int v=neighbour.first;
                int w=neighbour.second;
                if (dist[j] + w < dist[v]) {
                    dist[v] = dist[j] + w;
                }
            }
        }
    }
    for (int j=0;j<V;j++) { //negative weight cycles
        if (dist[j] != INT_MAX )continue;
        for(auto neighbour:adj[j]){
            int v=neighbour.first;
            int w=neighbour.second;
            if (dist[j] + w < dist[v]) {
                return false;
            }
        }
        
    }
    for (int i = 0; i < V; i++) {
        if (dist[i] == INT_MAX)
            cout << i << "\t" << "INF" << endl;
        else
            cout << i << "\t" << dist[i] << endl;
    }
}
int main() {
    int V = 5;
    int E = 8; 
    vector<Edge> adj(E);
    adj[0] = {0, 1, -1};
    adj[1] = {0, 2, 4};
    adj[2] = {1, 2, 3};
    adj[3] = {1, 3, 2};
    adj[4] = {1, 4, 2};
    adj[5] = {3, 2, 5};
    adj[6] = {4, 3, -3};
    int src= 0;
    bellmanFord(V,E,adj,src);
    return 0;
}
