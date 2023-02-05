#include<iostream>
#include<vector>
#include<queue>
using namespace std;

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
    }

    vector<int> inDegree(n+1,0);
    for(int i=0;i<n;i++){
        for(auto x : adj[i]){
            inDegree[x]++;
        }
    }

    queue<int> q;
    for(int i=0;i<n;i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }

    vector<int> ans;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ans.push_back(node);

        for(auto it : adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0){
                q.push(it);
            }
        }
    }

    for(auto it : ans){
        cout<<it<<" ";
    }
    return 0;
}