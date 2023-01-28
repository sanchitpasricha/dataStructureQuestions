#include<iostream>
using namespace std;

class stacksTwo{
    int *arr;
    int size;
    int top1, top2;

    public:
        twoStacks(int n){
            size = n;
            *arr = new int[size];
            top1 = n/2 + 1;
            top2 = n/2;
        }
        void push1(int x){
            if(top1 > 0){
                top1 --;
                arr[top1] = x;
            }
        }

        void push2(int x){
            if(top < size-1){
                top2 ++;
                arr[top2] = x;
            }
        }

        void 
}

int main(){

}