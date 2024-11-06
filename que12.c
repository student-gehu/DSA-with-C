// We have a‘singly linked list; first node of thelinked listis pointed by apointerPTI 3
// Write aC functionto print the node having highest information in that. singly linked
// list.
#include <stdio.h>
#include <stdlib.h>
#include <limits.h> // For INT_MIN

struct Node {
    int data;
    struct Node* next;
};

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

// Function to print the node with the highest value in the linked list
void printNodeWithHighestValue(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* current = head;
    int maxValue = INT_MIN; // Initialize to the smallest integer
    struct Node* maxNode = NULL; // Pointer to the node with the highest value

    // Traverse the linked list
    while (current != NULL) {
        if (current->data > maxValue) {
            maxValue = current->data; // Update max value
            maxNode = current; // Update pointer to the node with max value
        }
        current = current->next; // Move to the next node
    }

    // Print the node with the highest value
    if (maxNode != NULL) {
        printf("Node with the highest value: %d\n", maxNode->data);
    }
}

// Main function to demonstrate the functionality
int main() {
    // Create a linked list: 10 -> 20 -> 5 -> 30 -> 15
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(5);
    head->next->next->next = createNode(30);
    head->next->next->next->next = createNode(15);

    // Print the node with the highest value
    printNodeWithHighestValue(head);

    // Free the allocated memory (not shown here for simplicity)
    // In a real application, you should free all nodes in the linked list

    return 0;
}