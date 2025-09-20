#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// TODO: Write helper functions here...
void initializeStack_v1(Group* g) {
    g->top = -1;
}
bool isFull_v1(Group* g) {
    if(g->top == MAX_PASSENGERS-1) return true;
    else return false;
}
bool isEmpty_v1(Group* g) {
    if(g->top == -1) return true;
    else return false;
}

void push_v1(Group* g, char* value) {
    if(!isFull_v1(g)) {
        g->top++;
        strcpy(g->p[g->top].passengerName, value); 
    }
}

void pop_v1(Group* g) {
    if(!isEmpty_v1(g)) {
        g->top--;
    }
}
    
    
void initializeStack_v2(Group* g) {
    g->top = MAX_PASSENGERS;
}

bool isFull_v2(Group* g) {
    if(g->top == 0) return true;
    else return false;
}
    
bool isEmpty_v2(Group* g) {
    if(g->top == MAX_PASSENGERS) return true;
    else return false;
}
void push_v2(Group* g, char* value) {
    if(!isFull_v2(g)) {
        g->top--;
        strcpy(g->p[g->top].passengerName, value); 
    }
}
void pop_v2(Group* g) {
    if(!isEmpty_v2(g)) {
        g->top++;
    }
}
