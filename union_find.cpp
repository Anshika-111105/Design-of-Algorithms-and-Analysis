#include <bits\stdc++.h>
#include <climits>
using namespace std;
int find(vector<int>& parent,int node){
    if(node==parent[node]){
        return node;
    }else{
        return parent[node]=find(parent,parent[node]);
    }
}
void union_by_rank(int u,int v,vector<int>& rank,vector<int>& parent){
    int x = find(parent,u);
    int y = find(parent,v);
    if(x==y)return;
    if(rank[x]==rank[y]){
        parent[x]=y;
        rank[y]++;
    }
    else if(rank[x]>rank[y]){
        parent[y]=x;
    }else{
        parent[x]=y;
    }

}
int main(){
    int V,E;
    cout<<"Enter the no of vertices & edges : ";
    cin>>V>>E;
    vector<int> rank(V+1,0);
    vector<int> parent(V+1);
    for(int i=1;i<=V;i++){
        parent[i]=i;
    }

    vector<pair<int,pair<int,int>>> edges;
    for(int i=1;i<=E;i++){
        int u,v,w;
        //cout<<"Enter u,v,w : ";
        cin>>w>>u>>v;
        edges.push_back({w,{u,v}});
    }
    sort(edges.begin(),edges.end());
    int mst=0;
    vector<pair<int,int>> mst_edges(V);
    for(auto it:edges){
        int w=it.first;
        int u=it.second.first;
        int v=it.second.second;
        if(find(parent,u)!=find(parent,v)){
            union_by_rank(u,v,parent,rank);
            mst+=w;
            mst_edges.push_back({u,v});
            
        }
    }
    cout<<" MST : "<<mst<<endl;
    return 0;
}