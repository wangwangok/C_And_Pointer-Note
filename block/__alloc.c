//
//  __alloc.c
//  block
//
//  Created by 王望 on 17/1/12.
//  Copyright © 2017年 Will. All rights reserved.
//

#include "__alloc.h"

#undef malloc
void *alloc(size_t size){
    void *new_mem;
    new_mem = malloc(size);
    if (new_mem == NULL) {
        exit(1);
    }
    return new_mem;
}

