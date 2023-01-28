#include<iostream>
using namespace std;

struct Node{
    char data;
    struct Node *next;
}*top=NULL;

void push(char x){
    struct Node *t;
    t = new struct Node;

    if(t == NULL){
        cout<<"Stack overflow";
    }
    else{
        t -> data = x;
        t -> next = top;
        top = t;
    }
} 

void pop(){
    struct Node *p;
    char x;

    if(top == NULL){
        cout<<"Stack is empty";
    }
    else{
        p = top;
        top = top -> next;
        x = p -> data;
        free(p);
    }
}

int isBalanced(char *exp){
    
    for(int i=0;exp[i] != '\0';i++){
        if(exp[i] == '('){
            push(exp[i]);
        }
        else if(exp[i] == ')'){
            if(top == NULL){
                return 0;
            }
            pop();
        }
    }
    if(top == NULL){
        return 1;
    }
    else{
        return 0;
    }
}

int main(){
    char *exp = "((a+b)*(c-d))";
    cout<<isBalanced(exp);
}

