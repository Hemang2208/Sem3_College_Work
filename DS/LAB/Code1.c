#include <stdio.h>

//! Multiplication of two matrices is OG
void Multiply()
{
    int rows1, cols1, rows2, cols2;
    printf("Enter rows and cols for A: ");
    scanf("%d%d", &rows1, &cols1);
    printf("Enter rows and cols for B: ");
    scanf("%d%d", &rows2, &cols2);
    int A[rows1][cols1], B[rows2][cols2], C[rows1][cols2];
    // Initialize C with 0
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            C[i][j] = 0;
        }
    }

    // input of A
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }
    printf("\n");
    // input of B
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    // Calculating C
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            for (int k = 0; k < cols1; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Printing A
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols1; j++)
        {
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // Printing B
    for (int i = 0; i < rows2; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    // Printing C
    for (int i = 0; i < rows1; i++)
    {
        for (int j = 0; j < cols2; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");
}

//!Addition of two matrices
void Add()
{
    int rows, cols;
    printf("Emter rows and cols : ");
    scanf("%d%d", &rows, &cols);
    int A[rows][cols] , B[rows][cols] , C[rows][cols];
    // input of A
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &A[i][j]);
        }
    }

    printf("\n");

    // input of B
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf("%d", &B[i][j]);
        }
    }

    // Calculating C
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < cols; j++){
            C[i][j] = A[i][j] + B[i][j];
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
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", B[i][j]);
        }
        printf("\n");
    }

    printf("\n");
    
    // Printing C
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }
    printf("\n");

}
int main(){
    Add();
}