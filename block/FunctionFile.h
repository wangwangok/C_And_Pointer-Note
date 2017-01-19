//
//  FunctionFile.h
//  block
//
//  Created by 王望 on 17/1/6.
//  Copyright © 2017年 Will. All rights reserved.
//

#ifndef FunctionFile_h
#define FunctionFile_h

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include <ctype.h>
#include "__struct_union.h"
#include "__malloc_memory.h"
#include "__alloc.h"
#include "__struct_point.h"
#include "__higher_pointer.h"
#include "__preprocessor.h"
#include "_IO_FUNCTION.h"
//使用原型最方便的方法是把原型放在一个单独的文件中，当其他源文件需要这个函数的原型的时候，就是用`#include`指令包涵该文件。

//C函数的所有参数都是“传值调用”的方式进行传递，意思就是说函数将获得参数值的一份拷贝

//如果被传递的参数是一个数组名，并且在函数中使用下标的方式来获得该数组的元素，那么在函数中对数组元素进行修改实际上修改的是调用程序中的数组元素，__数组并不会复__制，这个称为__“传址调用”__。

int read_colunm_numbers(int columns[], int max);

void rearrange(char *output, char const *input,int n_columns, int const columns[]);

void print_linenumber(void);

int count_one_bites(unsigned int value);

char *find_char(char const *source,char const *chars);

int del_substr(char *str, char const *substr);

int even_parity(int value,int n_bits);

//可变参数列表是通过宏来实现的，这些宏定义在`stdarg.h`头文件中。这个头文件声明来一个类型`va_list`和三个宏:`va_start`,`va_arg`,`va_end`
float average(int n_values,...);

int hermite(int n,int x);

char * ascii_to_interger(char *string);

void str_cpy(char *buffer,char const *string);

void array_practice(void);

#endif /* FunctionFile_h */
