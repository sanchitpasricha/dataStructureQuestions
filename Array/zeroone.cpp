#include<iostream>
using namespace std;

int main(){
    int arr[6] = {0,1,0,1,1,0};
    int size = 6;
    int i=0,j=size-1;

    while(i<j){
        if(arr[i] == 1 && arr[j] == 0){
            swap(arr[i],arr[j]);
            i++;
            j--;
        }
        else if(arr[i] == 0){
            i++;
        }
        else if(arr[j] == 1){
            j--;
        }
    }

    for(int i=0;i<size;i++){
        cout<<arr[i]<<endl;
    }

    return 0;
}