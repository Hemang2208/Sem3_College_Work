#include<stdio.h>

int search(int arr[], int n, int x){
    for (int i=0;i<n;i++){
        if (arr[i]==x)
            return i;
    }
    return -1;
}

int main(){
    int arr[5]={1,2,3,4,5} , x , n=5;
    printf("Enter value to search : ");
    scanf("%d",&x);
    printf("%d is at index : %d\n",x,search(arr,n,x));

}