#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void dfs(int row, int col, vector<vector<int> >& vis, vector<vector<char> > grid, int delRow[], int delCol[]){
    vis[row][col] = 1;
    int n = grid.size();
    int m = grid[0].size();
    for(int i=0;i<4;i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && grid[nRow][nCol] == 'o' && !vis[nRow][nCol]){
            dfs(nRow, nCol, vis, grid, delRow, delCol);
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter the number of rows :: ";
    cin>>n;
    cout<<"Enter the number of columns :: ";
    cin>>m;
     
    vector<vector<char> > grid(n, vector<char> (m));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }

    int drow[] = {0, -1, 0, 1};
    int dcol[] = {-1, 0, 1, 0};
    vector<vector<int> > vis(n, vector<int> (m,0));

     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i == 0 || j == 0 || i == n-1 || j == n-1){
                if(grid[i][j] == 'o'){
                    dfs(i,j,vis,grid,drow,dcol);
                }
            }
        }
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 'o' && vis[i][j] != 1){
                grid[i][j] = 'x';
            }
        }
    }
    cout<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<grid[i][j]<<" ";
        }
        cout<<endl;
    }

    return 0;
}