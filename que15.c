//union of the array
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

// Function to insert a node at the end of the linked list
void insertEnd(struct Node** head, int data) {
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

// Function to find the union of two linked lists
struct Node* findUnion(struct Node* head1, struct Node* head2) {
    struct Node* result = NULL;
    struct Node* temp1 = head1;
    struct Node* temp2 = head2;

    // Create a set to store unique elements
    int set[100] = {0};

    // Traverse the first linked list and add elements to the set
    while (temp1 != NULL) {
        set[temp1->data] = 1;   //here 1 is used as a mark that the value is encountered
        temp1 = temp1->next;
    }

    // Traverse the second linked list and add elements to the set
    while (temp2 != NULL) {
        set[temp2->data] = 1;
        temp2 = temp2->next;
    }

    // Create a new linked list with the elements from the set
    for (int i = 0; i < 100; i++) {
        if (set[i] == 1) {            //here we create a new list named as result , we assess the 1 marked element here becaue they are unique
            insertEnd(&result, i);
        }
    }

    return result;
}

// Function to display a linked list
void displayList(struct Node* head) {
    if (head == NULL) {
        printf("The linked list is empty.\n");
        return;
    }

    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head1 = NULL;
    insertEnd(&head1, 1);
    insertEnd(&head1, 2);
    insertEnd(&head1, 3);

    struct Node* head2 = NULL;
    insertEnd(&head2, 2);
    insertEnd(&head2, 3);
    insertEnd(&head2, 4);

    printf("Linked List 1: ");
    displayList(head1);
    printf("Linked List 2: ");
    displayList(head2);

    // Find the union of the two linked lists
    struct Node* result = findUnion(head1, head2);
    printf("Union of Linked Lists: ");
    displayList(result);

    return 0;
}