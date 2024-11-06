// Assume that you have a
// Stack implemented with linked list, pointer Top is poining to
// the top most node. Writea C function to print the stackin reverseorderi.e. from bottom
// to top.(Do not use array)
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Stack {
    struct Node* top;
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

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = stack->top;
    stack->top = newNode;
}

// Recursive function to print the stack in reverse order
void printStackReverse(struct Node* node) {
    if (node == NULL) {
        return; // Base case: if the node is NULL, return
    }
    printStackReverse(node->next); // Recursive call to go to the next node
    printf("%d ", node->data); // Print the data during unwinding
}

int main() {
    struct Stack stack;
    stack.top = NULL; // Initialize the stack

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    printf("Stack in reverse order (bottom to top):\n");
    printStackReverse(stack.top);
    printf("\n");

    return 0;
}