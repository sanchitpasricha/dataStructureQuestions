#include<iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*HEAD=NULL;

void create(int arr[], int n){
    struct Node *t,*last;
    
    HEAD = new struct Node;
    HEAD -> data = arr[0];
    HEAD -> next = HEAD;
    last = HEAD;

    for(int i=1 ;i < n; i++){
        t = new struct Node;
        t -> data = arr[i];
        t -> next = HEAD;
        last -> next = t;
        last = t;
    }
}

void display(struct Node *p){
    do{
        cout << p->data <<" ";
        p = p->next;
    }while(p != HEAD);
}

int main(){
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    create(arr,10);
    display(HEAD);
    return 0;
}