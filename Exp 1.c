/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

#define MAX 100  // Maximum size of the stack

// Stack structure definition
struct Stack {
    int items[MAX];
    int top;
};

// Function to initialize the stack
void initStack(struct Stack* s) {
    s->top = -1;  // Set top to -1 to indicate the stack is empty
}

// Function to check if the stack is full
int isFull(struct Stack* s) {
    return s->top == MAX - 1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* s) {
    return s->top == -1;
}

// Function to add an element to the stack (push operation)
void push(struct Stack* s, int value) {
    if (isFull(s)) {
        printf("Stack overflow! Cannot push %d.\n", value);
    } else {
        s->items[++(s->top)] = value;
        printf("Element %d pushed to stack.\n", value);
    }
}

// Function to remove and return the top element from the stack (pop operation)
int pop(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack underflow! Cannot pop element.\n");
        return -1;  // Returning -1 as an error code for underflow
    } else {
        return s->items[(s->top)--];
    }
}

// Function to return the top element of the stack without removing it (peek operation)
int peek(struct Stack* s) {
    if (isEmpty(s)) {
        printf("Stack is empty. Cannot peek.\n");
        return -1;
    } else {
        return s->items[s->top];
    }
}

// Function to return the size of the stack
int size(struct Stack* s) {
    return s->top + 1;
}

// Main function to demonstrate stack operations
int main() {
    struct Stack s;
    initStack(&s);  // Initialize the stack

    // Demonstrate stack operations
    push(&s, 10);
    push(&s, 20);
    push(&s, 30);

    printf("Top element is: %d\n", peek(&s));

    printf("Popped element: %d\n", pop(&s));
    printf("Popped element: %d\n", pop(&s));
    
    printf("Stack size: %d\n", size(&s));

    pop(&s);  // This should empty the stack
    pop(&s);  // This will try to pop from an empty stack

    return 0;
}
