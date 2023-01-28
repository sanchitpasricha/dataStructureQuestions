#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*top=NULL;

void push(int x){
    struct Node *t;
    t = new struct Node;

    if(t == NULL){
        cout<<"Stack Overflow";
    }
    else{
        t -> data = x;
        t -> next = top;
        top = t;
    }
}

int pop(){
    struct Node *t;
    int x = -1;

    if(top == NULL){
        cout<<"Stack is Empty";
    }
    else{
        t = top;
        top=top->next;
        x = t->data;
        free(t);
    }
    return x;
}


int main(){
    push(10);
    push(20);
    push(30);
    cout<<pop()<<endl;
    cout<<pop();
}