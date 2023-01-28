#include<iostream>
#include "createTree.cpp"
#include "traversals.cpp"
#include "countNodes.cpp"


struct Node *root=NULL;

int main(){
    root = makeTree(root);
    LevelOrder(root);
    cout<<"Nodes :: "<<countNodes(root);
    return 0;
}