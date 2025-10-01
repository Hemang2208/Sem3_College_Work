#include <stdio.h>
int b[100];
// using this to initialize an array
void insertback(int val, int* lower_bound , int* upper_bound){
    if (*lower_bound==-1 && *upper_bound==-1){
        (*lower_bound) +=1;
        (*upper_bound) +=1;
        b[*upper_bound]=val;
    }
    else{
        *upper_bound+=1;
        b[*upper_bound]=val;
    }
}



// deleting from the back
void deleteback(int* upper_bound){
    if (*upper_bound==-1) printf("nothing to delete");
    else *upper_bound-=1;
}

//deleting from the front or from the middle 
// btw this can work for deleting from the back too if you give position pos=upper_bound;
//! here the pos is the index 
void delete(int pos , int* upper_bound){

    int i = pos; 
    while (i<=(*upper_bound)){
        b[i]=b[i+1];
        i++;
    }
    *upper_bound-=1;
}

int main(){

    // initiallizing an array
    int lower_bound=-1 , upper_bound=-1; 
    for (int i=0 ;i<5 ; i++){
        insertback(i,&lower_bound,&upper_bound);
    } 
    
    // deleting from back
    deleteback(&upper_bound); // b={0,1,2,3}
    
    // printing the array 
    for (int i=lower_bound ; i<=upper_bound ; i++){
        printf("%d ",b[i]);
    }
    printf("\n");


    //deleting from the middle
    delete(1,&upper_bound); 
    // b={0,2,3}

    // printing the array 
    for (int i=lower_bound ; i<=upper_bound ; i++){
        printf("%d ",b[i]);
    }
    printf("\n");
}   