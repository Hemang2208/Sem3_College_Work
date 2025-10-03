#include <stdio.h>
#define max 100

//! DECLARATION 
typedef struct node{
    int val;
    int next;
}node;

node list[max];
int head=-1; // to symbolize empty list
int freeindex=0;



//! OPERATIONS

//? inserting at the back 
void insertback(int val){
    list[freeindex].val = val;
    list[freeindex].next=-1;
    if (head==-1){
        head=freeindex;
    }
    else{
        // finding last node
        int curr = head;
        while(list[curr].next!=-1){
            curr=list[curr].next;
        }

        list[curr].next=freeindex; // linking the last node to the new node
    }
    freeindex++;
}

//? inserting at front or middle 
//! here pos is the index at which we need to insert
void insert(int pos , int val){
    if (pos == 0){ // inserts at beginning
        list[freeindex].val=val;
        list[freeindex].next=pos;
        head=freeindex;
    }
    else{ // inserts at any given position(index)
        int curr = head , curr1=head;
        int count=0,prev=-1;
        while(curr!=-1 && count < pos){
            prev=curr;
            curr = list[curr].next;
            count++;
        }
        list[freeindex].val=val;
        list[freeindex].next=curr;
        list[prev].next=freeindex;

    }

    freeindex++;
}

//? Deleting a node
void delete(int pos){
    
}

//? searching for a node
int search (int x){
    int current=head;
    int count=0;
    while(current != -1){

        if (list[current].val == x) return count;

        else {
            current=list[current].next;
            count++;
        }
        
    }
}

//? display the list
void display(){
    int current=head;
    while(current != -1){
        printf("%d ",list[current].val);
        current=list[current].next;
    }
    printf("\n");
}

int main(){

    // inserting 5 elements
    int i=0;
    while (i<5){
        insertback(i);
        i++;
    }

    //inserting in middle
    insert(1,78);
    display();

    insertback(89);
    display();

    insert(2,56);
    display();
 
    
    // searching for a node
    printf("Node no. is %d ",search(89));

}




