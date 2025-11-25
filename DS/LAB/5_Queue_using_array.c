#include<stdio.h>
# define max 5

int Queue[100];
int front=-1,rear = -1;


void enqueue (int x){
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

void dequeue() {
    if (front==-1 || front>rear) printf("Underflow\n");
    else{
        printf("dequeued  %d\n",Queue[front]);
        if (front==rear) front=rear=-1; // resets the queue if the very last element is dequeueped 
        else front++;
    }
}

void peek() {
    if (front==-1 || front>rear) printf("Queue empty\n");
    else  printf("Curent front is %d\n",Queue[front]);
}

int main(){
    for (int i=0 ; i<5 ; i++){   // enqueueing elements
        enqueue(i+1);
    }
    enqueue(6);  // testing edge case for overflow 

    peek();

    for (int i=0 ; i<5 ; i++){  // checking dequeue()
       dequeue();
       peek();
    }

    dequeue(); // testing edge case for underflow 

    peek();

}