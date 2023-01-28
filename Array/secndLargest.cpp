#include<iostream>
#include<algorithm>
using namespace std;

int main(){

    int n=4;
    int arr[] = {4,7,2,9};

    sort(arr, arr+n);
    reverse(arr, arr+n);
    cout<<arr[1];
    return 0;
}