//
// Created by matko on 9. 4. 2022.
//
#include "private.h"


void htab_resize(htab_t *target_table, size_t newn){
    htab_t *new_table= htab_init(newn);

    for (int i = 0; i < target_table->arr_size; i++) {
        if(target_table->items_array[i] != NULL){
            size_t index = htab_hash_function(target_table->items_array[i]->pair->key) % newn;
            if(new_table->items_array[index] != NULL){
                struct htab_ptr *tmp = new_table->items_array[index];
                while(tmp->next != NULL){
                    tmp = tmp->next;
                }
                tmp->next=target_table->items_array[i];
                tmp->next->next=NULL;
            }
            else{
                new_table->items_array[index]=target_table->items_array[i];
                new_table->items_array[index]->next=NULL;
            }
        }

        if(target_table->items_array[i]->next != NULL){
            struct htab_ptr *tmp1 = target_table->items_array[i]->next;
            while(tmp1->next != NULL){
                size_t index = htab_hash_function(tmp1->pair->key) % newn;
                if(new_table->items_array[index] != NULL){
                    struct htab_ptr *tmp = new_table->items_array[index];
                    while(tmp->next != NULL){
                        tmp = tmp->next;
                    }
                    tmp->next=tmp1;
                    tmp->next->next=NULL;
                }
                else{
                    new_table->items_array[index]=tmp1;
                    new_table->items_array[index]->next=NULL;
                }
                tmp1= tmp1->next;
            }
        }
    }
}
