//
//  __alloc.h
//  block
//
//  Created by 王望 on 17/1/12.
//  Copyright © 2017年 Will. All rights reserved.
//

#ifndef __alloc_h
#define __alloc_h

#include <stdio.h>
#include <stdlib.h>

//#define malloc 不要直接调用malloc！

#define MALLOC(num,type) (type *)alloc( (num) * sizeof(type))

extern void *alloc(size_t size);


#endif /* __alloc_h */
