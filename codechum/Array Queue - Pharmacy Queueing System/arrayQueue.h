#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "types.h"

// write your functions here
Queue* initialize() {
    Queue* Q = malloc(sizeof(Queue));
    Q->front = -1;
    Q->rear = -1;
    Q->list.count = 0;
    
}

void enqueue(Queue* q, int value) {
    if(isEmpty(q)) {
        q->front++;
        q->rear++;
    } 
    else if(isFull(q)) {
        // printf("Queue is Full");
        return;
    } 
    else {
        q->rear = ((q->rear + 1) % MAX);
    }
    q->list.items[q->rear] = value;
    q->list.count++;
    
}

int dequeue(Queue* q) {
    if(isEmpty(q)) {
        printf("Queue is Empty");
        return -1;
    }
    else {
        q->front = ((q->front + 1) % MAX);
        q->list.count--;
        return (q->list.items[(q->front - 1 + MAX) % MAX]);
    }
}

bool isFull(Queue* q) {
    if(q->list.count == MAX) return true;
    else return false;
}

bool isEmpty(Queue* q) {
    if(q->list.count == 0) return true;
    else return false;
}

void display(Queue* q) {
    if(isEmpty(q)) printf("Queue is empty.\n");
    else {
        int trav, i;
        for(i = q->front, trav = 0; trav < q->list.count; trav++, i = ((q->front + 1) % MAX)) printf("%d ", q->list.items[i]);
        printf("\n");
    }
    
}
