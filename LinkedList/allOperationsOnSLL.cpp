#include<iostream>
using namespace std;

//structure to create a linked list

struct Node{
    int data;
    struct Node *next;
}*first = NULL, *second = NULL, *third = NULL;

// create a linked list of array

void create(int A[], int s){
    struct Node *t;
    struct Node *last;
    
    first = new struct Node;
    first -> data = A[0];
    first -> next = NULL;
    last = first;

    for(int i=1 ; i<s ; i++){
        t = new struct Node;
        t -> data = A[i];
        t -> next = NULL;
        last -> next = t;
        last = t;
    }   
}

//display a linked list

void display(struct Node *p){
    while(p){
        cout<< p->data <<" ";
        p = p -> next;
    }
}

//recursive display for Linked list

void recursiveDisplay(struct Node *p){
    if(p != NULL){
        cout<< p -> data <<" ";
        recursiveDisplay(p->next);
    }
}

//counting nodes of a linked list

int countingNodes(struct Node *p){
    int count=0;

    while(p){
        count++;
        p = p -> next;
    }   

    return count;

}

//sum of all nodes

int sumOfAllNodes(struct Node *p){
    int sum = 0;

    while(p){
        sum += p -> data;
        p = p -> next;
    }

    return sum;
}

//finding max element

int maxElement(struct Node *p){
    int max = INT_MIN;

    while(p){

        if(max < p -> data){
            max = p -> data;
        }

        p = p->next;
    }
    return max;
}

//searching in a linkedlist

int searchEle(struct Node *p, int key){
    while(p){
        if(p->data == key){
            return 1;
        }
        p = p->next;
    }
    return -1;
}

//creating LinkedList using inserting

void createUsingInsert(int val){
    struct Node *last;
    struct Node *t;

    t = new struct Node;
    t -> data = val;
    t -> next = NULL;

    if(second == NULL){
        last=second=t;
    }
    else{
        last -> next = t;
        last = t;
    }
}

//inserting in a linked list

void insertingInLL(struct Node *p, int index, int val){
    struct Node *q;

    if(!p){
        cout<<"Create a linked list first !";
    }
    else{
        struct Node *t;
        t = new struct Node;
        t -> data = val;
        t -> next = NULL;

        if(index == 0){
            p = t;
            p -> next = first;
            first = t;
        }
        else{
            for(int i=1; i<index; i++){
                p = p->next;
            }
            q = p->next;
            p -> next = t;
            t -> next = q;
            p = q;
        }
    }
}

//inserting in a sorted Linked List

void insertInSortedLL(struct Node *p, int val){
    struct Node *q;
    struct Node *t;

    t = new struct Node;
    t -> data = val;
    t -> next = NULL;

    if(first == NULL){
        first = t;
    }

    while(p && p->data < val){
            q = p;
            p = p -> next; 

            if(p == first){
            t -> next = first;
            first = t;
        }
        else{
            t->next = q->next;
            q->next = t;
        }           
    }
        
}

//deleting a node from Linked list

void deletingInLL(int val, struct Node *p){
    struct Node *q;

    if(p->data == val){
        q = p;
        p = p->next;
        delete(q);
    }

    while(p){
        if(p -> data != val){
            q = p;
            p = p->next;
        }
        else{
            q -> next = p -> next;
            q = p;
            p = p -> next;
            delete(q);
        }
    }
    
}

//checking if linked list is sorted or not

int checkSorted(struct Node *p){
    int x = INT_MIN;

    while(p){
        if(p->data < x){
            return -1;
        }
        x = p->data;
        p = p->next;
    }
    return 1;
}

//remove duplicates from linked list

void removeDupli(struct Node *p){

    struct Node *q = p -> next;

    while(q){

        // will move both pointers forward if elements are unique
        if(q->data != p->data){
            p = q;
            q = q->next;
        }

        //will only move second pointer until both pointers hold different values.
        else{
            p -> next = q -> next;
            delete(q);
            q = p->next;
        }
    }

}

//reversing a linked list

void reversingLL(struct Node *p){
    struct Node *q=NULL, *r=NULL;

    while(p){
        r=q;
        q=p;
        p = p->next;
        q -> next = r;
    }
    first = q;
}

//concatinating 2 linked list

void concatinatingLL(struct Node *p, struct Node *second){
    while(p->next != NULL){
        p = p->next;
    }
    p -> next = second;
}

//merging 2 sorted linked list

void mergeLL(struct Node *first, struct Node *second){
    struct Node *last;

    if(first -> data < second -> data){
        last = third = first;
        first = first -> next;
        third -> next = NULL;
    }
    else{
        last = third = second;
        second = second -> next;
        third -> next = NULL;
    }

    while(first && second){
        if(first -> data < second -> data){
            last -> next = first;
            last = first;
            first = first -> next;
            last -> next = NULL;
        }
        else{
            last -> next = second;
            last = second;
            second = second -> next;
            last -> next = NULL;
        }
    }

    if(first){
        last -> next = first;
    }
    if(second){
        last -> next = second;
    }
}

//checking loop in a linkedlist

bool chkLoop(struct Node *p){

    if(p == NULL){
        return false;
    }

    struct Node *q = p;

    while(q != NULL && q -> next != NULL){
        q = q -> next -> next;
        p = p -> next;

        if(p == q){
            return true;
        }
    }
    return false;

}

int main(){

    int Arr[11] = {1,2,3,4,4,4,5,5,6,12,22};
    create(Arr,11);
    // display(first);
    // recursiveDisplay(first);
    // countingNodes(first);
    // sumOfAllNodes(first);
    // maxElement(first);
    // searchEle(first, 12);
    // createUsingInsert(7);
    // createUsingInsert(9);
    // createUsingInsert(13);
    // display(second);
    // insertingInLL(first, 0, 15);
    // insertingInLL(first, 3, 22);
    // display(first);
    // insertInSortedLL(first, 13);
    // display(first);
    // deletingInLL(22, first);
    // display(first);
    // cout<< checkSorted(first);
    // removeDupli(first);
    // reversingLL(first);
    // display(first);
    // concatinatingLL(first, second);
    // display(first);
    // mergeLL(first,second);
    // display(third);
    cout<< chkLoop(first);

    return 0;

}