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

void deallocSpace(VHeap* V, int index) {
    V->H[index].next = V->avail;
    V->avail = index;
}

void insertFirst(int* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        V->H[newCell].elem = elem;
        V->H[newCell].next = *L;
        *L = newCell;
    }
    else printf("List is Full\n");
}

void insertLast(int* L, VHeap* V, int elem) {
    int newCell = allocSpace(V);
    if(newCell != -1) {
        int *trav;
        V->H[newCell].elem = elem;
        V->H[newCell].next = -1;
        for(trav = L; *trav != -1; trav = &V->H[*trav].next);
        *trav = newCell;
    }
    else printf("List is Full\n");
}



void display(int L, VHeap V) {
    for(;L != -1; L = V.H[L].next) printf("%d ", V.H[L].elem);
}

void delete(int* L, VHeap* V, int elem) {
    int *trav, temp;
    for(trav = L; *trav != -1 && V->H[*trav].elem != elem; trav = &V->H[*trav].next);
    if(*trav != -1) {
        temp = *trav;
        *trav = V->H[*trav].next;
        deallocSpace(V , temp);
    }
}
    
    


int main() {
    List L = -1;
    VHeap V;
    initialize(&V);
    insertFirst(&L, &V, 50);
    delete(&L, &V, 50);
    display(L, V);
    printf("\n");
    insertLast(&L, &V, 2000);
    insertLast(&L, &V, 4000);
    insertLast(&L, &V, 3000);
    insertFirst(&L, &V, 1000);
    display(L, V);
    printf("\n");
    delete(&L, &V, 4000);
    display(L, V);
    printf("\n");
    insertFirst(&L, &V, 5000);


    
    display(L, V);
    

    return 0;
}
