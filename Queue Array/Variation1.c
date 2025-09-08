// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 10

typedef struct {
    int items[MAX];
    int count;
}List;

typedef struct {
    List list;
    int front;
    int rear;
}Queue;

Queue* initialize() {
    Queue* Q = malloc(sizeof(Queue));
    Q->list.count = 0;
    Q->front = Q->rear = -1;
    
    return Q;
}

bool isFull(Queue* q) {
    if(q->list.count == MAX) return true;
    else return false;
}

bool isEmpty(Queue* q) {
    if(q->list.count == 0) return true;
    else return false;
}

void enqueue(Queue* q, int value) {
    if(q->list.count == MAX) printf("Q = is full");
    else if(isEmpty(q)) {
        q->front = q->rear =+ 1;
    }
    else {
        q->rear = (q->rear+1)%MAX;
    }
    q->list.items[q->rear] = value;
}

void display(Queue* q) {
    int i, x;
    for(i = q->front, x =0; x != q->list.count; i = (i+1)%MAX, x++) {
        printf("%d", q->list.items[i]);
    }
}


int main() {
    Queue* Q = initialize();
    printf("%d\n", isFull(Q));
    printf("%d\n", isEmpty(Q));
    
    Q->list.items[8] = 8;
    Q->list.items[9] = 9;
    Q->list.items[0] = 0;
    Q->list.items[1] = 1;
    Q->list.items[2] = 2;
    Q->front = 8;
    Q->rear = 2;
    Q->list.count =5;
    
    display(Q);
    

    return 0;
}
