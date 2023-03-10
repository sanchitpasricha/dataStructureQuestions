#include<iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
};

struct Queue{
    int size;
    int front;
    int rear;
    struct Node **Q;
};

void create(struct Queue *q, int size){
    q -> size = size;
    q -> front = q -> rear = 0;
    q -> Q = new struct Node*;
}

void enqueue(struct Queue *q, struct Node *x){
    if((q -> rear + 1) % q -> size == q -> front){
        cout<<"Queue is full";
    }
    else{
        q -> rear = (q -> rear + 1) % q -> size;
        q -> Q[q -> rear] = x;
    }
}

struct Node * dequeue(struct Queue *q){

    struct Node *x;

    if(q -> rear == q -> front){
        cout<<"Queue is empty";
    }
    else{
        q -> front = (q -> front + 1) % q -> size;
        x = q -> Q[q -> front];
    }
    return x;
}

int isEmpty(struct Queue q){
    return q.front == q.rear;
}