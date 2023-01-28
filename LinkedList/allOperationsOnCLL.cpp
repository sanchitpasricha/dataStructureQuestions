#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node *next;
};

class CircularLinkedList{
    private:
        Node *first;
    public:
        CircularLinkedList(){
            first =NULL;
        }
        CircularLinkedList(int A[], int n);
        // ~CircularLinkedList();

        void Display();
        void insert(int index, int x);
        int length();
        // void Insert();
        // void Deleting();
};

CircularLinkedList :: CircularLinkedList(int A[], int n){
    Node *last,*t;

    first = new Node;
    first -> data = A[0];
    first -> next = first;
    last = first;

    for(int i=1 ; i<n ; i++){
        t = new Node;
        t -> data = A[i];
        t -> next = last -> next;
        last -> next = t;
        last = t;
    }
}

void CircularLinkedList :: Display(){
    Node *p = first;

    do{
        cout<< p->data <<" ";
        p = p->next;
    }
    while(p != first);
}

int CircularLinkedList :: length(){
    int count=0;
    Node *p = first;

    do{
        count++;
        p = p->next;
    }while(p!=first);
    return count;
}

void CircularLinkedList :: insert(int index, int x){
    Node *t;
    Node *p=first;

    if(index == 0 || index > length()){

        return;
    }

    if(index == 0){
        t = new Node;
        t -> data = x;
        if(first == NULL){
            first = t;
            first -> next = first;
        }
        else{
            while(p->next != first){
                p=p->next;
                p -> next = t;
                t -> next = first;
                first = t;
            }
        }
    }
    else{
        for(int i=1; index; i++){
            p = p->next;
            t = new Node;
            t -> data = x;
            t -> next = p -> next;
            p -> next = t;
        }
    }
}

int main(){
    int Arr[6] = {1,2,3,4,5,6};
    CircularLinkedList l(Arr, 6);
    l.insert(2, 10);
    l.Display();
}