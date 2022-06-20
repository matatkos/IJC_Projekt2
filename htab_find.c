//
// Created by matko on 10. 4. 2022.
//
#include "private.h"
htab_pair_t * htab_find(htab_t * table, htab_key_t key){
    size_t index = htab_hash_function(key) % table->arr_size;
    htab_ptr_t *tmp = table->items_array[index];
    while(tmp){
        if(strcmp(tmp->pair->key,key)== 0){
            return tmp->pair;
        }
        tmp=tmp->next;
    }
    return NULL;
}
