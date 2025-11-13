#include<stdio.h>
int arr[5];
int* makearray(){
    for (int i=0; i<5;i++){
        arr[i]=i;
    }
    return arr;
}

int main(){
    int *arr1 = makearray();
    for (int i=0; i<5;i++){
        arr1[i]=i;
    }

}