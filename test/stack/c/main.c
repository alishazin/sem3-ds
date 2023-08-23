#include <stdio.h>
#include <stdlib.h>

typedef struct Stack{
    int size;
    int top;
    int *array;
} Stack;

struct Stack* createStack(int size) {
    Stack *stack = (Stack*) malloc(sizeof(Stack*));
    
    stack->size = size;
    stack->top = -1; 
    stack->array = (int*) malloc(size * sizeof(int));

    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1 ? 1 : 0;
}

int isFull(Stack* stack) {
    return stack->top == stack->size - 1 ? 1 : 0;
}

void push(Stack* stack, int item) {
    
    if (isFull(stack)) {
        printf("\nStack Overflow!");
        return;
    } 

    stack->top++;
    stack->array[stack->top] = item;
}

void display(Stack* stack) {

    if (isEmpty(stack)) {
        printf("\nEmpty Stack!");
        return;
    }

    for (int i=stack->top; i>-1; i--) {
        if (i == stack->top) {
            printf("\n\n%d <-- Top", stack->array[i]);
        } else {
            printf("\n%d", stack->array[i]);
        }
    }
    printf("\nSize = %d\n", stack->size);
}

int pop(Stack* stack) {

    if (isEmpty(stack)) {
        printf("Stack Underflow!");
        return -1;
    }
    
    stack->top--;
    return stack->array[stack->top + 1];
}

int peek(Stack* stack) {

    if (isEmpty(stack)) {
        printf("Empty Stack!");
        return -1;
    }
    
    return stack->array[stack->top];
}

int main() {

    Stack* stack = createStack(5);
    push(stack, 10);
    push(stack, 30);
    push(stack, 20);
    printf("\nPopped element: %d", pop(stack));
    printf("\nTop element: %d", peek(stack));
    
    push(stack, 50);

    display(stack);


    return 0;
}