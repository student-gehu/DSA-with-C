// what do you mean by a dynamic array? write a c function to create a dynamic array to store n element and then remove duplicate elements in that array
#include <stdio.h>
#include <stdlib.h>

void createDynamicArrayAndRemoveDuplicates(int n) {
    // Step 1: Create a dynamic array
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }

    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    int *uniqueArr = (int *)malloc(n * sizeof(int)); // Allocate maximum possible size
    if (uniqueArr == NULL) {
        printf("Memory allocation for unique array failed!\n");
        free(arr);
        return;
    }

    int uniqueCount = 0; // Counter for unique elements

    for (int i = 0; i < n; i++) {
        int isDuplicate = 0; // Flag to check if the element is a duplicate
        for (int j = 0; j < uniqueCount; j++) {
            if (arr[i] == uniqueArr[j]) {
                isDuplicate = 1; // Found a duplicate
                break;
            }
        }
        // If not a duplicate, add it to the unique array
        if (!isDuplicate) {
            uniqueArr[uniqueCount++] = arr[i];
        }
    }

    printf("Array after removing duplicates:\n");
    for (int i = 0; i < uniqueCount; i++) {
        printf("%d ", uniqueArr[i]);
    }
    printf("\n");

    // Free the allocated memory
    free(arr);
    free(uniqueArr);
}

int main() {
    int n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    createDynamicArrayAndRemoveDuplicates(n);
    return 0;
}
