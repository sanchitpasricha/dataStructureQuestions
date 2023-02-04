#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, vector<int> adj[], vector<int> &vis, vector<int> &pathVis){
    vis[node] = 1;
    pathVis[node] = 1;
    for(auto x : adj[node]){
        if(!vis[x]){
            if(dfs(x, adj, vis, pathVis) == true) return true;
        }
        else if(pathVis[x] == 1){
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}   

int main(){
    int n,m;
    cout<<"Enter the number of Nodes :: ";
    cin>>n;
    cout<<"Enter the number of Edges :: ";
    cin>>m;

    vector<int> adj[n+1];
    vector<int> vis(n+1,0);
    vector<int> pathVis(n+1,0);
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    for(int i=1;i<=n;i++){
        if(!vis[i]){
            if(dfs(i, adj, vis, pathVis) == true) {
                cout<<"Has cycle";
                return 0;
            }
        }
    }
    cout<<"No cycle detected !";
    return 0;

}