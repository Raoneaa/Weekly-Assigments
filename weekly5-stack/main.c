#include <stdio.h>
#include "stack.h"

int main() {
    // Create a new stack
    LinkedListStack* stack = createStack();

    // Push elements onto the stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    // Pop elements from the stack and verify they are in reverse order

    int expected_values[] = {4, 3, 2, 1};
    int i = 0;
    while (!isEmpty(stack)) {
        int value = pop(stack);
        if (value != expected_values[i]) {
            printf("Stack operation failed: Expected %d but got %d\n", expected_values[i], value);
            deleteStack(stack);
            return 1; // Exit with error code
        }
        i++;
    }

    // Check if the stack is empty after popping
    if (isEmpty(stack)) {
        printf("Stack operations were successful.\n");
    } else {
        printf("Stack operation failed: Stack is not empty after popping all elements.\n");
    }

    // Free memory allocated for the stack
    deleteStack(stack);

    return 0;
}
