#include<stdio.h>
#include<stdbool.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

int main(){
    int arr[5]={1,45,23,5,90};
    int n=5;
    bool swapped=false;

    // sorting 
    int i=0,j=1;
    for(int i=0;i<n-1;i++){
        for(int j=0 ;j<n-i-1;j++){
            if(arr[j]>arr[j+1])
                swap(&arr[j],&arr[j+1]);
                swapped=true;
        }
        if (swapped==false) break;
    }

    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}