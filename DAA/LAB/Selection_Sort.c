#include <stdio.h>

// Selection Sort Function
void selectionSort(int arr[], int n){
    int i, j, min_idx;

    // Loop through all elements
    for (i = 0; i < n - 1; i++){
        min_idx = i;

        // Find the minimum element in unsorted part
        for (j = i + 1; j < n; j++){
            if (arr[j] < arr[min_idx])
            {
                min_idx = j;
            }
        }

        // Swap the found minimum element with first element
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

// Print Array
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// Main Function
int main()
{
    int arr[] = {64, 25, 12, 22, 11};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    selectionSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}