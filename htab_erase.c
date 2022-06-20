//
// Created by matko on 12. 4. 2022.
//
#include "stdlib.h"
#include "stdbool.h"
#include "private.h"
bool htab_erase( htab_t *table, htab_key_t key){
    htab_pair_t *tmp = htab_find(table, key);
    if(tmp == NULL){
        return false;
    }
    size_t index= htab_hash_function(key) % table->arr_size;
    if(table->items_array[index]->pair->key == key){
        if(table->items_array[index]->next != NULL){
            htab_ptr_t *tmp1 = table->items_array[index]->next;
            free(table->items_array[index]);
            table->items_array[index] = tmp1;
        }
        else{
            free(table->items_array[index]);
        }
    }
    else{
        htab_ptr_t  *tmp1 = table->items_array[index];
        while(tmp1->next->pair->key != key){
            tmp1 = tmp1->next;
        }
        htab_ptr_t *tmp_next = tmp1->next->next;
        free(tmp1->next);
        tmp1->next=tmp_next;
    }
    return true;
}
