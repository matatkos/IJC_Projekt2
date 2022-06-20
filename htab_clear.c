//
// Created by matko on 12. 4. 2022.
//
#include "private.h"
#include "stdlib.h"
void htab_clear(htab_t *table){
    for (int i = 0; i < table->arr_size; i++) {
        htab_ptr_t *tmp = table->items_array[i];
        table->items_array[i] = NULL;
        while (tmp){
            htab_ptr_t *tmp2 = tmp->next;
            free((char*)tmp->pair->key);
            free(tmp);
            tmp=tmp2;
        }
    }
}