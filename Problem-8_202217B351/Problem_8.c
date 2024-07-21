#include <stdio.h>

// Function to find the smallest element's position in the array from index i to n
int findSmallest(int arr[], int i, int n) {
    int small = arr[i];
    int pos = i;
    for (int j = i+1; j < n; j++) {
        if (small > arr[j]) {
            small = arr[j];
            pos = j;
        }
    }
    return pos;
}

// Function to perform selection sort
void selectionSort(int arr[], int n) {
    int pos, temp;
    for (int i = 0; i < n-1; i++) {
        pos = findSmallest(arr, i, n);
        // Swap the found smallest element with the element at index i
        temp = arr[i];
        arr[i] = arr[pos];
        arr[pos] = temp;
    }
}

// Function to print the array
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;

    // Input the size of the array
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];

    // Input the elements of the array
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Print the unsorted array
    printf("Unsorted array: ");
    printArray(arr, n);

    // Perform selection sort
    selectionSort(arr, n);

    // Print the sorted array
    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}
