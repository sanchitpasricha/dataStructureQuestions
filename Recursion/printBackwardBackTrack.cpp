#include<iostream>
using namespace std;

void printNumber(int i, int n){
    if(i > n){
        return;
    }
    printNumber(i+1, n);
    cout<<i<<endl;
}

int main(){
    int n;
    cin>>n;
    printNumber(1,n);
}