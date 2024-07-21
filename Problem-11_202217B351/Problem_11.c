#include <stdio.h>

// Function to perform linear search
int linearSearch(int arr[], int n, int target) {
    int i;
    // Iterate through each element in the array
    for (i = 0; i < n; i++) {
        // Check if the current element matches the target
        if (arr[i] == target) {
            return i;  // Element found at index i
        }
    }
    return -1;  // Element not found
}

int main() {
    int arr[] = {10, 2, 8, 5, 17};  // Array to search
    int n = sizeof(arr) / sizeof(arr[0]);  // Number of elements in the array
    int target = 8;  // Element to search for

    // Call the linearSearch function
    int result = linearSearch(arr, n, target);

    // Output the result
    if (result == -1) {
        printf("Element not found in the array.\n");
    } else {
        printf("Element found at index: %d\n", result);
    }

    return 0;
}
