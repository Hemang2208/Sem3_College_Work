
//! DECLARING A NODE
// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     //? using Structure tag
//     struct node {
//         int value;
//         struct node *next;
//     };

//     //? using typedef
//     typedef struct Node{
//         int value;
//         struct Node* next;
//     }Node;

//     Node *p,*q;
//     p=malloc(sizeof(Node));
//     q=malloc(sizeof(Node));

//     p->value=6;
//     p->next=q;

//     q->value=7;
//     q->next=NULL;

//     printf("%d %d",p->value,(*p).next->value);
// }


//! CREATING A LINKED_LIST USING CUSTOM CONSTRUCTOR
#include<stdio.h>
#include<stdlib.h>
typedef struct node{ // declaration of node
    int val;
    struct node *next;
}Node;

typedef struct{ 
    Node *head;
    Node *tail;
}Link_list;

//definition of the constructor
Link_list* List_constructor(){

    Link_list *chain=malloc(sizeof(Link_list));
    chain->head = NULL;
    chain->tail = NULL;
    printf("Enter a series of numbers : ");
    char line[1000];
    fgets(line, sizeof(line), stdin); // Read entire line
    
    char *ptr = line;
    int n,offset;
    
    // Parse numbers from the line
    while(sscanf(ptr, "%d %n", &n , &offset) == 1){

        //creating node first
        Node *new_node=malloc(sizeof(Node));
        new_node->val = n;
        new_node-> next = NULL;
        
        // checking and updating head & tail of the list
        if (chain->head == NULL){ // if list was empty
            chain->head=new_node;
            chain->tail=new_node;
        }
        else{
            chain->tail->next=new_node; // if list has some nodes , we need to update the next member of it
            chain->tail = new_node;
        }

        ptr+=offset;
    } 
    return chain;
}

//? display the list
void display(Link_list* l){
    Node *curr = l->head;
    while (curr!=NULL){
        printf("%d ",curr->val);
        curr=curr->next;
    }
    printf("\n");
}

// ! OPERATIONS : 


// ! Inserting a node
// ? At the Beginning
void add_beginning(Link_list*l , int x){
    Node *new_node=malloc(sizeof(Node));
    new_node->val = x;
    new_node->next = l->head;
    l->head=new_node;
}

// ? At the end
void add_end(Link_list *l , int x){
    Node *new_node=malloc(sizeof(Node));
    new_node->val=x;
    new_node->next=NULL;
    l->tail->next=new_node;
    l->tail=new_node;
}

// ? In the Middle
void add_middle(Link_list*l,int pos , int x){
    Node *new_node=malloc(sizeof(Node));
    Node *List_node = l->head;

    // finding the wanted_node
    if (pos == 0 || l->head==NULL){
        add_beginning(l,x);
        return;
    }
    for (int i=0 ; i<pos && List_node!=NULL ; i++){
        List_node=List_node->next;
    }
    if (List_node == NULL){
        add_end(l,x);
        return;
    }
    new_node->val=x;
    new_node->next=List_node->next;
    List_node->next=new_node;
}

// ! Searching for a node
void search(Link_list *l , int x){
    int count=0;
    Node *curr=l->head;
    while (curr!=NULL){
        curr=curr->next;
        count++;
        if (curr->val == x) break;
    }
    printf("%d is on Node no. %d\n",curr->val,count);
}

//! Deleting a node
void delete(Link_list* l , int pos){
    Node* List_node = l->head; 
    Node* List_node_prev=l->head;
    if (List_node==NULL || List_node->next==NULL){
        printf("Invalid position");
        return;
    }
    else if(pos == 0 && List_node!=NULL){
        l->head = List_node->next;
        free(List_node);
    }
    else {
        for (int i=0 ; i<pos && List_node!=NULL ; i++){
            List_node=List_node->next;
        }
        for (int i=0 ; i<pos-1 && List_node!=NULL ; i++){
            List_node_prev=List_node_prev->next;
        }
        List_node_prev->next = List_node->next ;

        if (List_node->next==NULL) l->tail = List_node_prev; 
        free(List_node); 
    }
}

int main(){
    Link_list *l = List_constructor();

    add_beginning(l,11);
    add_end(l,23);
    add_middle(l,4,45);

    display(l);
    
    // searching for a node
    int x;
    printf("Enter value to search and print: ");
    scanf("%d",&x);
    search(l,x);

    delete(l,0);display(l);

    delete(l,2);display(l);

    delete(l,2);display(l);
}