#include<stdio.h>
#include<stdlib.h>

typedef struct index{
    int val;
    int t;
}index;

index *makeindex(int arr[], int n , int step){
    int k = n/step;
    index *arr1 = (index*)malloc(k * sizeof(index)); // i have a dynamic array of type index of size k 
    int i=0,j=0;
    while (i < n && j < k){
        arr1[j].val=arr[i];
        arr1[j].t=i;
        j++;
        i+=step;
    }  
    return arr1; 
}

int search(int arr[],int n, index* indexarray, int step, int x){
    int findex=0;
    for(int i=0 ; i<(int)(n/step) ; i++){
        if (x>=indexarray[i].val) findex=indexarray[i].t;
        else break;
    }
    for (int i=findex; i<findex+step ; i++){
        if (x==arr[i]) return i;
    }
    return -1;
}

int main(){
    int n=20;
    int arr[20];
    printf("Enter 20 numbers : ");
    for (int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }

    int step;
    printf("Enter step size : ");
    scanf("%d",&step);

    index *indexarray=makeindex(arr,n,step);

    printf("\n");

    for (int i=0 ; i<(n/step) ; i++){
        printf("%d %d\n",indexarray[i].t,indexarray[i].val);
    }
    
    int x;
    printf("Enter value to search : ");
    scanf("%d",&x);
    printf("%d is at the index %d\n",x,search(arr,n,indexarray,step,x));

}