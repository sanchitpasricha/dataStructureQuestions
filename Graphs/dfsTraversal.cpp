#include<iostream>
#include<vector>
using namespace std;

void dfs(int node, vector<int> adj[], int vis[], vector<int>& ls){
    vis[node] = 1;
    ls.push_back(node);
    for(auto it:adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis, ls);
        }   
    }
}

vector<int> dfsTraversal(int n, vector<int> adj[]){
    int vis[n+1];
    for(int i=0;i<=n;i++){
        vis[i] = 0;
    }
    int start = 1;
    vector<int> ls;
    dfs(start, adj, vis, ls);
    return ls;
}

int main(){
    int n,m;
    cout<<"Enter number of Nodes :: ";
    cin>>n;
    cout<<"Enter number of edges :: ";
    cin>>m;

    vector<int> adj[n+1];
    vector<int> ans;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = dfsTraversal(n,adj);

    for(auto it:ans){
        cout<<it<<" ";
    }
}