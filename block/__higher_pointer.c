//
//  __higher_pointer.c
//  block
//
//  Created by 王望 on 17/1/13.
//  Copyright © 2017年 Will. All rights reserved.
//

#include "__higher_pointer.h"

void _pointer_pointer(void);

void _higher_declaration(void);

void __higher_pointer_main(void){
    
    printf("%c\n",*"xyz");//对一指针执行间接访问操作，取得首地址对应的值。
    printf("%c\n", *("xyz" + 1));//指针值加1，也就是说这个指针向后偏移一个，指向字符串常量的第二个字符串
    printf("%c,%c\n","xyz"[2],*("xyz" + 2));
}

void _pointer_pointer(void){
    int i = 'a';
    int *pi;
    int **ppi;
    
    i = 5;
    pi = &i;
    ppi = &pi;
    
    printf("%p\n",&i);
    printf("%p\n",&pi);
    printf("%p\n",&ppi);
    printf("%p\n",ppi);
    
    
    //*ppi = 5;//在指针变量没有被初始化之前是不可以进行间接操作的。
    
    printf("%p",*ppi);
    
    *ppi = &i;//对pi进行初始化。
}

int function_pointer(int value){
    return value;
}

void _higher_declaration(void){
    
    
    //int array[3];
    //int *a_p = array;
    /**
    int (*a_p)(int) = &function_pointer;
    
    int result_1 = function_pointer(5);
    
    int result_2 = (*a_p)(25);
    
    int result_3 = a_p(25);
     */
    _get_next(5, function_pointer);
    
    int out_value = 10;
    
    //与普通的C函数定义不同，块可以使用其上文中定义的变量
    void (^testblock)(int value) = ^(int value){
        
        printf("%d,%d\n",value,out_value);
    };
    testblock(5);
    
    int *b;
    //...
    int **a;
    a = &b;
}

int _get_next(int value,int (*compare)(int value)){
    return compare(value) + 1;
}

int _get_next_for_block(int value, int(^compare)(int value)){
    return 1;
}


int f_a[];

int (*f_b)();//函数指针，意思指针f_b指向的函数返回一个整数值，程序中每个函数都位于内存中的某个位置；

//这里不要把指针数组和数组指针搞混乱了
//指针数组：元素都是指针的数组
//数组指针：一个指向数组的指针
int (*f_c[])();//数组f_c的元素是函数指针。

int *(*f_d[])();//f_d是一个指针数组，数组元素指针指向的函数其返回值类型是整型指针。






//当一个字符串常量出现于表达式中时，它的值是个指针常量。编译器把这些指定字符的一份拷贝存储在内存的某个位置，并存储一个指向第一个字符的指针。
