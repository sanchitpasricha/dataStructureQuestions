#include<iostream>
#include<vector>
using namespace std;

int main(){
    int arr[10] = {1,2,3,4,5};
    vector<int> ans;
    int size = 5;
    int s = 12;
    for(int i=0;i<size-2;i++){
        for(int j=i+1;j<size-1;j++){
            for(int k=j+1;k<size;k++){
                if(arr[i]+arr[j]+arr[k] == s){
                   ans.push_back(arr[i]);
                   ans.push_back(arr[j]);
                   ans.push_back(arr[k]); 
                }
            }
        }
    }
    if(ans.size() == 0){
        cout<<"No triplet";
    }
    else{
        for(int i=0;i<ans.size();i++){
            cout<<ans[i]<<endl;
        }
    }
}