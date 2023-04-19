#include <stdio.h>
#include <stdlib.h>

// Node struct wich holds a value
// and a pointer to next Node struct
typedef struct Node {
    int value;
    struct Node *next;
} Node;

// Queue wrapper of Node struct
// placing a head and a tail
typedef struct {
    int length;
    Node *head;
    Node *tail;
} Queue;

void enqueue(Queue *q, int item);
void deque(Queue *q);

int main() {

    // Queue initialization
    Queue *q = malloc(sizeof(Queue));
    q->length = 0;
    // both head and tail starts without a value
    q->head = q->tail = NULL;

    enqueue(q, 1);
    enqueue(q, 2);
    deque(q);

    printf("Queue head: %d\n", ((q->head != NULL) ? (q->head)->value : -1));
    printf("Queue tail: %d\n", ((q->tail != NULL) ? (q->tail)->value : -1));

    return 0;
}

// append to the tail of the queue
// and set a pointer to the next available Node
void enqueue(Queue *q, int item) {
    Node *temp = malloc(sizeof(Node));
    temp->value = item;
    temp->next = NULL;
    q->length++;

    if (q->tail == NULL) q->head = q->tail = temp;
    q->tail->next = temp;
    q->tail = temp;

    return;
}

// pop a value from the head of a queue
// and point to the next Node in line
void deque(Queue *q) {
    if (q->head == NULL) return;

    q->length--;

    Node *temp = q->head;
    q->head = q->head->next;

    free(temp);
    if (q->head == NULL) q->tail = NULL;

    return;
}
