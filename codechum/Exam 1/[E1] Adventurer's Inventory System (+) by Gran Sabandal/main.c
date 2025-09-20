#include <stdio.h>
#include <stdbool.h>
#include "enchanted101.h"

// The Sacred Push Spell
void push(Stack *s, Item i) {
 // [Task 1] To do code logic here ...



}

// Main adventure function
int main() {
    printf("Cursor-Based Stack Test Program\n");
    printf("Testing push() function implementation\n\n");

    // Show menu and get single choice
    int choice;
    Stack testStack;
    VSpace storage;

    // Initialize
    initVSpace(&storage);
    initStack(&testStack, &storage, 25.0);

    showTrialMenu();
    scanf("%d", &choice);

    switch(choice) {
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
            runSelectedTrial(choice, &testStack, &storage);
            break;

        case 8:
            runAllTrials();
            break;

        case 9:
            runInteractiveMode();
            break;

        case 0:
            printf("Program ended.\n");
            break;

        default:
            printf("Invalid choice\n");
    }

    return 0;
}
