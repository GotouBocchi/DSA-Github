#ifndef ENCHANTED_101_H
#define ENCHANTED_101_H

#include <stdbool.h>

#define MAX 10

// The Sacred Item Structure
typedef struct {
    char itemName;    // Single-letter rune identifying the item
    float weight;     // Mystical weight in ethereal units
} Item;

// The Mystical Node Connection
typedef struct {
    Item item;        // The actual treasure
    int next;         // Ethereal link to the next item below
} Node;

// The Dimensional Storage Space
typedef struct {
    Node nodes[MAX];  // 10 sacred storage slots
    int avail;        // Portal to the realm of unused slots
} VSpace;

// The Enchanted Backpack
typedef struct {
    int top;              // Index of the topmost item
    float currentWeight;  // Current magical burden
    float maxWeight;      // Maximum mystical capacity
    VSpace *vs;          // Pointer to the dimensional storage
} Stack;

// Function prototypes
void initVSpace(VSpace *vs);
void initStack(Stack *s, VSpace *vs, float maxWeight);
int allocNode(VSpace *vs);
void deallocNode(VSpace *vs, int index);
void push(Stack *s, Item i);
void pop(Stack *s);
void peek(Stack s);
void displayItems(Stack s);
bool isEmpty(Stack s);
void makeEmpty(Stack *s);
void visualizeVSpace(VSpace vs);
void printFantasyHeader(const char* title);
void showTrialMenu();
void runSelectedTrial(int trialNumber, Stack *backpack, VSpace *storage);
void runAllTrials();
void runInteractiveMode();

#endif
