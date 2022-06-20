//
// Created by matko on 8. 4. 2022.
//
#include "htab.h"
#include <inttypes.h>

size_t htab_hash_function(htab_key_t str){
    uint32_t h=0;     // musí mít 32 bitů
    htab_key_t p;
    for(p=str; *p!='\0'; p++)
        h = 65599*h + *p;
    return h;
}