#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "types.h"

// TODO: Write deplanePassengers function here...
void deplanePassengers(BoardingList* list) {
    int a, b, c, check = 0;
    a = 0;
    b = 3;
    c = 6;
    
    printf("\nDeplaning passengers...\n");
    while(check < list->passengerCount) {
        if(!isEmpty_v1(&list->seatRows[a].ABC)) {
            for(;!isEmpty_v1(&list->seatRows[a].ABC);) {
                pop_v1(&list->seatRows[a].ABC);
                printf("Deplaning Ben from row %d, seat ABC\n", a+1); 
            }
        } else if (!isEmpty_v2(&list->seatRows[a].DEF)) {
            for(;!isEmpty_v2(&list->seatRows[a].DEF);) {
                pop_v2(&list->seatRows[a].DEF);
                printf("Deplaning Ben from row %d, seat DEF\n", a+1); 
            }
            a++;
        }
        
        if(!isEmpty_v2(&list->seatRows[b].DEF)) {
            for(;!isEmpty_v2(&list->seatRows[b].DEF);) {
                pop_v2(&list->seatRows[b].DEF);
                printf("Deplaning Ben from row %d, seat DEF\n", b+1); 
            }
        } else if (!isEmpty_v1(&list->seatRows[b].ABC)) {
            for(;!isEmpty_v1(&list->seatRows[b].ABC);) {
                pop_v1(&list->seatRows[b].ABC);
                printf("Deplaning Ben from row %d, seat ABC\n", b+1); 
            }
            b++;
        }
        
        if(!isEmpty_v2(&list->seatRows[c].DEF)) {
            for(;!isEmpty_v2(&list->seatRows[c].DEF);) {
                pop_v2(&list->seatRows[c].DEF);
                printf("Deplaning Ben from row %d, seat DEF\n", c+1); 
            }
        } else if (!isEmpty_v1(&list->seatRows[c].ABC)) {
            for(;!isEmpty_v1(&list->seatRows[c].ABC);) {
                pop_v1(&list->seatRows[c].ABC);
                printf("Deplaning Ben from row %d, seat ABC\n", c+1); 
            }
            c++;
        }
        check++;
    }
}
