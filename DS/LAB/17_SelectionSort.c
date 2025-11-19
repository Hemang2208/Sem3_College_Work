//? find the smallest element and keep placing it in the right place 
//? basically mirror of bubble sort 

#include<stdio.h>

void swap(int* x, int* y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

void selectionSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
          int min_indx=i;
          for(int j=i+1; j<n ;j++){    // finding the actual index containing min element
            if(arr[j]<arr[min_indx]){
                min_indx=j;
            }
          swap(&arr[min_indx],&arr[i]);
          }
    }
  
}

int main(){
    int arr[10]={10,9,8,7,6,5,4,3,2,1};
   selectionSort(arr,10);

    for(int i=0;i<10;i++){
        printf("%d ",arr[i]);
    }
}