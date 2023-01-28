#include<iostream>
#include<stack>
using namespace std;

struct Node{
    int data;
    struct Node *next;
}*head=NULL;

void create(int arr[] , int size){
    struct Node *last;
    struct Node *t;
    
    head = new struct Node;
    head ->data = arr[0];
    head -> next = NULL;
    last = head;
    for(int i = 1;i < size; i++){
        t = new struct Node;
        t->data = arr[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}

bool isPalindrome(struct Node *head){
    stack<int> st;

    struct Node *p = head;
    struct Node *q = head;
    while(p != NULL){
        st.push(p->data);
        p = p->next;
    }

    while(q != NULL){
        if(q->data == st.top()){
            st.pop();
            q = q->next;
        }
        else{
            return false;
        }
    }
    return true;

}

int main(){
    int arr[] = {1};
    create(arr,3);
    cout<<isPalindrome(head);
}