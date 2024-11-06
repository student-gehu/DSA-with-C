// Assume that we have a single linked list; first node ofthe linked |istis:pointed by apointer
// P. Write a C function to print alternate nodesin the |linked list.
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

// Function to print alternate nodes in the linked list
void printAlternateNodes(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* current = head; // Start from the head of the list
    int index = 0; // Initialize index to track node positions

    // Traverse the linked list
    while (current != NULL) {
        if (index % 2 == 0) { // Check if the index is even
            printf("Node at index %d: %d\n", index, current->data); // Print the node's data
        }
        current = current->next; // Move to the next node
        index++; // Increment the index
    }
}

// Main function to demonstrate the functionality
int main() {
    // Create a linked list: 10 -> 20 -> 30 -> 40 -> 50
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);
    head->next->next->next->next = createNode(50);

    // Print alternate nodes in the linked list
    printAlternateNodes(head);

    // Free the allocated memory (not shown here for simplicity)
    // In a real application, you should free all nodes in the linked list

    return 0;
}