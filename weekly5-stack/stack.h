#ifndef STACK_H
#define STACK_H

// Structure for a node in the stack
typedef struct {
    int data;
    struct Node* next;
} Node;

// Structure for the linked list based stack
typedef struct {
    Node* top;  // Pointer to the top of the stack
} LinkedListStack;

// Function declarations
LinkedListStack* createStack(); //create a basic stack
void push(LinkedListStack* stack, int data); //add new element to top of stack
int pop(LinkedListStack* stack); //return and remove top element of stack
int peek(LinkedListStack* stack); //return the element at the top of the stack without removing it
int isEmpty(LinkedListStack* stack); //return 1 if stack empty, 0 if not
void deleteStack(LinkedListStack* stack); //delete the stack, this is done for you already :)

#endif /* LINKED_LIST_STACK_H */