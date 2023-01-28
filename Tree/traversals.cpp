#include<iostream>

void Preorder(struct Node *p){
    if(p){
        cout<<p -> data<<" ";
        Preorder(p -> lchild);
        Preorder(p -> rchild);
    }
}

void Inorder(struct Node *p){
    if(p){
        Inorder(p -> lchild);
        cout<<p -> data<<" ";
        Inorder(p -> rchild);
    }
}

void Postorder(struct Node *p){
    if(p){
        Postorder(p -> lchild);
        Postorder(p -> rchild);
        cout<<p -> data<<" ";
    }
}

void LevelOrder(struct Node *p){
    struct Queue q;
    create(&q,100);
    cout<<p -> data<<" ";
    enqueue(&q, p);
    while(!isEmpty(q)){
        p = dequeue(&q);
        if(p -> lchild){
            cout<<p -> lchild -> data<<" ";
            enqueue(&q,p -> lchild);
        }
        if(p -> rchild){
            cout<<p -> rchild -> data<<" ";
            enqueue(&q,p -> rchild);
        }
    }
}