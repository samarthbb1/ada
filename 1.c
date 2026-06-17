#include <stdio.h>

int binarySearch(int arr[], int n, int key) {
    int low = 0, high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Prevents potential overflow

        if (arr[mid] == key)
            return mid; // Key found
        
        if (arr[mid] < key)
            low = mid + 1; // Narrow to right half
        else
            high = mid - 1; // Narrow to left half
    }
    return -1; // Key not found
}

int main() {
    int n, key, result;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d sorted integers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Enter the key to search: ");
    scanf("%d", &key);

    result = binarySearch(arr, n, key);

    if (result != -1)
        printf("Element found at index %d\n", result);
    else
        printf("Element not found.\n");

    return 0;
}

