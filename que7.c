//mearge short two sort linked list
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int val;
    struct Node* next;
};

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->val = value;
    newNode->next = NULL;
    return newNode;
}

// Function to merge two sorted linked lists
struct Node* mergeTwoLists(struct Node* list1, struct Node* list2) {
    // Create a dummy node to simplify the merging process
    struct Node* temp = createNode(0);
    struct Node* tail=temp ; 
    temp->next = NULL; // Initialize the dummy node's next to NULL

    // Iterate through both lists
    while (list1 != NULL && list2 != NULL) {
        if (list1->val < list2->val) {
            tail->next = list1; // Append list1 node
            list1 = list1->next; // Move to the next node in list1
        } else {
            tail->next = list2; // Append list2 node
            list2 = list2->next; // Move to the next node in list2
        }
        tail = tail->next; // Move the tail pointer forward
    }

    // If there are remaining nodes in either list, append them
    if (list1 != NULL) {
        tail->next = list1;
    } else {
        tail->next = list2;
    }

    // Return the merged list, which starts from the next of the dummy node
    return temp->next;
}

// Function to print the linked list
void printList(struct Node* head) {
    struct Node* current = head;
    while (current != NULL) {
        printf("%d ", current->val);
        current = current->next;
    }
    printf("\n");
}

// Main function to demonstrate the merge function
int main() {
    // Create first sorted linked list: 1 -> 2 -> 4
    struct Node* list1 = createNode(1);
    list1->next = createNode(2);
    list1->next->next = createNode(4);

    // Create second sorted linked list: 1 -> 3 -> 4
    struct Node* list2 = createNode(1);
    list2->next = createNode(3);
    list2->next->next = createNode(4);

    // Merge the two lists
    struct Node* mergedList = mergeTwoLists(list1, list2);

    // Print the merged list
    printf("Merged List: ");
    printList(mergedList);

    // Free memory (not shown here for brevity)
    // You should free the nodes in the merged list and the original lists

    return 0;
}