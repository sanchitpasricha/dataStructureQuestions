#include<iostream>
using namespace std;

struct Node{
    struct Node *lchild;
    int data;
    struct Node *rchild;
}*root=NULL;

void insertBST(int key){
    struct Node *p = root;
    struct Node *t;
    struct Node *r;

    if(root == nullptr){
        t = new struct Node;
        t -> data = key;
        t -> lchild = t -> rchild = NULL;
        root = t;
        return;
    }

    while(p != nullptr){
        r = p;
        if(key < p -> data){
            p = p -> lchild;
        }
        else if(key > p -> data){
            p = p -> rchild;
        }
        else{
            return;
        }
    }

    t = new struct Node;
    t -> data = key;
    t -> lchild = t -> rchild = nullptr;
    if(key < r -> data){
        r -> lchild = t;
    }
    else{
        r -> rchild = t;
    }
}

void Preorder(struct Node *p){
    if(p){
        cout<<p -> data<<" ";
        Preorder(p -> lchild);
        Preorder(p -> rchild);
    }
}

struct Node * Rsearch(struct Node *t, int key){
    if(t == NULL){
        return NULL;
    }
    if(t -> data == key){
        return t;
    }
    else if(t -> data < key){
        return Rsearch(t -> lchild,key);
    }
    else{
        return Rsearch(t -> rchild,key);
    }
}

struct Node * Insucc(struct Node *p){
    while(p && p -> lchild != NULL){
        p = p -> lchild;
    }
    return p;
}

struct Node * Inpre(struct Node *p){
    while(p && p -> rchild != NULL){
        p = p -> rchild;
    }
    return p;
}

int Height(struct Node *p){
    int x,y;
    while(p){
        x = Height(p -> lchild);
        y = Height(p -> rchild);
        if(x > y){
            return x + 1;
        }
        else{
            return y + 1;
        }
    }
    return 0;   
}

struct Node * deleteNode(struct Node *p, int key){

    struct Node *q;

    if(p == NULL){
        return NULL;
    }
    if(p -> lchild == NULL && p -> rchild == NULL){
        if(p == root){
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if(key < p -> data){
        p -> lchild = deleteNode(p -> lchild, key);
    }
    else if(key > p -> data){
        p -> rchild = deleteNode(p -> rchild, key);
    }
    else{
        if(Height(p -> lchild) > Height(p -> rchild)){
            q = Inpre(p -> rchild); 
            p -> data = q -> data;
            p -> lchild = deleteNode(p -> lchild, q -> data);
        }
        else{
           q = Insucc(p -> lchild); 
           p -> data = q -> data;
           p -> rchild = deleteNode(p -> rchild, q -> data);
        }
    }
    return p;
}

int main(){
    insertBST(20);
    insertBST(5);
    insertBST(12);
    insertBST(16);
    insertBST(27);
    insertBST(2);
    deleteNode(root, 12);
    Preorder(root);
    // cout<<endl<<Rsearch(root,27);
}
