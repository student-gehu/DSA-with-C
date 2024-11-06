// .Assume that vou have a single Hinked list. Write a C function to count the nodes having
// information multiple of 3.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a linked list node
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed!\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to count nodes with data that are multiples of 3
int countMultiplesOfThree(struct Node* head) {
    int count = 0; // Initialize count to 0
    struct Node* current = head; // Start from the head of the list

    // Traverse the linked list
    while (current != NULL) {
        if (current->data % 3 == 0) { // Check if the data is a multiple of 3
            count++; // Increment count
        }
        current = current->next; // Move to the next node
    }

    return count; // Return the final count
}

// Main function to demonstrate the functionality
int main() {
    // Create a linked list: 10 -> 3 -> 5 -> 9 -> 12 -> 15
    struct Node* head = createNode(10);
    head->next = createNode(3);
    head->next->next = createNode(5);
    head->next->next->next = createNode(9);
    head->next->next->next->next = createNode(12);
    head->next->next->next->next->next = createNode(15);

    // Count and print the number of nodes with data that are multiples of 3
    int count = countMultiplesOfThree(head);
    printf("Number of nodes with data that are multiples of 3: %d\n", count);

    // Free the allocated memory (not shown here for simplicity)
    // In a real application, you should free all nodes in the linked list

    return 0;
}