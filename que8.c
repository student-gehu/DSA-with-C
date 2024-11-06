// assume that we have two singly linked list . pointers p and q pointing to first node of the linked lists respectively. write a c function to print similar nodes from both the linked lists.
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

// Function to print similar nodes from two linked lists
void printSimilarNodes(struct Node* p, struct Node* q) {
    while (p != NULL && q != NULL) {
        if (p->data == q->data) {
            printf("%d ", p->data); // Print similar node
            p = p->next; // Move to the next node in the first list
            q = q->next; // Move to the next node in the second list
        } else if (p->data < q->data) {
            p = p->next; // Move to the next node in the first list
        } else {
            q = q->next; // Move to the next node in the second list
        }
    }
    printf("\n");
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(3);
    list1->next->next->next = createNode(4);
    list1->next->next->next->next = createNode(5);

    struct Node* list2 = createNode(2);
    list2->next = createNode(3);
    list2->next->next = createNode(5);
    list2->next->next->next = createNode(6);

    printf("List 1: ");
    displayList(list1);
    printf("List 2: ");
    displayList(list2);

    printf("Similar nodes: ");
    printSimilarNodes(list1, list2); // Print similar nodes

    return 0;
}