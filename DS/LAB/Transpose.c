#include<stdio.h>
void Transpose(){
    int rows , cols ;
    printf("Enter rows and cols : ");
    scanf("%d%d",&rows,&cols);

    int A[rows][cols] , B[cols][rows] ;

    // input of A
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    //Calculating B
    for (int i = 0; i <cols; i++){
        for (int j = 0; j < rows ; j++){
            B[i][j]=A[j][i];
        }
    }

        // Printing A
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }

    printf("\n");

    // Printing B
    for (int i = 0; i < cols; i++)
    {
        for (int j = 0; j < rows; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    
}
int main(){
    Transpose();
}