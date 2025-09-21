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
        if(isEmpty_v1(&list->seatRows[a].ABC)) {
            pop(&list->seatRows[a].ABC))
            printf("Deplaning Ben from row %d, seat ABC", a)
        } else if (isEmpty_v2(&list->seatRows[a].DEF)) {
            pop_v2(&list->seatRows[a].DEF));
            printf("Deplaning Ben from row %d, seat DEF", a)
        }
        
        if(isEmpty_v1(&list->seatRows[b].ABC)) {
            pop(&list->seatRows[b].ABC))
            printf("Deplaning Ben from row %d, seat ABC", a)
        } else if (isEmpty_v2(&list->seatRows[a].DEF)) {
            pop_v2(&list->seatRows[a].DEF));
            printf("Deplaning Ben from row %d, seat DEF", a)
        }
        
    }
}
