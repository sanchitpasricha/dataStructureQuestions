#include<iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *s, int size){
    s -> S = new int[size];
    s -> size = size;
    s -> top = -1;
}

void push(struct Stack *st, int x){
    if(st -> top == st -> size-1){
        cout<<"Stack overflow";
    }
    else{
        st -> top++;
        st -> S[st -> top] = x;
    }
}

int pop(struct Stack *st){
    int x=-1;
    if(st -> top == -1){
        cout<<"Stack is empty";
    }
    else{
        x = st -> S[st -> top--];
    }
    return x;
}

int main(){
    struct Stack st;
    create(&st, 5);
    push(&st, 10);
    push(&st, 20);
    push(&st, 30);
    push(&st, 40);
    cout<<pop(&st);
}