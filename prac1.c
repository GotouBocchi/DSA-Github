// Online C compiler to run C program online
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef enum{
    BSIT = 1,
    BSCS,
    BSIS
}Course;

const char* courseNames[] = {"", "BSIT", "BSCS", "BSIS"};

typedef struct {
    int id;
    char fname[55];
    char lname[55];
    Course course;
    int yearlvl;
    float grades;
} Student;

typedef struct newNode{
    Student person;
    struct newNode* next;
}newNode, *newNodePtr;

// typedef struct{
//     newNodePtr front;
//     newNodePtr rear;
// }Queue;

typedef struct {
    newNodePtr top;
}Stack;

// typedef struct {
//     newNodePtr head;
//     int count;
// }List;

Stack* initStack() {
    Stack* S = malloc(sizeof(Stack));
    if(S != NULL) {
        S->top = NULL;
        return S;
    }
    else return NULL;
}

bool isFullStack(Stack* s) {
    return false;
}

bool isEmptyStack(Stack* s) {
    if(s->top == NULL) return true;
    else return false;
}

void push(Stack* s, Student person) {
    newNode* node = malloc(sizeof(newNode));
    node->person = person;
    node->next = s->top;
    s->top = node;
}

int pop(Stack* s) {
    if(s->top != NULL) {
        newNode* trav;
        int store;
        trav = s->top;
        store = trav->person.id;
        s->top = trav->next;
        free(trav);
        return store;
    }
    else return -1;
}

int peek(Stack* s) {
    
}

void displayStack(Stack* s) {
    newNode* trav;
    printf("\n\n-----Display-----\n");
    for(trav = s->top; trav != NULL; trav = trav->next) {
        printf("ID: %d\n", trav->person.id);
        printf("First Name: %s\n", trav->person.fname);
        printf("Last Name: %s\n", trav->person.lname);
        printf("Course: %s\n", courseNames[trav->person.course]);
        printf("Year lvl: %d\n", trav->person.yearlvl);
        printf("Grades: %.2f\n\n", trav->person.grades);
    }
    printf("-----End Display-----\n\n");
}
/*
Queue* initQueue() {
    Queue* Q = malloc(sizeof(Queue));
    if(Q != NULL) {
        Q->front = NULL;
        Q->rear = NULL;
        return Q;
    }
    else return NULL;
}

bool isFullQueue(Queue* q) {
    
}

bool isEmptyQueue(Queue* q) {
    
}

void enqueue(Queue* q, int value) {
    
}

int dequeue(Queue* q) {
    
}

int front(Queue* q) {
    
}

void displayQueue(Queue* q) {
    
}

List* initList() {
    List* L = malloc(sizeof(List));
    if(L != NULL) {
        L->head = NULL;
        L->count = 0;
        return L;
    }
    else return NULL;
}

void empty(List *list) {
    
}

void insertFirst(List *list, int data) {
    
}

void insertLast(List *list, int data) {
    
}

void insertPos(List *list, int data, int index) {
    
}

void deleteStart(List *list) {
    
}

void deleteLast(List *list) {
    
}

void deletePos(List *list, int index) {
    
}

int retrieve(List *list, int index) {
    
}

int locate(List *list, int data) {
    
}

void displayList(List *list) {
    
}
*/
void showStackMenu(Stack* S) {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- Stack Menu ---\n");
        printf("1. isFullStack\n");
        printf("2. isEmptyStack\n");
        printf("3. push\n");
        printf("4. pop\n");
        printf("5. peek\n");
        printf("6. displayStack\n");
        printf("0. Back to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
            printf("isFullStack() = %d\n", isFullStack(S)); 
            break;
            
            case 2: 
            printf("isEmptyStack() = %d\n", isEmptyStack(S)); 
            break;
            
            case 3: 
            Student person;
            printf("ID: ");
            scanf(" %d", &person.id);
            printf("First Name: ");
            scanf(" %s", &person.fname);
            printf("Last Name: ");
            scanf(" %s", &person.lname);
            printf("Course: ");
            scanf(" %d", &person.course);
            printf("Year lvl: ");
            scanf(" %d", &person.yearlvl);
            printf("Grades: ");
            scanf(" %f", &person.grades);
            push(S, person); 
            printf("push() called\n"); 
            break;
            
            case 4: 
            printf("pop() = %d\n", pop(S)); 
            break;
            
            case 5: 
            printf("peek() = %d\n", peek(S)); 
            break;
            
            case 6: 
            displayStack(S); 
            break;
            
            case 0: 
            printf("Returning to Main Menu...\n"); 
            break;
            
            default: printf("Invalid choice!\n"); break;
        }
    }
}
/*
// ===== QUEUE MENU =====
void showQueueMenu(Queue* Q) {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- Queue Menu ---\n");
        printf("1. isFullQueue\n");
        printf("2. isEmptyQueue\n");
        printf("3. enqueue\n");
        printf("4. dequeue\n");
        printf("5. front\n");
        printf("6. displayQueue\n");
        printf("0. Back to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("isFullQueue() = %d\n", isFullQueue()); break;
            case 2: printf("isEmptyQueue() = %d\n", isEmptyQueue()); break;
            case 3: enqueue(); printf("enqueue() called\n"); break;
            case 4: printf("dequeue() = %d\n", dequeue()); break;
            case 5: printf("front() = %d\n", front()); break;
            case 6: displayQueue(); break;
            case 0: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    }
}

// ===== LIST MENU =====
void showListMenu(List* L) {
    int choice = -1;
    while (choice != 0) {
        printf("\n--- List Menu ---\n");
        printf("1. empty\n");
        printf("2. insertFirst\n");
        printf("3. insertLast\n");
        printf("4. insertPos\n");
        printf("5. deleteStart\n");
        printf("6. deleteLast\n");
        printf("7. deletePos\n");
        printf("8. retrieve\n");
        printf("9. locate\n");
        printf("10. displayList\n");
        printf("0. Back to Main Menu\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: printf("empty() = %d\n", empty()); break;
            case 2: insertFirst(); printf("insertFirst() called\n"); break;
            case 3: insertLast(); printf("insertLast() called\n"); break;
            case 4: insertPos(); printf("insertPos() called\n"); break;
            case 5: deleteStart(); printf("deleteStart() called\n"); break;
            case 6: deleteLast(); printf("deleteLast() called\n"); break;
            case 7: deletePos(); printf("deletePos() called\n"); break;
            case 8: printf("retrieve() = %d\n", retrieve()); break;
            case 9: printf("locate() = %d\n", locate()); break;
            case 10: displayList(); break;
            case 0: printf("Returning to Main Menu...\n"); break;
            default: printf("Invalid choice!\n"); break;
        }
    }
}
*/
void main() {
    Stack *S;
    S = initStack();
    

    int choice = -1;
    while (choice != 0) {
        printf("\n===== Main Menu =====\n");
        printf("1. Stack\n");
        printf("2. Queue\n");
        printf("3. List\n");
        printf("0. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: 
            showStackMenu(S); 
            break;
            
            // case 2: 
            // showQueueMenu(); 
            // break;
            
            // case 3: 
            // showListMenu(); 
            // break;
            
            case 0: 
            printf("Exiting program...\n"); 
            break;
            
            default: 
            printf("Invalid choice!\n"); 
            break;
        }
    }
}
