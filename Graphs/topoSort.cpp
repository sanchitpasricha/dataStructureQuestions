#include<iostream>
#include<vector>
#include<stack>
using namespace std;

void dfs(int node, vector<int> adj[], vector<int> &vis, stack<int> &st){
    vis[node]=1;
    for(auto x : adj[node]){
        if(!vis[x]){
            dfs(x, adj, vis, st);
        }
    }
    st.push(node);
}

int main(){
    int n,m;
    cout<<"Enter the number of Nodes :: ";
    cin>>n;
    cout<<"Enter the number of Edges :: ";
    cin>>m;

    vector<int> adj[n+1];
    stack<int> st;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }
    vector<int> vis(n+1,0);

    for(int i=0;i<n;i++){
        if(!vis[i]){
            dfs(i, adj, vis, st);
        }
    }

    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
    return 0;
}