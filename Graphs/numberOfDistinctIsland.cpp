#include<iostream>
#include<vector>
#include<set>
using namespace std;

void dfs(int row, int col, vector<vector<int> > grid, vector<vector<int> > &vis, vector<pair<int, int> > &vec,int row0, int col0){
    int n = grid.size();
    int m = grid[0].size();
    vis[row][col] = 1;
    vec.push_back(make_pair(row - row0, col - col0));
    
    int dRow[] = {-1, 0, 1, 0};
    int dCol[] = {0, 1, 0, -1};
    for(int i=0;i<4;i++){
        int nrow = row + dRow[i];
        int ncol = col + dCol[i];
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol] != 1 && grid[nrow][ncol] == 1){
            dfs(nrow, ncol, grid, vis, vec, row0, col0);
        }
    }

}


int main(){
    int n,m;
    cout<<"Enter the number of rows :: ";
    cin>>n;
    cout<<"Enter the number of columns :: ";
    cin>>m;

    vector<vector<int> > grid(n, vector<int> (m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>grid[i][j];
        }
    }
    vector<vector<int> > vis(n, vector<int> (m,0));
    set<vector<pair<int, int> > > st;
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(grid[i][j] == 1 && vis[i][j] != 1){
                vector<pair<int, int> > vec;
                dfs(i, j, grid, vis, vec, i, j);
                st.insert(vec);
            }
        }
    }
    cout<<st.size();
    return 0;
}