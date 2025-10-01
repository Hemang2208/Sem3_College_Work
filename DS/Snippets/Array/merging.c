#include<stdio.h>

void merge(int a[] , int s1, int b[] , int s2 , int c[]){

    for(int i=0 ; i<s1 ; i++){
        c[i]=a[i];
    }

    for(int i=0 ; i<s1 ; i++){
        c[i+s1]=b[i];
    }
} 

int main(){
    int a[4]={1,2,3,4} , b[4]={5,6,7,8};
    int s1=(sizeof(a)/sizeof(a[0])) , s2 =(sizeof(b)/sizeof(b[0]));
    int c[s1+s2];
    merge(a,s1,b,s2,c);

    for (int i=0 ; i<(sizeof(c)/sizeof(c[0])) ; i++ ){
        printf("%d ",c[i]);
    }
}