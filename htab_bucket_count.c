//
// Created by matko on 9. 4. 2022.
//
#include "private.h"
size_t htab_bucket_count(const htab_t *target_table){
    return target_table->arr_size;
}
