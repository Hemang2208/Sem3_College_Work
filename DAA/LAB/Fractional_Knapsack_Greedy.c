#include <stdio.h>

// Structure for items
struct Item
{
    int profit, weight;
    float ratio;
};

// Function to sort items by ratio (descending)
void sortItems(struct Item arr[], int n)
{
    struct Item temp;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (arr[j].ratio < arr[j + 1].ratio)
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Fractional Knapsack Function
float knapsack(struct Item arr[], int n, int capacity)
{
    float totalProfit = 0.0;

    for (int i = 0; i < n; i++)
    {
        // If item can be fully taken
        if (arr[i].weight <= capacity)
        {
            capacity -= arr[i].weight;
            totalProfit += arr[i].profit;
        }
        // Take fraction of item
        else
        {
            totalProfit += arr[i].ratio * capacity;
            break;
        }
    }
    return totalProfit;
}

// Main Function
int main()
{
    int n, capacity;

    printf("Enter number of items: ");
    scanf("%d", &n);

    struct Item arr[n];

    printf("Enter profits and weights:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &arr[i].profit, &arr[i].weight);
        arr[i].ratio = (float)arr[i].profit / arr[i].weight;
    }

    printf("Enter knapsack capacity: ");
    scanf("%d", &capacity);

    // Sort items by profit/weight ratio
    sortItems(arr, n);

    float maxProfit = knapsack(arr, n, capacity);

    printf("Maximum profit = %.2f\n", maxProfit);

    return 0;
}