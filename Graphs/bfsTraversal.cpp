#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<int> bfsOfGraphs(int n, vector<int> adj[]){
    
    int visited[n+1];
    for(int i=0;i<=n;i++){
        visited[i] = 0;
    }
    visited[1] = 1;
    queue<int> q;
    q.push(1);
    vector<int> bfs;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        bfs.push_back(node);

        for(auto it:adj[node]){
            if(!visited[it]){
                visited[it] = 1;
                q.push(it);
            }
        }
    } 
    return bfs;
}

int main(){

    int n,m;
    cout<<"Number of nodes :: ";
    cin>>n;
    cout<<"Number of edges :: ";
    cin>>m;

    vector<int> adj[n+1];
    vector<int> ans;

    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    ans = bfsOfGraphs(n,adj);
    for(int i=0;i<n;i++){
        cout<<ans[i]<<" ";
    }

}