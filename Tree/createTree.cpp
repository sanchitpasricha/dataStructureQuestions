#include<iostream>
#include "q.cpp"
using namespace std;

struct Node * makeTree(struct Node *root){
    struct Node *p,*t;
    struct Queue q;
    int x;
    create(&q,100);
    cout<<"Enter a root value :: ";
    cin>>x;
    root = new struct Node;
    root -> data = x;
    root -> lchild = root -> rchild = NULL;
    enqueue(&q, root);
    while(!isEmpty(q)){
        p = dequeue(&q);
        cout<<"Enter the left child of "<<p -> data<<":: ";
        cin>>x;
        if(x != -1){
            t = new struct Node;
            t -> lchild = t -> rchild = NULL;
            t -> data = x;
            p -> lchild = t;
            enqueue(&q, t);
        }
        cout<<"Enter the right child of "<<p -> data<<":: ";
        cin>>x;
        if(x != -1){
            t = new struct Node;
            t -> data = x;
            t -> lchild = t -> rchild = NULL;
            p -> rchild = t;
            enqueue(&q, t);
        }
    }
    return root;
}