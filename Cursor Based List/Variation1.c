// Online C compiler to run C program online
#include <stdio.h>

# define MAX 4

typedef struct {
    int elem;
    int next;
} Cell, HeapSpace[MAX];

typedef struct {
    HeapSpace H;
    int avail;
}VHeap;

typedef int List;

void initialize(VHeap* V) {
    V->avail = 0;
    int i;
    for(i = 0; i < MAX; i++) {
        if(i == MAX-1) V->H[i].next = -1;
        else V->H[i].next = i+1;
    }
}
    
int allocSpace(VHeap* V) {
    int ret = V->avail;
    if(ret != -1) {
        V->avail = V->H[ret].next;
    }
    return ret;
}

void insertFirst(int* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
}

// SAYOP MANI
// void insertLast(int* L, VHeap* V, int elem) {
//     int newCell = allocSpace(V);
//     if(newCell != -1) {
//         V->H[newCell].elem = elem;
//         V->H[newCell].next = -1;
//     }
//     int *trav;
//     for(trav = L; trav != NULL; trav = V->H[trav].next);
//     V->H[trav].next = newCell;
// }

void display(int L, VHeap V) {
    for(;L != -1; L = V.H[L].next) printf("%d ", V.H[L].elem);
}
    
    


int main() {
    List L = -1;
    VHeap V;
    initialize(&V);
    insertFirst(&L, &V, 50);
    insertFirst(&L, &V, 100);
    display(L, V);
    

    return 0;
}
