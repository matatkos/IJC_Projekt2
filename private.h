//
// Created by matko on 8. 4. 2022.
//
#ifndef __PRIVATE_H__
#define __PRIVATE_H__

#include "htab.h"

struct htab{
    size_t size;
    size_t arr_size;
    struct htab_ptr *items_array[];
};

typedef struct htab_ptr{
    htab_pair_t *pair;
    struct htab_ptr *next;
}htab_ptr_t;

#endif //__PRIVATE_H__