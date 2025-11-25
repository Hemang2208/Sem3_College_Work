#include<stdio.h>
#include<stdlib.h>
#define max 5
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
        newnode->next=stk.top;
        stk.top=newnode;
        stk.count++;
    }
}

void pop(){
    if (stk.count == 0) printf("Underflow\n");
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
        printf("No. of elements are %d\n",stk.count);
    }

    push(6); // overflow

    peek();

    for (int i=0 ; i<5 ; i++){
        pop(); 
        printf("No. of elements are %d\n",stk.count);
    }
    
    pop();
     
    peek();
}