#include <stdio.h>

#define MAX 20

int w[MAX], x[MAX]; // weights and solution vector
int n, target;

// Function to print subset
void printSubset()
{
    printf("{ ");
    for (int i = 0; i < n; i++)
    {
        if (x[i] == 1)
            printf("%d ", w[i]);
    }
    printf("}\n");
}

// Sum of Subsets using Backtracking
void sumOfSubsets(int s, int k, int r)
{
    x[k] = 1;

    // If subset sum equals target → print
    if (s + w[k] == target)
    {
        printSubset();
    }
    // If adding next element is valid
    else if (s + w[k] + w[k + 1] <= target)
    {
        sumOfSubsets(s + w[k], k + 1, r - w[k]);
    }

    // Exclude current element
    if ((s + r - w[k] >= target) && (s + w[k + 1] <= target))
    {
        x[k] = 0;
        sumOfSubsets(s, k + 1, r - w[k]);
    }
}

// Main Function
int main()
{
    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements (sorted): ");
    for (int i = 0; i < n; i++)
        scanf("%d", &w[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);

    // Calculate total sum
    int total = 0;
    for (int i = 0; i < n; i++)
        total += w[i];

    printf("Subsets with sum %d:\n", target);
    sumOfSubsets(0, 0, total);

    return 0;
}