//
//  __malloc_memory.c
//  block
//
//  Created by 王望 on 17/1/11.
//  Copyright © 2017年 Will. All rights reserved.
//

#include "__malloc_memory.h"

void malloc_free(void);

void _malloc_case_1(void);

void _malloc_main(void){
    
    _malloc_case_1();
}

void malloc_free(void){
    int *pi;
    
    //pi = malloc(100);//在整型为4个字节的机器上，100是可以存储25个整数数据，因为pi指针是整型。malloc(25 * sizeof(int))
    //pi = MALLOC(25, int);
    
    
    pi = malloc(25 * sizeof(int));
    
    int *pt = realloc(pi, 20 * sizeof(int));
    if (!pt) {
        return;
    }
    
    pt = pi;

    printf("pi is %p,pt is %p\n",pi,pt);
    free(pt);
    
    
}

//常见的动态内存错误
//1.对NULL指针进行解引用操作。
//2.对分配的内存进行操作时越过边界。
//3.释放并非动态分配的内存。
//4.试图释放一块动态分配内存的一部分。
//5.一块动态内存被释放之后被继续使用。

//数组被声明时，必须要在编译时知道它的长度。动态内存分配允许程序为一个长度在运行时才知道的数组分配内存空间。

//在堆栈上分配内存，主要的优点是，当分配内存的函数返回时，这块内存会被自动释放。这个属性是由于堆栈的工作方式决定的，它可以保证不会出现内存泄漏。但是这种做法存在去诶单，由于当函数返回时被分配的内存消失，所以它不能用于存储那些传给调用程序的数据。

//

void _malloc_case_1(void){

    int *arrays;
    int n_values;
    int i;
    
    printf("How many values are there?\n");
    if (scanf("%d",&n_values) != 1 || n_values <= 0) {
        
        exit(EXIT_FAILURE);
    }
    
    arrays = malloc(n_values * sizeof(int));
    
    for (i = 0; i < n_values; i++) {
        if (scanf("%d",arrays + i) != 1) {
            free(arrays);
            exit(EXIT_FAILURE);
        }
    }
    //操作，排序，自己穿入一个需要的排序方式
    int compare_intergers(const void *lhs,const void *rhs);
    qsort(arrays, n_values, sizeof(int), compare_intergers);
    for (i = 0; i < n_values; i++) {
        printf("%d\n",*(arrays+i));
    }
    free(arrays);
};

int compare_intergers(const void *lhs,const void *rhs){
    
    const int *lhs_int = lhs;
    const int *rhs_int = rhs;
    
    return *lhs_int > *rhs_int ? 1 : (*lhs_int < *rhs_int ? -1 : 0);
}


