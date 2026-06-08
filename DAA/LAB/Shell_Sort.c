#include <stdio.h>

// Shell Sort Function
void shellSort(int arr[], int n){
    int gap, i, j, temp;

    // Start with a large gap, then reduce it
    for (gap = n / 2; gap > 0; gap /= 2){

        // Perform insertion sort for this gap
        for (i = gap; i < n; i++){
            temp = arr[i];

            // Shift earlier gap-sorted elements up
            for (j = i; j >= gap && 
                arr[j - gap] > temp; j -= gap)
            {
                arr[j] = arr[j - gap];
            }

            arr[j] = temp;
        }
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
    int arr[] = {12, 34, 54, 2, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array:\n");
    printArray(arr, n);

    shellSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}