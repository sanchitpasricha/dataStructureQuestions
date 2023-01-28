#include<iostream>

int countNodes(struct Node *p){
    int x,y;
    if(p){
        x = countNodes(p -> lchild);
        y = countNodes(p -> rchild);
        return x + y + 1;
    }
    return 0;
}