#include <bits/stdc++.h>
#include <climits>
using namespace std;
int prims(int V,int start,vector<vector<pair<int,int>>>& adj, vector<int>& visited){
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;   
    int mst=0;
    pq.push({0, start});
    while(!pq.empty()){
        auto it=pq.top();
        int w=it.first;
        int u=it.second;
        pq.pop();
        if(visited[u])continue;
        mst+=w;
        visited[u]=1;
        for(auto edge:adj[u]){
            int w=edge.first;
            int u=edge.second;
            pq.push({w, u});
        }
    }
    return mst;
}
int main(){
    int V,E;
    cin>>V>>E;
    vector<vector<pair<int, int>>> adj(V);
    vector<int> visited(V,0);
    for (int i=0; i<E; i++) 
    {
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v, w});
    }
    int source;
    cout << "Enter source node: ";
    cin >> source;
    int result = prims(V, source, adj, visited);
    cout<< "Minimum cost of the MST : " << result<<endl;
    return 0;
}
