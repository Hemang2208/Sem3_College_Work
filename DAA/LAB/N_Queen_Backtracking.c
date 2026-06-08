#include <stdio.h>

#define N 4

int board[N][N];

// Function to print solution
void printSolution()
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%d ", board[i][j]);
        printf("\n");
    }
    printf("\n");
}

// Check if it's safe to place queen
int isSafe(int row, int col)
{
    int i, j;

    // Check left side of row
    for (i = 0; i < col; i++)
        if (board[row][i])
            return 0;

    // Check upper diagonal
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return 0;

    // Check lower diagonal
    for (i = row, j = col; i < N && j >= 0; i++, j--)
        if (board[i][j])
            return 0;

    return 1;
}

// Backtracking function
int solveNQueen(int col)
{
    // If all queens placed
    if (col == N)
    {
        printSolution();
        return 1;
    }

    int res = 0;

    // Try placing queen in all rows of this column
    for (int i = 0; i < N; i++)
    {
        if (isSafe(i, col))
        {
            board[i][col] = 1;

            // Recur for next column
            res = solveNQueen(col + 1) || res;

            // Backtrack
            board[i][col] = 0;
        }
    }

    return res;
}

// Main Function
int main()
{
    solveNQueen(0);
    return 0;
}