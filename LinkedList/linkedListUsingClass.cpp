#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    private:
        Node *first;

    public:
        LinkedList(){
            first = NULL;
        }
        LinkedList(int arr[], int n);
        ~LinkedList();

        void Display();
        void Insert(int index, int x);
        void Delete(int index);
        int Length();
};

LinkedList :: LinkedList(int arr[], int n){
    Node *last,*t;

    first = new Node;
    first -> data = arr[0];
    first -> next = NULL;
    last = first;

    for(int i=1;i<n;i++){
        t = new Node;
        t -> data = arr[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }
}

LinkedList :: ~LinkedList(){
    Node *p = first;
    while(first){
        first = first->next;
        delete p;
        p = first;
    }
}

void LinkedList :: Display(){
    Node *p = first;
    while(p){
        cout<< p->data <<" ";
        p = p -> next;
    }
    cout<<endl;
}

int main(){
    int A[5] = {1,2,3,4,5};
    int B[10] = {1,2,3,4,5,6,7,8,9,10};
    LinkedList l(A,5);
    LinkedList l2(B,10);

    l.Display();
    l2.Display();
}