// Assume that we have a singly linked list , first node of the linked list is pointed by a pointer ptr.write a c function to deleat loop in the linked list.
#include <stdio.h>
#include <stdlib.h>

// Define the structure for a node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Function to detect and remove a loop in the linked list
void deleteLoop(struct Node* head) {
    struct Node *slow = head, *fast = head;

    // Detect loop using Floyd's Cycle Detection Algorithm
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) { // Loop detected
            slow = head; // Move slow to the start
            while (slow != fast) {
                slow = slow->next;
                fast = fast->next;
            }
            // Find the last node in the loop
            while (fast->next != slow) {
                fast = fast->next;
            }
            fast->next = NULL; // Remove the loop
            return;
        }
    }
}

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next!=NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

void displayList(struct Node* node) {
    while (node) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;

    insertNode(&head, 1);
    insertNode(&head, 2);
    insertNode(&head, 3);
    insertNode(&head, 4);
    insertNode(&head, 5);

    // Create a loop for testing (linking last node to the second node)
    head->next->next->next->next->next = head->next;

    // Attempt to delete the loop
    deleteLoop(head);

    // Display the linked list after attempting to delete the loop
    printf("Linked List after removing loop: ");
    displayList(head); // This will not work correctly if the loop was not removed

    return 0;
}