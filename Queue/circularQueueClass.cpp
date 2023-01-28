#include<iostream>
using namespace std;

class Queue{
    private:
        int capacity;
        int front;
        int rear;
        int *Q;
    public:
        Queue(int size);
        ~Queue();
        void enqueue(int x);
        int dequeue();
};

Queue :: Queue(int size){
    Q = new int[size];
    front = -1;
    rear = -1;
    capacity = size;
}

Queue :: ~Queue(){
    delete[] Q;
}

void Queue :: enqueue(int x){
    if((rear+1) % capacity == front){
        cout<<"Queue is full";
    }
    else{
        rear = (rear + 1) % capacity;
        Q[rear] = x;
    }
} 

int Queue :: dequeue(){
    int x;

    if(front == rear){
        cout<<"Queue is empty";
    }
    else{
        front = (front + 1) % capacity;
        x = Q[front];
    }
    return x;
}

int main(){
    Queue q(3);
    q.enqueue(10);
    q.enqueue(20);
    q.dequeue();
    q.dequeue();
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(20);
}
