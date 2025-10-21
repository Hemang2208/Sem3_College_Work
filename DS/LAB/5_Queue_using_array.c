#include<stdio.h>
# define max 5

int Queue[100];
int front=-1,rear = -1;


void push (int x){
    if (rear==max-1) printf("Overflow\n");
    else if(front==-1 && rear==-1){
        front++;
        rear++;
        Queue[rear] = x;
    }
    else{
        rear++;
        Queue[rear] = x;
    }
}

void pop() {
    if (front==-1 || front>rear) printf("Underflow\n");
    else{
        printf("Popped  %d\n",Queue[front]);
        if (front==rear) front=rear=-1; // resets the queue if the very last element is popped 
        else front++;
    }
}

void peek() {
    if (front==-1 || front>rear) printf("Queue empty\n");
    else  printf("Curent front is %d\n",Queue[front]);
}

int main(){
    for (int i=0 ; i<5 ; i++){   // pushing elements
        push(i+1);
    }
    push(6);  // testing edge case for overflow 

    peek();

    for (int i=0 ; i<5 ; i++){  // checking pop()
       pop();
       peek();
    }

    pop(); // testing edge case for underflow 

    peek();

}