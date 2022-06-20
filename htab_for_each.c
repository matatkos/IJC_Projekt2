//
// Created by matko on 14. 4. 2022.
//
#include "private.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    for (int i = 0; i < t->arr_size; i++) {
        htab_ptr_t *tmp = t->items_array[i];
        while(tmp){
            f(t->items_array[i]->pair);
            tmp= tmp->next;
        }
    }
}
