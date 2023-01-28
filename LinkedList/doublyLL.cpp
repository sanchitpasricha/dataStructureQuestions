#include<iostream>
using namespace std;

struct Node{
    struct Node *prev;
    int val;
    struct Node *next;
}*first=NULL;

void create(int A[], int s){
    struct Node *t,*last;

    first = new struct Node;
    first->val = A[0];
    first->prev=first->next=NULL;
    last = first;

    for(int i=1;i<s;i++){
        t = new struct Node;
        t->val = A[i];
        t->next = NULL;
        t->prev = last;
        last->next = t;
        last = t;
    }
}

void display(struct Node *p){
    while(p){
        cout<<p->val<<" ";
        p = p->next;
    }
}

int main(){
    int arr[5] = {1,2,3,4,5};
    create(arr,5);
    display(first);
    return 0;
}