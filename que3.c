// assume that we have a single linked list and a key, first node of the linked list is pointed by a pointer start. write a c functiont to print the node having information lesser than key value in the linked list.
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Function to print nodes with data less than the given key
void printLessThanKey(struct Node* start, int key) {
    struct Node* current = start;

    printf("Nodes with data less than %d: ", key);
    while (current != NULL) {
        if (current->data < key) {
            printf("%d -> ", current->data);
        }
        current = current->next;
    }
    printf("NULL\n");
}

// Function to create a new node with the given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the end of the linked list
void insertNode(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Node* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    struct Node* head = NULL;

    insertNode(&head, 10);
    insertNode(&head, 5);
    insertNode(&head, 20);
    insertNode(&head, 3);
    insertNode(&head, 15);

    int key = 20;
    printLessThanKey(head, key);

    return 0;
}