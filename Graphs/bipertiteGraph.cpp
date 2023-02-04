#include<iostream>
#include<vector>
using namespace std;

bool dfs(int node, int color, vector<int> adj[], vector<int> &vis){
    vis[node] = color;
    for(auto x:adj[node]){
        if(vis[x] == -1){
            if(dfs(x, !color, adj, vis) == false) return false;
        }
        else if(vis[x] == color){
            return false;
        }
    }
    return true;
}

int main(){
    int n,m;
    cout<<"Enter the number of Nodes :: ";
    cin>>n;
    cout<<"Enter the number of Edges :: ";
    cin>>m;

    vector<int> adj[n+1];
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }


    vector<int> vis(n+1,-1);
    
    if(dfs(1,0,adj,vis) == false){
        cout<< 0;
        return 0;
    }
    else{
        cout<< 1;
    }
    // for(int i=0;i<n;i++){
    //     if(vis[i] == -1){
    //         if(dfs(i, 0, adj, vis) == false) cout<<0;
    //     }
    // }
    return 0;
}
