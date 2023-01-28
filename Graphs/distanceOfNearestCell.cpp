//Distance of nearest set having 1

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

vector<vector<int> > bfs(vector<vector<int> > grid){
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int> > vis(n, vector<int> (m,0));
    vector<vector<int> > ans = vis;
    queue<pair<pair<int, int>, int> > q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1){
                q.push(make_pair(make_pair(i,j), 0));
                vis[i][j] = 1;
            }
        }
    }

    int dRow[] = {0, -1, 0, 1};
    int dCol[] = {-1, 0, 1, 0};
    while(!q.empty()){
        int r = q.front().first.first;
        int c = q.front().first.second;
        int p = q.front().second;
        q.pop();
        ans[r][c] = p;
        for(int i=0;i<4;i++){
            int nRow = r + dRow[i];
            int nCol = c + dCol[i];
            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < n && vis[nRow][nCol] != 1){
                q.push(make_pair(make_pair(nRow, nCol), p+1));
                vis[nRow][nCol] = 1;
            }
        }
    }
    return ans;

}

int main(){
    int n,m;
    cout<<"Enter the number of rows :: ";
    cin>>n;
    cout<<"Enter the number of columns :: ";
    cin>>m;

    vector<vector<int> > grid(n, vector<int> (m,0));
    cout<<"Enter the numbers :: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    vector<vector<int> > answer = bfs(grid);

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<answer[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}