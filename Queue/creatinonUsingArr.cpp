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
    q -> Q = new int(size);
}

void enqueue(struct Queue *q, int x){
    if(q -> rear == q -> size-1){
        cout<<"Queue is full";
    }
    else{
        q -> rear++;
        q -> Q[q -> rear] = x;
    }
}

int dequeue(struct Queue *q){
    int x;

    if(q -> front == q -> rear){
        cout<<"Queue is empty";
    }
    else{
        q -> front++;
        x = q -> Q[q -> front];
    }

    return x;
}

void display(struct Queue q){

}

int main(){
    struct Queue q;
    create(&q, 5);
    enqueue(&q ,1);
    enqueue(&q, 2);
    enqueue(&q, 3);

    
    cout<<"Poped element "<<dequeue(&q)<<endl;
    cout<<"Poped element "<<dequeue(&q)<<endl;
}