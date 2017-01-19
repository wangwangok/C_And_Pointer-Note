//
//  main.c
//  block
//
//  Created by 王望 on 16/12/28.
//  Copyright © 2016年 Will. All rights reserved.
//


#include "FunctionFile.h"

#define MAX_INPUT 1000
#define MAX_COLS 20
#define N_VALUES_COUNT  5

enum C_Enum_Type{ C_Int = 2,C_Short = 4,C_Long = 6 };

//static const int b = 10;//这个声明为：声明另一个常量b的作用域为当前这个.c文件下面，static并不会改变b的存储类型。

size_t _strlen(char const *string){
    size_t length = 0;
    while (length++,*string++ != '\0')
        ;
    return length - 1;
}
//这个数组的每个元素都是一个字符指针，数组的末尾是一个`NULL`指针。argc的值和这个`NULL`值都用于确定实际传递了多少参数。argv指向数组的第一个元素

//argc：它表示命令行参数的数目
//argv：一个指向数组的指针。由于参数的数目并没有内在的限制，所以argv指向这组参数值的第一个元素，
int main(int argc, const char * argv[]) {
    
    //cc -c -o main.c insert.c -o test
    int num = 0;
    int *ptr = &num;
    char str[] = "wangwang";
    char *s_ptr = str;
    char *message = "Hello world";
    
    printf("%p---%d---str is %p----%c\n",ptr,*ptr,s_ptr,str[0]);
    printf("%p--%c\n",message,*message);
    //enum C_Enum_Type int_type;
    //print_linenumber();

#if 0
    
    typedef char *TypeChar;
    TypeChar char_point;
    /*
    #define d_ptr_to_char char *
    d_ptr_to_char a,b;
    */
    printf("------------------------------------\n");
    int const int_const = 0;
    const int const_int = 0;
    printf("------------------------------------\n");
    
    
    //MARK: - const指针相关操作 -
    printf("------------------------------------\n");
    int itr[10];
    int *pi;
    int const *cpi;
    int * const pci;
    int const * const cpci;
    pi = itr;
    *pi = 10;
    cpi = itr;
    *pci = 20;
    printf("------------------------------------\n");
    
    
    
    //MARK: - 右移操作符 -
    printf("------------------------------------\n");
    int uint = 10; //00001010
    int sint = -10;//11110110
    printf("%d\n",uint >> 2);//00000010
    printf("%d\n",sint >> 2);//11111101
    //所以从这里看出来xcode编译器对于左移操作是算术移位
    printf("result is %d\n",count_one_bites(20));
    printf("------------------------------------\n");
    
    
    
    //MARK: - Static在代码块中的使用 -
    printf("------------------------------------\n");
    int (^static_int)(void) = ^{
        //代码块中，static定义的变量为静态变量，在程序运行前初始化，而且只初始化一次
        static int counter = 1;
        return ++counter;
    };
    printf("First static_int is %d\n",static_int() - static_int() * static_int());//-10
    printf("------------------------------------\n");
    
    
    
    //MARK: - 逗号运算符 -
    printf("------------------------------------\n");
    int (^f1)(int) = ^(int value){
        return value + 1;
    };
    int (^f2)(int) = ^(int value){
        return value + 2;
    };
    int (^f3)(int,int) = ^(int a,int b){
        return a + b;
    };
    int x,a,b,c;
    x = 0;
    
    while (a = f1(x),b = f2(x + a),c = f3(a,b),++x,c < 10) {
        printf("while statements c is:%d\n",c);
    }
    //现在，循环中用于获得下一个值的语句只需要出现一次，逗号操作符使源码更易于维护。
    /**
     a = f1(x);
     b = f2(x + a);
     for (c = f3(a,b); c < 10; c = f3(a,b)) {
     printf("while statements c is:%d\n",c);
     a = f1(++x);
     b = f2(x + a);
     }
     */
    printf("------------------------------------\n");
    
    
    
    //MARK: - 指针 -
    //变量标识符与内存位置之间的关联并不是硬件提供的，而是编译器为我们提供的，硬件仍然通过地址访问内存位置
    int   a = 112;
    int   *d;//d = &a;初始化时候使用&
    d = &a;
    printf("%d\n",a);
    *d = 120;
    printf("%d,%p,%d\n",a,d,*d);
    *&a = 140;//*d = 140
    printf("%d,%p,%d\n",a,d,*d);
    
    printf("------------------------------------\n");
    int (*(*c));
    c = &d;
    printf("string length %lu\n",_strlen("wangwang"));
    float values[N_VALUES_COUNT];
    float *cp;
    //数组在内存中存储是连续的
    for (cp = &values[0]; cp < &values[N_VALUES_COUNT];cp++) {
        *cp = 0;
    }
    printf("------------------------------------\n");
    
    
    
    
    
    printf("------------------------------------\n");
    printf("find_char :%s\n",find_char("ABCDEF", "BXRCQEF"));
    printf("del_substr %d\n",del_substr("ABCDEF", "CD"));
    printf("------------------------------------\n");
    
    
    
    
    
    printf("------------------------------------\n");
    printf("average is %f",average(1,2,3,4,5,6,7,8,9));
    printf("hermite is %d",hermite(3, 2));
    printf("------------------------------------\n");
    
    
    
    
    //MARK: - 数组指针 -
    printf("------------------------------------\n");
    //int array[] =  {1,2,3,4,5};
    //存储于静态内存的数组只初始化一次，当程序执行时，静态数组已经初始化完毕。如果数组没有被初始化，数组元素的初始值将会自动设置为0.
    //由于自动变量位于运行时堆栈，所以自动变量在缺省的情况下是未被初始化的。
    char *buffer = malloc(sizeof(char));
    char *string = "wangwang";
    str_cpy(buffer, string);
    printf("str_cpy string buffer is:%s\n",buffer);
    
    array_practice();
    printf("------------------------------------\n");
    
    
    
    
    //MARK: - 结构 -
    __struct_point_mem();
    
    
    
    //MARK: - 动态内存分配 -
    printf("------------------------------------\n");
    
    _malloc_main();
    
    printf("------------------------------------\n");
    
    
    //MARK: - 高级指针话题 -
    printf("------------------------------------\n");
    
    __higher_pointer_main();
    
    printf("------------------------------------\n");
    
    
    //MARK: - 预处理器 -
    _preprocessor_main();
    
    
#endif
    
    printf("------------------------------------\n");
    
    _io_func_main();
    
    printf("------------------------------------\n");
    printf("\n");
    return 0;
}


int matrixs[3][10];
//这里的关键在于编译器必须知道第二个及以后各维的长度才能对各下标进行求值，因此在原型中必须声明这个维的长度
void matrix(int (*mat)[10]);

int read_colunm_numbers(int columns[], int max){
    
    int num = 0;
    int ch;
    while (num < max && scanf("%d",&columns[num]) == 1 && columns[num] > 0) {
        num += 1;
    }
    
    if (num % 2 != 0) {
        puts("Last colum number is not paired.");
        exit(EXIT_FAILURE);
    }
    
    while ((ch = getchar()) != EOF && ch != '\n') {
        ;
    }
    return num;
}


void rearrange(char *output, char const *input,int n_columns, int const columns[]){
    
    int col;
    int output_col;
    int len;
#if 0
    int noway;
#endif
    len = (int)strlen(input);
    output_col = 0;
    
    for (col = 0; col < n_columns; col += 2) {
        int nchars = columns[col + 1] - columns[col] + 1;
        
        if (columns[col] >= len ||
            output_col == MAX_INPUT - 1) {
            break;
        }
        
        if (output_col + nchars > MAX_INPUT -1) {
            nchars = MAX_INPUT - output_col - 1;
        }
        
        strncpy(output + output_col, input + columns[col], nchars);
        output_col += nchars;
    }
    output[output_col] = '\0';
}

void print_linenumber(void){

    const int MAX_NUMS = 10;
    int  num = 0;
    char chs[19];
    int  line = 1;
    
    while (scanf("%s",&chs[num]) == 1 && num <= MAX_NUMS) {
        num += 1;
        printf("%d. %s\n",line,chs);
        line++;
        
    }
}

void enum_func(void){
    enum Liquid {OUNCE = 1,CUP = 8,PINT = 16};
    enum Liquid jar;
    jar = OUNCE;
    printf("%u\n",jar);
    jar = jar + PINT;
    printf("%u\n",jar);
}

int count_one_bites(unsigned int value){
    
    int ones;
    unsigned int result = value;
    for (ones = 0; result != 0; result = result >> 1) {
        printf("count_one_bites result is %d\n",result);
        if (result % 2 != 0) {
            ones += 1;
        }
    }
    return ones;
}

//这里source和chars为字符串的开始位置的地址
char *find_char(char const *source,char const *chars){
    if (source == NULL || chars == NULL) {
        return NULL;
    }
    char const *f_p = chars;
    do {
        do {
            if (*source == *chars) {
                char *result = (char *)source;
                char *cp;
                *cp = *result;
                return cp;
            }
        } while (*chars++ != '\0');
        chars = f_p;
    } while (*source++ != '\0');
    return NULL;
}


int del_substr(char *str, char const *substr){
    
    int flag = 0;
    //重置str指针的位置
    char *reset = str;
    //标记成功比较了几个字符
    int str_index = 0;
    size_t length = _strlen(str);
    /*
    for (;str_index = 0, *substr != '\0'; substr++) {
        printf("~~~substr~~%c\n",*substr);
        for (; *str != '\0'; str++,str_index++) {
            printf("~~~str~~%c\n",*str);
            if (str_index == length) {
                return flag;
            }else if(*substr == *str){
                str++;
                break;
            }
        }
    }
     */
    char *s_p;
    *s_p = *str;
    for (;str_index = 0, *substr != '\0'; substr++) {
        printf("~~~substr~~%c\n",*substr);
        for (; *str != '\0'; str++,str_index++) {
            printf("~~~str~~%c\n",*str);
            if(*substr == *str){
                str++;
                break;
            }else{
                *s_p++ = *str;
                //s_p++;
            }
        }
    }
    printf("++++s_p is %s +++++\n",s_p);
    return flag;
}

// 19 ,3
int even_parity(int value,int n_bits){
    int parity = 0;
    while (n_bits > 0) {
        parity += value & 1;
        value >>= 1;
        n_bits -= 1;
    }
    return parity % 2 == 0;
}


float average(int n_values,...){
    va_list var_arg;
    int count;
    float sum = 0;
    
    va_start(var_arg, n_values);
    for (count = 0; count < n_values; count += 1) {
        sum += va_arg(var_arg, int);
    }
    va_end(var_arg);
    return sum/n_values;
}

//在参数列表中至少要有一个命名参数
//命名参数制定了实际传递的参数数量，在程序中这些参数的类型被假定为整型。

//递归
int hermite(int n,int x){
    return n < 0 ? 0 : (n == 1 ? 2 * x : (2 * x * hermite(n - 1, x) - 2 * (n - 1) * hermite(n - 2, x)));
}

char * ascii_to_interger(char *string){
    
    if (string == NULL) {
        return 0;
    }
    
    char *interger = MALLOC(1, char);
    interger = string;
    while (interger++,*string++ != '\0') {
        if (*string > 57 || *string < 48) {
            *interger++ = '0';
        }else{
            *interger++ = *string;
        }
    }
    return interger;
}

//将string声明为constr的作用是：编译器可以捕捉到任何试图修改该数据的意外错误。
void str_cpy(char *buffer,char const *string){
    while ((*buffer++ = *string++) != '\0') {
        ;
    }
}


void array_practice(void){
    //169
    int ints[20] = {
        10,20,30,40,50,60,70,80,90,100,110,120,130,140,150,160,170,180,190,200
    };
    
    int *ip = ints + 3;
    //ints 为数组的首地址
    printf("1.ints %p\n",ints);
    //ip 为ints + 3和&ints[3]
    printf("2.ip is %p,ints + 3 is %p,&ints[3] is %p\n",ip,ints + 3,&ints[3]);
    //ints[4] = *(ip + 1),*(ints + 4)
    printf("3.ints[4] is %d,*(ip + 1) is %d,*(ints + 4) is %d\n",ints[4],*(ip + 1),*(ints + 4));
    //ip[4] = *(ip + 4),ints[7]
    printf("4.ip[4] is %d,*(ip + 4) is %d,ints[7] is %d\n",ip[4],*(ip + 4),ints[7]);
    //ints + 4 = ip + 1,&ints[4]
    printf("5.ints + 4 is %p,ip + 1 is %p,&ints[4] is %p\n",ints + 4,ip + 1,&ints[4]);
    //ip + 4 = ints + 7,&ints[7]
    printf("6.ip + 4 is %p,ints + 7 is %p,&ints[7] is %p\n",ip + 4,ints + 7,&ints[7]);
    //*ints + 4 = ints[0] + 4,*(ip - 2) + 4
    printf("7.*ints + 4 is %d,ints[0] + 4 is %d,*(ip - 3) + 4 is %d\n",*ints + 4,ints[0] + 4,*(ip - 3) + 4);
    //*ip + 4 = ints[3] + 4,*(ints + 3) + 4
    printf("8.*ip + 4 is %d,ints[3] + 4 is %d,*(ints + 3) + 4 is %d\n",*ip + 4,ints[3] + 4,*(ints + 3) + 4);
    //*(ints + 4) = ints[4],*(ip + 1)
    printf("9.*(ints + 4) is %d,ints[4] is %d,*(ip + 1) is %d\n",*(ints + 4),ints[4],*(ip + 1));
    //*(ip + 4) = *(ints + 7),ints[7]
    printf("10.*(ip + 4) is %d,*(ints + 7) is %d,ints[7] is %d\n",*(ip + 4),*(ints + 7),ints[7]);
    //ints[-2]表示的一个值，但是这个值已经不在数组ints的范围内了
    printf("11.ints[-2] %d\n",ints[-2]);
    //ip[-2] = *(ip + (-2)),ints[1],*(ints + 1)
    printf("12.ip[-2] is %d,*(ip + (-2)) is %d,ints[1] is %d ,,*(ints + 1) is %d\n",ip[-2],*(ip -2),ints[1],*(ints + 1));
    //&ints 获取这个数组的地址，而不是获取这个数组的首地址，应该和第一个数据是不同的。
    printf("13.&ints %p\n",&ints);
    //&ip 获取指针变量ip的地址
    printf("14.&ip %p\n",&ip);
    //&ints[4] = *(&ints + 4),ints[4]
    //printf("15.&ints[4] is %d,*(&ints + 4) is %d,ints[4] is %d\n",&ints[4],*(&ints + 4),ints[4]);
    //&ip[4] = *(&ip + 4)
    //printf("16.ints %p\n",ints);
    //printf("17.ints %p\n",ints);
    //printf("18.ints %p\n",ints);
    
    
}

//
