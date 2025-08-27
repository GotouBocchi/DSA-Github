#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct{
    int elem[MAX];
    int count;

}List;

void display(List L){
    int i = 0;
    for(i=0; i<L.count; i++){
        printf("%d", L.elem[i]);
    }
    printf("\n");
}

List insertPos(List L, int data, int position){
    int i;
    for(i = L.count; i > position; i--){
        L.elem[i] = L.elem[i-1];
    }
    
    L.elem[i] = data;
    L.count++;

    return L;
}

List deletePos(List L, int position){
    int i;
    
    for(i=position; i < L.count; i++) {
        L.elem[i] = L.elem[i+1];
    }
    L.elem[i] = 0;
    L.count -= 1;
    
    return L;
}

int locate(List L, int data){
    int i;
    for(i=0; i<L.count; i++){
        if(L.elem[i] == data) {
            return i;
        }
    }
    
    return -1;
}


int main() {
    List l;
    int i;
    
    l.elem[0] = 1;
    l.elem[1] = 3;
    l.elem[2] = 2;
    l.elem[3] = 5;
    l.count = 4;
    
    display(l);
    
    l = insertPos(l, 4, 2);
    
    display(l);
    
    l = deletePos(l, 1);
    
    display(l);
    
    printf("\n%d" ,locate(l, 4));

    return 0;
}