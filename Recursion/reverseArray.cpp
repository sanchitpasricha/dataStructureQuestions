#include<iostream>
using namespace std;

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}

void reverseArray(int i, int arr[], int n){
    if(i > n/2){
        return;
    }
    swap(arr[i], arr[n-i-1]);
    reverseArray(i+1, arr, n);
}

void printArray(int i, int arr[],int n){
    if(i > n-1){
        return;
    }
    cout<<arr[i]<<" ";
    printArray(i+1,arr,n);
}

int main(){
    int a[] = {1,2,3,4,5};
    reverseArray(0,a,5);
    printArray(0,a,5);
}