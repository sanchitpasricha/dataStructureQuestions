#include<iostream>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};

void create(struct Queue *q, int size){
    q -> size = size;
    q -> front = q -> rear = -1;
    q -> Q = new int[size];   
}

void enqueue(struct Queue *q, int x){
    if((q -> rear+1)% q -> size == q -> front){
        cout<<"Queue is full";
    }
    else{
        q -> rear = (q -> rear+1) % q -> size;
        q -> Q[q -> rear] = x;
    }
}

int dequeue(struct Queue *q){
    int x;

    if(q -> front == q -> rear){
        cout<<"Queue is empty";
    }
    else{
        q -> front = (q -> front + 1) % q -> size;
        x = q -> Q[q -> front];
    }

    return x;
}

int main(){
    struct Queue q;

    create(&q, 5);
    enqueue(&q, 5);
    enqueue(&q, 10);
    enqueue(&q, 15);
    enqueue(&q, 20);
    dequeue(&q);
    enqueue(&q, 25);
    dequeue(&q);
    enqueue(&q, 25);
}