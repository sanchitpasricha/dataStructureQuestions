#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*first=NULL;

void create(int arr[] , int size){
    struct Node *last;
    struct Node *t;
    
    first = new struct Node;
    first ->data = arr[0];
    first -> next = NULL;
    last = first;
    for(int i = 1;i < size; i++){
        t = new struct Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

void deleteMiddle(struct Node *head){
    struct Node *prev = NULL;
    struct Node *slow = head;
    struct Node *fast = head;

    // if(head == NULL || head -> next != NULL){
    //     return NULL;
    // }

    while(fast != NULL && fast->next != NULL){
        prev = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    prev->next = slow->next;
    delete slow;
    
}

void display(struct Node *p){
    while(p != NULL){
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(){
    int arr[] = {1,2,3,4,5,6,7};
    int size = sizeof(arr) / sizeof(arr[0]);
    create(arr,size);
    deleteMiddle(first);
    display(first);
}