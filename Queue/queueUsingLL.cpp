#include<iostream>
using namespace std;

struct Node{
    int data;   
    struct Node *next;
}*front=NULL, *rare=NULL;

void enqueue(int x){
    struct Node *t;
    t = new struct Node;

    if(t == NULL){
        cout<<"Queue is full";
    }
    else{
        t -> data = x;
        t -> next = NULL;
        if(front == NULL){
            front=rare=t;
        }
        else{
            rare -> next = t;
            rare = t;
        }
    }
}

int dequeue(){
    struct Node *p;
    int x = -1;

    if(front == NULL){
        cout<<"Queue is Empty";
    }
    else{
        x = front -> data;
        p = front;
        front = front->next;
        free(p);
    }
    return x;
}

void display(){
    struct Node *p = front;
    while(p){
        cout<<p -> data<<" ";
        p = p->next;
    }
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();
    cout<<dequeue();
}