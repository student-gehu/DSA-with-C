// assume that we have a single linked list with a pointer p at first node. write a c function to input a number and search it in the linked list if number is found update the link list by deleting that node otherwise prite number not found .

#include <stdio.h>
#include <stdlib.h>


struct Node {
    int data;
    struct Node* next;
};


struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insert(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node with a specific value
void deleteNode(struct Node** head, int value) {
    struct Node* temp = *head;
    struct Node* prev = NULL;

    while (temp != NULL && temp->data != value) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Number %d not found in the list.\n", value);
        return;
    }

    if (prev == NULL) {          //it means the head is itself that should be deleated by function
        *head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
    printf("Node with value %d deleted.\n", value);
}


void displayList(struct Node* temp) {
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = NULL;
    int value;

    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    printf("Initial linked list: ");
    displayList(head);

    // Input a number to search and delete
    printf("Enter a number to search and delete: ");
    scanf("%d", &value);

    // Delete the node with the specified value
    deleteNode(&head, value);

    // Display the updated linked list
    printf("Updated linked list: ");
    displayList(head);

    return 0;
}