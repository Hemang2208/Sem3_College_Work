#include <stdio.h>

int linearSearch(int arr[], int n, int key){
    if (n == 0)
        return -1;
    if (arr[n - 1] == key)
        return n - 1;
    return linearSearch(arr, n - 1, key);
}

int binarySearch(int arr[], int low, int high, int key){
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == key)
        return mid;
    else if (arr[mid] > key)
        return binarySearch(arr, low, mid - 1, key);
    else
        return binarySearch(arr, mid + 1, high, key);
}

int main(){
    int arr[] = {2, 5, 8, 12, 16, 23, 38};
    int n = sizeof(arr) / sizeof(arr[0]);

    int key;
    printf("Enter element to search: ");
    scanf("%d", &key);

    int linResult = linearSearch(arr, n, key);
    if (linResult != -1)
        printf("Linear Search: Element found at index %d\n", linResult);
    else
        printf("Linear Search: Element not found\n");

        
    int binResult = binarySearch(arr, 0, n - 1, key);
    if (binResult != -1)
        printf("Binary Search: Element found at index %d\n", binResult);
    else
        printf("Binary Search: Element not found\n");

    return 0;
}