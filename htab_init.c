//
// Created by matko on 9. 4. 2022.
//
#include "private.h"
#include <stdlib.h>
htab_t *htab_init(size_t n){
    htab_t* table;
    table = malloc(sizeof(htab_t) + n * sizeof(htab_ptr_t*));
    if(table == NULL) { return NULL; }
    table->size =0;
    table->arr_size=n;
    for (int i = 0; i < n; i++) {
        table->items_array[i]=NULL;
    }
    return table;
}