#include <stdio.h>
int main(){


    int a[100]={11,22,33,44,55};

    int lower_bound=0 , upper_bound=4;

    for (int i=lower_bound ; i<upper_bound ; i++){ // set i=lower_bound , updating i until i<=upper_bound
        printf("%d ",a[i]);
    }



    printf("\n");
}