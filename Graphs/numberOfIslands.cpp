#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void bfs(int row, int col, vector<vector<int> >& vis, vector<vector<int> > islands){
    vis[row][col] = 1;
    queue<pair<int , int> > qe;
    qe.push({row , col});
    int n = islands.size();
    int m = islands[0].size();
    while(!qe.empty()){
        int row = qe.front().first;
        int col = qe.front().second;
        qe.pop();

        for(int del_row = -1; del_row<= 1;del_row++){
            for(int del_col = -1; del_col<= 1;del_col++){
                int nrow = row + del_row;
                int ncol = col + del_col;

                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && islands[nrow][ncol] == 1 && !vis[nrow][ncol]){
                    vis[nrow][ncol] = 1;
                    qe.push({nrow,ncol});
                }
            }
        }
    }
}

int main(){
    int n,m;
    cout<<"Enter the number of Nodes :: ";
    cin>>n;
    cout<<"Enter the number of Edges :: ";
    cin>>m;

    vector<vector<int> > islands(n, vector<int> (m,0));
    vector<vector<int> > vis(n, vector<int> (m,0));


    cout<<"Enter the land and water :: "<<endl;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>islands[i][j];
        }
    }

    int count = 0;

    for(int row = 0; row < n; row++){
        for(int col = 0; col < m; col++){
            if(islands[row][col] == 1 && !vis[row][col]){
                count++;
                bfs(row, col, vis, islands);
            }
        }
    }

    cout<<count;

    return 0;
}