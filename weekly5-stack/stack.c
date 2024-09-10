#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

//complete each fucntion, deleteStack is already complete

LinkedListStack* createStack() {
    LinkedListStack * head = (LinkedListStack *) malloc(sizeof(LinkedListStack));
    head->top = NULL;
    return head;
}

int isEmpty(LinkedListStack* stack) {
    if(stack->top == NULL){
        return 1;
    }
    return 0;
}

void push(LinkedListStack* stack, int data) {
    // dynamically allocate newNode
    Node* newNode = (Node*) malloc(sizeof(Node));
    //assign data to the newNode
    newNode->data = data;
    // assign the next pointer to the old top of the node
    newNode->next = (struct Node *) stack->top;
    // assign the new top the recently created node
    stack->top = newNode;
    printf("%d pushed to stack\n", data);// help debug
}

int pop(LinkedListStack* stack) {
    // call function to see if its empty; if it is returns -1
    if(isEmpty(stack)){
        return -1;
    }

    Node* temp = stack->top;
    int popped = temp->data;
    stack->top = (Node *) temp->next;
    free(temp);
    printf("%d popped from stack\n",popped); // help debug
    return popped;
}

int peek(LinkedListStack* stack) {
    if(isEmpty(stack)){
        return -1;
    }
    Node* peek = stack->top;
    int peeked = peek->data;
    return peeked;
}

//You get this one for free :V
void deleteStack(LinkedListStack* stack) {
    Node* current = stack->top;
    Node* next;

    while (current != NULL) {
        next = (Node *) current->next;
        free(current);
        current = next;
    }

    free(stack);
}
