#include<stdio.h>
#include<stdlib.h>
#define max 10
typedef struct node{
    int val;
    struct node* next;
}node;

typedef struct Stack{
    node* top;
    int count;
}Stack;

Stack stk = {NULL,0};

void push(int x){
    node* newnode = malloc(sizeof(node));
    newnode->val=x;
    newnode->next=NULL;
    if (stk.count==max) printf("Overflow\n");
    else{
        newnode->next=stk.top->next;
        stk.top=newnode;
        stk.count++;
    }
}

void pop(){
    if (stk.count == 0) printf("Overflow\n");
    else {
        stk.top = stk.top->next;
        stk.count--;
    }
}

void peek(){
    if (stk.top == NULL) printf("Stack empty");
    else printf("%d \n",stk.top->val);
    printf("\n");

}

int main(){
    for (int i=0 ; i<5 ; i++){
        push(i);
    }

    pop();
    pop();

    peek();

    for (int i=1 ; i<=stk.count ; i++ )
        printf("%d ",stk.top->val);
}