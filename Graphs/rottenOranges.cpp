#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int orangeRotting(vector<vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<pair<int, int>, int> > q;
    vector<vector<int> > vis = grid;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 2){
                q.push(make_pair(make_pair(i,j), 0));
                vis[i][j] = 2;
            }
            else{
                vis[i][j] = 0;
            }
        }
    }
    int tm = 0;
    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int t = q.front().second;

        tm = max(tm, t);
        q.pop();
        for(int i=0;i<4;i++){
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if(nrow >= 0 && nrow < n && ncol >=0 && ncol < m && vis[nrow][ncol] != 2 && grid[nrow][ncol] == 1){
                q.push(make_pair(make_pair(nrow, ncol), t+1));
                vis[nrow][ncol] = 2;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] != 2 && grid[i][j] == 1){
                return -1;
            }
        }
    }
    return tm;
}

int main(){
    int n,m;
    cout<<"Enter the number of Rows :: ";
    cin>>n;
    cout<<"Enter the number of Columns :: ";
    cin>>m;

    vector<vector<int> > grid(n,vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int ans = orangeRotting(grid);
    cout<<ans;
    return 0;
}