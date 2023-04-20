#include <stdio.h>
#include <stdlib.h>

// Simple Stack implementation in C
// Different from Queues, Stacks works
// on inverse order.
// Last item goes out first.

// Node struct which holds a value
// and a pointer to the previous node
typedef struct Node {
    int value;
    struct Node *prev;
} Node;

// Stack structure
typedef struct {
    int length;
    Node *head;
} Stack;

// Stack methods
// push
// pop
// peek
void push(Stack *stack, int item);
void pop(Stack *stack);
void peek(Stack *stack);

int main() {

    // Stack initialization
    Stack *stack = malloc(sizeof(Stack));
    // Empty stack initialization
    stack->length = 0;

    // push some items into the stack
    push(stack, 1);
    push(stack, 2);
    push(stack, 3);
    push(stack, 4);
    push(stack, 5);

    // pop one item of the stack (FILO)
    pop(stack);

    // peek shows the item on top of the Stack
    peek(stack);

    return 0;
}

void push(Stack *stack, int item) {

    // Node initialization
    Node *temp = malloc(sizeof(Node));
    temp->value = item;
    temp->prev = NULL;

    // Stack length increased
    stack->length++;

    // if Stack is empty just add the node
    if(!stack->head) {
        stack->head = temp;
        return;
    }

    // if Stack is not empty
    // then point the head to
    // the top of the Stack again
    temp->prev = stack->head;
    stack->head = temp;
    return;
}

void pop(Stack *stack) {

    // decrease the stack length
    // but must care to not go to
    // the negative land
    stack->length--;
    if (stack->length <= 0) {
        stack->head = NULL;
        return;
    }

    // point the head of the Stack
    // to the node that comes next
    // on top of the Stack
    Node *temp = stack->head;
    stack->head = stack->head->prev;

    // free the popped item
    free(temp);

    return;
}

void peek(Stack *stack) {

    // simply print out the value
    // of the node on top of the Stack
    // it can also print other values
    // with "stack->head->prev->value"
    if (stack->head != NULL) printf("%d\n", stack->head->value);
    return;
}
