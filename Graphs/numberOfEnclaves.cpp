#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(vector<vector<int> > grid, vector<vector<int> >& vis){
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, int> > q;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 || j == 0 || i == n-1 || j == n-1){
                if(grid[i][j] == 1){
                    q.push(make_pair(i,j));
                }
                
            }
        }
    }

    int drow[] = {-1, 0, 1, 0};
    int dcol[] = {0, 1, 0, -1};
    while(!q.empty()){
        int row = q.front().first;
        int col = q.front().second;
        q.pop();
        for(int i=0;i<4;i++){
            int nRow = row + drow[i];
            int nCol = col + dcol[i];

            if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && vis[nRow][nCol] != 1 && grid[nRow][nCol] == 1){
                q.push(make_pair(nRow, nCol));
                vis[nRow][nCol] = 1;
            }
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter the number of rows :: ";
    cin>>n;
    cout<<"Enter the number of columns :: ";
    cin>>m;

    vector<vector<int> > grid(n,vector<int> (m,0));
    vector<vector<int> > vis(n,vector<int> (m,0));

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    bfs(grid,vis);
    cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 && vis[i][j] != 1){
                grid[i][j] = 0;
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}
