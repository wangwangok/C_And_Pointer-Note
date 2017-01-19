//
//  _IO_FUNCTION.c
//  block
//
//  Created by 王望 on 17/1/17.
//  Copyright © 2017年 Will. All rights reserved.
//

#include "_IO_FUNCTION.h"
#include <ctype.h>

int const MAX_LINE_LENGTH = 1024;

typedef struct VALUE {
    long a;
    float b;
    char c;
} IO_VALUE;

int const ARRAY_SIZE = 5;

void _io_func_main(void){
    
    printf("someting or other\n");
    fflush(stdout);
    
    //fopen(<#const char *restrict __filename#>, <#const char *restrict __mode#>);
    //fclose(<#FILE *#>);
    
    
    FILE *file = fopen("FILE", "r+");
    if (file == NULL) {
        perror("con't find file ,exit");
        exit(EXIT_SUCCESS);
    }
    /**
     //fclose(<#FILE *#>)
     int result = fclose(file);
     if (result != 0) {
     perror("fclose failed");
     }
     */
    
    /**
    int ch;
    int value = 0;
    while ((ch = getchar()) != EOF && isdigit(value)) {
        value *= 10;
        value += ch - '0';
    }
    ungetc(ch, stdin);
    //ungetc(<#int#>, <#FILE *#>)
     */
    //putchar('abc');
    //gets和puts相关的函数用于操作字符串而不是单个字符，这使得它们在处理一行行文本输入的程序中很有用，相关函数：
    //fputs(<#const char *restrict#>, <#FILE *restrict#>)
    //puts(<#const char *#>)
    
    FILE *copy_file = fopen("copy_file", "a+");
    
    char buffer[MAX_LINE_LENGTH];
    while (fgets(buffer, MAX_LINE_LENGTH, file) != NULL) {
        fputs(buffer, copy_file);
    }
    //scanf(<#const char *restrict, ...#>)
    //sscanf(<#const char *restrict#>, <#const char *restrict, ...#>)

    //int fprintf(FILE * __restrict, const char * __restrict, ...)
    //int printf(const char * __restrict, ...)
    //int sprintf(char *buffer, char const *format, ...);
    //sprintf用于输出的缓冲区的大小sprintf并不知道，所以如果输出结果很长溢出缓冲区时，就可能改写缓冲区后面内存中的数据。但是可以查看可能出现的值被转换后的结果出书将有多长。
    ///
    char s_buffer[10];
    sprintf(s_buffer, "%5s",s_buffer);
    
    printf("%c\n",97);//a
    printf("%5d,%i\n",100,101);//  100,101
    printf("%u,%d\n",-10,-10);//4294967286,-10，其中4294967286转换为二进制为－10的补码的形式，在这台机器上int型占4个字节，所以算补码的时候33位减去200的二进制码。
    printf("%.3e\n",6.023000e23);//6.023e+23
    printf("%f,%.2f\n",6.023805482085420,6.023805482085420);//6.023805,6.02 精度缺省值6
    printf("%.2g\n",2.333333e-6);//2.33333e-06
    printf("%g\n",2.333333e-3);//0.00233333
    char *str = "printf";
    printf("%s,%p\n",str,str);//printf,0x100002f0d
    int i = 0;
    void *v_p = &i;
    printf("%p\n",v_p);//0x7fff5fbff344
    
    //size_t	 fread(void * __restrict __ptr, size_t __size, size_t __nitems, FILE * __restrict __stream);
    //size_t	 fwrite(const void * __restrict __ptr, size_t __size, size_t __nitems, FILE * __restrict __stream) ;
    IO_VALUE values[ARRAY_SIZE];
    size_t number_values = fread(values, sizeof(IO_VALUE), ARRAY_SIZE, file);
    fwrite(values, sizeof(IO_VALUE), number_values, copy_file);
    
    ///rewind(<#FILE *#>)
    ///fgetpos(<#FILE *restrict#>, <#fpos_t *#>)
    ///fsetpos(<#FILE *#>, <#const fpos_t *#>)
    
    
    //exit(EXIT_SUCCESS);
}
///##错误报告
///perror函数的原型：
///void	 perror(const char *);
///如果这个字符指针不是`NULL`并且指向一个非空字符串，该函数就打印出这个字符串，和用于解释errno当前错误代码的信息

///##终止执行
///exit函数的原型：
///```
///void exit(int);
///```
///将exit函数的参数返回给操作系统，用于提示程序是否正常完成。经常会在调用`perror`函数之后再调用`exit`终止程序。

///##I/O函数库
///对于C程序而言，所有的I/O操作只是简单的从程序移进或者移出字节的事情，这种字节称为__流__。
///绝大多数流是完全缓冲的，这说明“读取”和“写入”实际上是从一块被称为缓冲区的内存区域来回复制数据。从内存中来回复制数据是很快的。__用于输出流的缓冲区只有把它写满时才会被刷新到设备或者文件中__。一次性把写满的缓冲区写入和逐片把程序产生的输出分别写入相比较效率更高。输入缓冲区当她为空时通过从设备或文件读取下一块较大的输入，重新填充缓冲区。
///因为编译器的不同，一个常见的策略是把标准输出和标准输入联系在一起，当请求输入时同时刷新输出缓冲区。
///当在程序中使用很多`printf`函数的时候，__这些函数调用的输出结果被写入到缓冲区，并不立即显示在屏幕上__，如果程序失败，缓冲输出可能不会被实际写入，解决这个问题的办法就是每个用于__调试的printf函数之后立即调用`fflush`__：
///```
///printf("someting or other");
///fflush(stdout);
///```
///__其中`fflush`函数迫使缓冲区的数据立即写入，不管它是否已满__。
///在MS-DOS中，文本文件约定以一个回车符和一个换行符结尾，在UNIX中只使用一个换行符结尾。
///
///二进制流中的字节将完全根据程序编写它们的形式写入到文件或者设备中，而且完全根据它们从文件或设备读取的形式读入到程序中。


///文件
///`stdio.h`中包含了一个`FILE`结构，不要把`FILE`和磁盘上的数据文件混淆，__`FILE`是一个数据结构，用于访问一个流__。如果同时激活了几个流，每个流都有一个对应的`FILE`与它关联。为了在流上执行一些操作，你调用一些合适的函数，并向他们传递一个与这个流关联的`FILE`参数。
///运行时系统提供了三个流－－标准输入(stdin)、标准输出(stdout)和标准错误(stderr)，它们都是一个指向`FILE`结构的指针。


///流I/O
///关于文件I/O的一些概括
///* 1.程序为必需同时处于活动状态的每个文件声明一个指针变量，类型为`FILE *`，这个指针指向`FILE`结构，当它处于活动状态是由流使用；
///* 2.__流通过调用`fopen`函数打开__。必需指定需要访问的文件或设备以及它们的访问方式（读，写，读写）。`fopen`会向操作系统确认文件是否存在（有些操作系统还要验证是否允许执行在fopen中指定的访问方式），如果存在则初始化`FILE`结构；
///`fopen`函数原型
///```
///FILE *fopen(const char * __restrict __filename, const char * __restrict __mode);
///```
///* 3.根据制定的方式对该文件进行读取或者写入；
///* 4.调用`fclose`函数。关闭一个流可以防止与它相关联的文件被再次访问，保证任何存储于缓冲区的数据被正确的写入到文件中，并且释放`FILE`结构。
///`fclose`函数原型
///```
///int  fclose(FILE *);
///```
///I/O函数以三种基本的形式处理数据：单个字符、文本行和二进制数据。
///
/**
 | 数据类型 | 输入 | 输出 | 描述 |
 | :---- :| :----: | :----: | ---- |
 | 字符 | ___getchar___ | ___putchar___ | 读取（写入）单个字符 |
 | 文本行 | ___gets___,___scanf___ | ___puts___,___printf___ | 第一种(get,puts)是文本行格式化输入和输出，第二种（scanf,printf）是格式化输入输出 |
 | 二进制数据 | ___fread___ | ___fwrite___ | 读取（写入）二进制数据 |
 */
///只用于stdin或stdout，作为参数的流使用，使用内存中的字符而不是流。
/**
 | 函数家族名 | 目的 | 只用于stdin和stdout(1) | 可用于所有的流(2) | 内存中的字符(3) |
 | :---- :| :----: | :----: | ---- |
 | ___getchar___ | 字符输入 | getchar | fgetc,getc | 方式一 |
 | ___putchar___ | 字符输出 | putchar | fputc,putc | 方式一 |
 | ___gets___ | 文本输入 | gets | fgets | 方式二 |
 | ___puts___ | 文本输出 | puts | fputs | 方式二 |
 | ___scanf___ | 格式化输入 | scanf | fscanf | sscanf |
 | ___printf___ | 格式化输出 | print | fprintf | sprintf |
 */
///方式一：对指针使用下标引用或者间接操作符从内存获得一个字符（或向内存写入一个字符）
///方式二：使用`strcpy`函数从内存读取文本行（或向内存写入文本行）
///



///##打开流
///`fopen`函数打开一个特定的文件，并把一个流和这个文件相关联，原型：
///```
///FILE	*fopen(const char * __restrict __filename, const char * __restrict __mode);
///```
///两个参数都是字符串，`__filename`是需要打开的文件或者设备的名字。而返回值`FILE *`并不影响哪个文件被打开。`__mode`参数提示流是用于只读，只写还是读写都可以。
/**
 | 数据类型 | 读取 | 写入 | 添加 |
 | :---- :| :----: | :----: | ---- |
 | 文本 | "r" | "w" | "a" |
 | 二进制数据 | "rb" | "wb" | "ab" |
 */
///如果一个文件被打开是用于读取的，那么它必须是原先已经存在的;
///如果一个文件打开是用于写入的，如果它原先已经存在，__那么它原来的内容就会被删除__，如果它原先不存在，那么就创建一个新文件;
///如果一个文件使用添加的，如果添加的文件不存在，那么将会被创建。如果它原先已经存在，__它原先的内容并不会被删除__;
///无论在哪一种情况下，__数据只能从文件的尾部写入__。
///
///在上面的各个mode中后面添加一个加号，比如："r+","w+","a+"打开的这个文件都是可以读写的，并执行相关操作。但是如果已经从该文件读入了一些数据，在开始写数据之前，必须调用其中一个文件定位函数(`fseek`,`fsetpos`,`rewind`)。如果已经写入一些数据之后，又想从该文件读取一些数据，首先必须要调用`fflush`函数或者文件定位函数之一。


///##关闭流
///关闭流使用`fclose`函数，其原型：
///```
///int  fclose(FILE *);
///```
///对于输出流，`fclose`函数在文件关闭之前刷新缓冲区。如果它执行成功，`fclose`返回0，否则返回EOF。
///



///##字符I/O
///当一个流被打开以后（假设是可以读写的），它可以用于输入和输出。最简单的形式是字符I/O，字符输入是由`getchar`那一类（前面表格getchar函数家族）来执行的。原型如下：
///```
///int  fgetc(FILE *);
///int  getc(FILE *);
///int  getchar(void);
///```
///需要操作的流作为参数传递给`getc`和`fgetc`，但是`getchar`始终从标准输入读取。每个函数从流中读取下一个字符，并把它作为函数的返回值返回。如果流中不存在更多的字符，函数返回常量`EOF`。
///为了把单个字符写入到流中，你可以使用`putchar`相关的函数，它们的原型：
///```
///int  fputc(int, FILE *);
///int  putc(int, FILE *);
///int  putchar(int);
///```
///第一个参数是要被打印的字符。在打印之前，函数把这个整数参数裁剪为一个无符号字符整值，所以：
///```
///putchar('abc');//我的机器上打印c
///```
///只打印一个字符。

///######撤销字符I/O
///假定你必须从一个流中逐个读入一串数字，由于实际读入之前，你无法知道下一个字符，你必须连续读取，直到读入一个非数字字符，但是并不希望丢弃这个字符。这时候我们就可以使用函数`ungetc`;
///`ungetc`把一个__先前读入的字符返回到流中，这样它可以在以后被重新读入__。其函数原型：
///```
///int  ungetc(int, FILE *);
///```
///每个流都允许至少一个字符被退回。如果一个流允许退回多个字符，那么这些字符再次被读取的顺序就以退回时的反序进行。

///##未格式化的行I/O


/**
| 格式码 | h | l | L |
| :---- :| :----: | :----: | :----: |
| d,i,n | short | long |  |
| o,u,x | unsigned short | unsigned long |  |
| c,f,g |  | double |long double |
*/




/**
 | 代码 | 参数 | 含义 |
 | :----:| :----: | :----: |
 | c       | int          | 参数被裁减为unsigned char类型并作为字符进行打印 |
 | d i     | int          | 参数作为一个十进制整数打印，如果给出了精度而且值的位数小于精度位数，前面就用0填充 |
 | u o x,X | unsigned int | 无符号整型，u使用十进制，o使用八进制，x或X使用十六进制，区别在于x约定使用abcdef，而X约定使用ABCDEF |
 | e E     | double       | 指数形式打印，小数点后面的位数由精度字段决定，缺省值是6 |
 | f       | double       | 浮点数，精度字段决定小数点后面的位数，缺省值同样是6 |
 | g G     | double       | 以%f或者%e表示（G则对应大写），如果指数大于等于－4但是小于精度字段就使用%f，否则使用指数形式 |
 | s       | char*        | 字符串 |
 | p       | void*        | 打印指针指向的地址吧 |
 | n       | int*         | 不产生任何输出，到目前为止函数所产生的输出字符数目将被保存到对应的参数中 |
 */


///把数据写到文件效率最高的方法是用二进制形式写入。二进制输出避免了在数值转换为字符串过程中所涉及的开销和精度损失。
///`fread`函数读取二进制数据，`fwrite`函数写入二进制数据。原型：
///```
///size_t	 fread(void * __restrict __ptr, size_t __size, size_t __nitems, FILE * __restrict __stream);
///size_t	 fwrite(const void * __restrict __ptr, size_t __size, size_t __nitems, FILE * __restrict __stream) ;
///```
///第一个参数是一个指向用于保存数据的内存位置的指针，第二个参数是缓冲区每个元素的字节数，第三个参数是读取或写入的元素数，最后一个参数是数据读取或写入的流。


///fseek函数允许你在一个流中定位，这个操作将改变下一个读取或写入操作的位置。第一个参数是需要改变的源，对于第二个和第三个参数标识文件中需要定位的位置，参数具体的参数可以看下表：
/**
 | 第三个参数 | 不同参数的定位地址 |
 | :---- :| :----: |
 | __SEEK_SET__ | 从流的起始位置起offset个字节，offset必须是一个非负值 |
 | __SEEK_CUR__ | 从流的当前位置起offset个字节，offset的值可正可负 |
 | __SEEK_END__ | 从流的尾部位置起offset个字节，offset的值可正可负，如果是正值就定位文件尾的后面 |
 */
///其中offset为第二个参数，之所以存在这些限制，部分原因是文本流所执行的行末字符映射。由于这种映射的存在，文本文件的字节数可能和程序写入的字节数不同。所以一个可移植的程序不能根据实际写入字符数的计算结果定位到文本流的一个位置。
///fseek改变一个流的位置会带来三个副作用
///* 1.行末指示符被清除
///* 2.如果在`fseek`之前使用`ungetc`把一个字符返回到流中，那么这个被退回的字符会被丢弃，因为在定位操作以后，他不在是“下一个字符”。
///* 3.定位后可以从写入模式切换到读取模式，或者回到打开的流以便更新。
///
///



///##改变缓冲方式
///在流上执行缓冲方式有时并不合适，下面两个函数可以用于对缓冲方式进行修改。__这两个函数只有当指定的流被打开但还没有在它上面执行任何操作前才能被调用__。
///```
///
///
///```
///
