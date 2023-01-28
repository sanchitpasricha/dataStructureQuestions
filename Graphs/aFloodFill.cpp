#include<iostream>
#include<vector>
using namespace std;

void dfs(int row, int col, vector<vector<int> >& ans, vector<vector<int> > image, int newColor, int delRow[], int delCol[], int init){
    
    ans[row][col] = newColor;
    int n = image.size();
    int m = image[0].size();
    for(int i=0;i<4;i++){
        int nRow = row + delRow[i];
        int nCol = col + delCol[i];

        if(nRow >= 0 && nRow < n && nCol >= 0 && nCol < m && image[nRow][nCol] == init && ans[nRow][nCol] != newColor){
            dfs(nRow, nCol, ans, image, newColor, delRow, delCol, init);
        }
    }
}

vector<vector<int> > floodFill(int sr, int sc, vector<vector<int> > image, int newColor){
    int initialColor = image[sr][sc];
    vector<vector<int> > ans = image;
    int delRow[] = {-1, 0, 1, 0};
    int delCol[] = {0, 1, 0, -1};

    dfs(sr, sc, ans, image, newColor, delRow, delCol, initialColor);
    return ans;
}

int main(){
    int n,m;
    cout<<"Enter the number of rows :: ";
    cin>>n;
    cout<<"Enter the number of columns :: ";
    cin>>m;

    vector<vector<int> > image(n, vector<int> (m,0));
    cout<<"Enter the pixel values of image :: "<<endl;

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>image[i][j];
        }
    }

    vector<vector<int> > output = floodFill(2, 0, image, 3);
    
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<output[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}