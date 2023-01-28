#include<iostream>
#include<stack>
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
        LinkedList(int arr[], int size);
        ~LinkedList();

        void Display();
        void DeleteMiddle();
        bool isPalindrome();
        void reverseLinkedList();
        // void Insert();
        // void Length();
        // void Delete();
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
        first = first -> next;
        delete p;
        p = first;
    }
}

void LinkedList :: DeleteMiddle(){
   Node *prev=NULL, *slow=first, *fast=first;

   while(fast != NULL && fast->next != NULL){
    prev = slow;
    slow = slow->next;
    fast = fast -> next -> next;
   }
   prev -> next = slow -> next;
   delete slow;
}

bool LinkedList :: isPalindrome(){
    Node *p=first, *q=first;
    stack<int> st;

    while(p != NULL){
        st.push(p->data);
        p = p->next;
    }

    while(q != NULL){
        if(q -> data == st.top()){
            st.pop();
            q = q->next;
        }else{
            return false;
        }
    }
    return true;
}

void LinkedList :: reverseLinkedList(){
    Node *p=first,*q=first;
    stack<int> st;

    while(p){
        st.push(p->data);
        p = p->next;
    }

    while(q){
        q -> data = st.top();
        q = q -> next;
        st.pop();
    }

}

void LinkedList :: Display(){
    Node *p = first;
    while(p){
        cout<<p->data<<" ";
        p = p->next;
    }
}

int main(){

    int arr[] = {1,2,3,4,5};
    int arr2[] = {6,7,8,9,10};
    LinkedList l1(arr, 5);
    LinkedList l2(arr2, 5);
    // l1.DeleteMiddle();
    // cout<<l1.isPalindrome();
    l1.reverseLinkedList();
    l1.Display();
    return 0;
}