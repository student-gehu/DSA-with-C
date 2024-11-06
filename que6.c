#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node *prev;
    int data;
    struct node *next;
};

// Function to create a new node
struct node *createNode(int data) {
    struct node *newnode = (struct node *)malloc(sizeof(struct node));
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;
    return newnode;
}

// Function to insert a new node at the end of the circular doubly linked list
void insertNode(struct node **head, int data) {
    struct node *newnode = createNode(data);
    if (*head == NULL) {
        *head = newnode;
        newnode->next = newnode; 
        newnode->prev = newnode; 
    } else {
        struct node *tail = (*head)->prev; // Get the last node
        tail->next = newnode; // Link the last node to the new node
        newnode->prev = tail; // Link the new node back to the last node
        newnode->next = *head; // Link the new node to the head
        (*head)->prev = newnode; // Update head's prev to the new node
    }
}

// Function to delete a node from the beginning of the circular doubly linked list
void deleteNodeBeg(struct node **head) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *temp = *head;

    // If there's only one node in the list
    if (temp->next == *head) {
        free(temp);
        *head = NULL; // List becomes empty
    } else {
        struct node *tail = (*head)->prev; // Get the last node
        *head = (*head)->next; // Move head to the next node
        (*head)->prev = tail; // Update new head's prev pointer
        tail->next = *head; // Link the last node to the new head
        free(temp); // Free the old head
    }
}

// Function to delete a specific node from the circular doubly linked list
void deleteNode(struct node **head, int key) {
    if (*head == NULL) {
        printf("List is empty!\n");
        return;
    }

    struct node *current = *head;
    struct node *temp = NULL;

    // Check if the node to be deleted is the head node
    if (current->data == key) {
        deleteNodeBeg(head);
        return;
    }

    // Traverse the list to find the node to delete
    do {
        if (current->data == key) {
            temp = current;
            current->prev->next = current->next; // Bypass the node to delete
            current->next->prev = current->prev; // Update the next node's prev pointer
            free(temp);
            return;
        }
        current = current->next;
    } while (current != *head);

    printf("Node with value %d not found in the list.\n", key);
}

// Function to display the circular doubly linked list
void display(struct node *head) {
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }
    struct node *temp = head;
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

// Main function to demonstrate the functionality
int main() {
    struct node *head = NULL;
    insertNode(&head, 10);
    insertNode(&head, 20);
    insertNode(&head, 30);
    insertNode(&head, 40);
    insertNode(&head, 50);

    printf("List before deletion from beginning:\n");
    display(head);

    deleteNodeBeg(&head); // Delete from the beginning
    printf("List after deletion from beginning:\n");
    display(head);

    // Delete a specific node
    deleteNode(&head, 30);
    printf("List after deleting node with value 30:\n");
    display(head);

    // Delete the last remaining node
    deleteNode(&head, 50);
    printf("List after deleting node with value 50:\n");
    display(head);

    // Delete the head node
    deleteNode(&head, 10);
    printf("List after deleting head node with value 10:\n");
    display(head);

    // Attempt to delete from an empty list
    deleteNodeBeg(&head);
    printf("List after attempting to delete from an empty list:\n");
    display(head);

    return 0;
}