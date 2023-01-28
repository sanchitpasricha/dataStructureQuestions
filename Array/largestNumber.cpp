#include<algorithm>
#include<iostream>
using namespace std;

void largestNumber(int arr[], int n){
    sort(arr,arr+n);
    reverse(arr, arr+n);

    cout<<arr[1];
}

int main(){
    int arr[] = {1,2,3,2,8,222,3,1,22,15,3121};
    int size = sizeof(arr) / sizeof(arr[0]);

    largestNumber(arr, size);
}