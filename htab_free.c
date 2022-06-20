//
// Created by matko on 12. 4. 2022.
//
#include "private.h"
#include "stdlib.h"
void htab_free(htab_t *table){
    htab_clear(table);
    free(table);
}
