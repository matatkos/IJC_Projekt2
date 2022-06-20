//
// Created by matko on 10. 4. 2022.
//

#include "stdlib.h"
#include "stdio.h"
#include "private.h"
#include "string.h"
htab_pair_t *htab_lookup_add(htab_t *t, htab_key_t key){
    htab_pair_t *tmp = htab_find(t,key);

    size_t index = htab_hash_function(key) % t->arr_size;
    if(tmp == NULL){
        if(t->items_array[index]== NULL){

            htab_ptr_t *new= malloc(sizeof(htab_ptr_t)* strlen(key));
            htab_key_t key2 = malloc(sizeof(htab_key_t*));
            t->items_array[index]=new;
            t->items_array[index]->pair = malloc(sizeof(htab_pair_t));
            t->items_array[index]->pair->key=key2;
            t->items_array[index]->pair->key=key;
            t->items_array[index]->next = NULL;
            t->size++;
            t->items_array[index]->pair->value=0;
            return t->items_array[index]->pair;
        }
        else{
            htab_ptr_t *tmp1 = t->items_array[index]->next;
            while(tmp1){
                tmp1=tmp1->next;
            }
            htab_ptr_t *new= malloc(sizeof(htab_ptr_t));
            htab_key_t key2 = malloc(sizeof(htab_key_t)* strlen(key));
            tmp1=new;
            tmp1->pair= malloc(sizeof(htab_pair_t));
            tmp1->pair->key=key2;
            tmp1->pair->key=key;
            tmp1->next= NULL;
            tmp1->pair->value=0;
            t->size++;
            return tmp1->pair;
        }
    }
    else{
        return tmp;
    }
}
