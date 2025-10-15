#include <stdio.h>
#include <stdlib.h>
#define max 5

typedef struct node{
    int val;
    struct node* prev;
}node;

typedef struct Stack{
    node* top;
    int count;
}Stack;

Stack stk={NULL,0}; // initialized an empty Stack named stk with top=NULL
 
void push(int val){
    if (stk.count==max) printf("overflow \n");
    else{
        node* newnode=malloc(sizeof(node));        // creating a new node
        newnode->val=val;                         // assigning value to new node
        newnode->prev=stk.top;                   // linking new node to it's previous node
        stk.top=newnode;                        // updating the top 
        stk.count++; 
    }                       
}

void pop(){
    if (stk.top==NULL) printf("underflow \n");
    else
    stk.top = stk.top->prev;
    stk.count--;
}

void peek(){
    if (stk.top==NULL) printf("Stack empty \n");
    else printf("%d is the current top\n",stk.top->val);
}

int main(){

    for (int i=0 ; i<5 ; i++){
        push(i); 
        printf("No. of elements are %d\n",stk.count);
    }

    push(6); // overflow

    for (int i=0 ; i<5 ; i++){
        pop(); 
        printf("No. of elements are %d\n",stk.count);
    }
    
    pop();
     
    peek();

}