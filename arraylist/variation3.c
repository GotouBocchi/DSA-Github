#include <stdio.h>
#include <stdlib.h>

#define LENGHT 10

typedef struct{
    int *elemPtr;
    int count;
    int max;

}List;

void display(List L) {
    int i;
    
    printf("Data: ");
    
    for(i=0; i < L.count; i++) {
        printf("%d", L.elemPtr[i]);
    }
    printf("\nCount: %d\n", L.count);
    
}

List initialize(List L) {
    L.max = LENGHT;
    L.elemPtr = malloc(L.max * sizeof(int));
    L.count = 0;
    
    return L;
}

List insertPos(List L, int data, int position) {
    int i;
    L.count++;
    for(i=L.count; i > position; i--){
        L.elemPtr[i] = L.elemPtr[i-1];
    }
    L.elemPtr[i] = data;
    
    return L;
}
List deletePos();
int locate();
List instertSorted();

List resize();

int main() {
    List L;
    
    L = initialize(L);
    
    L.elemPtr[0] = 1;
    L.elemPtr[1] = 3;
    L.elemPtr[2] = 4;
    L.elemPtr[3] = 9;
    L.count = 4;

    display(L);
    
    L = insertPos(L, 2, 1);
    
    display(L);
   
    return 0;
}
