#include <stdio.h>
int a[100];

void insertback(int val, int* upper_bound , int* lower_bound){
    if (*lower_bound==-1 && *upper_bound==-1){
        (*lower_bound) +=1;
        (*upper_bound) +=1;
        a[*upper_bound]=val;
    }
    else{
        *upper_bound+=1;
        a[*upper_bound]=val;
    }
}

int main(){
    // inserting at the back
    int lower_bound=-1 , upper_bound=-1; 
    for (int i=0 ;i<5 ; i++){
    insertback(i,&upper_bound,&lower_bound);
    }

    //inserting in the middle


    // printing the array
    printf("%d %d\n",lower_bound,upper_bound);
    for (int i=lower_bound ; i<=upper_bound ; i++){
        printf("%d ",a[i]);
    }

}   