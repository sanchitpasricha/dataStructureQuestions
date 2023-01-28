#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> adj[], int visited[]){
    visited[node] = 1;
    for(auto it:adj[node]){
        if(!visited[it]){
            dfs(it,adj,visited);
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter the number of Nodes :: ";;
    cin>>n;
    cout<<"Enter the number of Edges :: ";
    cin>>m;
    vector<int> adjLs[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adjLs[u].push_back(v);
        adjLs[v].push_back(u);
    }

    int vis[n+1];
    for(int i=0;i<=n;i++){
        vis[i] = 0;
    }
    int cnt = 0;
    vis[0] = 1;
    for(int i=0;i<=n;i++){
        if(!vis[i]){
            cnt++;
            dfs(i,adjLs,vis);
        }
    }

    cout<<cnt;
    return 0;

}