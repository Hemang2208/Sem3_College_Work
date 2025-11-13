#include<stdio.h>

int search(int arr[],int lb,int ub, int x){
    int i=(lb+ub)/2;
    if (lb>ub) return -1;
    if (arr[i]== x){
        return i;
    }
    else if(x>arr[i]){
        lb=i+1;
        return search(arr,lb,ub,x);
    }
    else {
        ub=i-1;
        return search(arr,lb,ub,x);
    }
}

int main(){
    int arr[15]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15};
    int x;
    printf("Enter value to find : ");
    scanf("%d",&x);
    printf("Found at index %d\n",search(arr,0,14,x));
}