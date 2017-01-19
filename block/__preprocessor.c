//
//  __preprocessor.c
//  block
//
//  Created by 王望 on 17/1/16.
//  Copyright © 2017年 Will. All rights reserved.
//

#include "__preprocessor.h"
/**
 C预处理器：
 它的主要任务包括删除注释，插入被`#include`指令包含的文件内容、定义和替换`#define`指令定义的符号以及确定代码的部分内容是否应该根据一些条件编译指令进行编译。
 */

#define DEBUG 1
#define RELEASE 0

#if DEBUG



#endif
/**
#define name(parameter-list) stuff
有了这条指令后，每当有符号`name`出现在这条指令后面时，预处理器就会把把它替换为`stuff`。其中参数列表的左括号必须与`name`相邻，如果两者之间存在空白，则会被解释为`stuff`的一部分。
当宏被调用时，名字后面是一个逗号分隔的值的列表，每个值都与宏定义中的一个参数相对应，整个参数列表用一个括号包围。当参数出现在程序中时，与每个参数对应的实际值都被替换到`stuff`的一部分。
 
1.在调用宏时，首先对参数进行检查，看看是否包含了任何`#define`定义的符号。如果是，他们首先被替换。
2.替换文本随后被插入到程序中原来文件的位置。对于宏，参数名称被它们的值替代。
通过上面描述，宏参数和`#define`定义可以包含其它`#define`定义的符号。但是，__宏不可以出现递归__。

 
*/

#define SQUARE(x) x*x

#define repeat  do
#define until(x) while( !(x))

///预处理器并不会对字符串常量进行检查，如果你想把参数插入到字符串常量中有两种技巧：
///邻近字符串自动连接的特性使得可以把一个字符串分成几段，每段实际上都是一个宏参数。
#define PRINT(FORMAT,VALUE) printf("the value is "FORMAT"\n", VALUE );

///预处理器把一个宏参数转换为一个字符串。`#argument`这种结构被预处理器翻译为"argument"。
#define Print(FORMAT,VALUE) printf("the value of #VALUE is " FORMAT"\n", VALUE );

//宏想对函数，函数的参数必须声明为一种特定的类型，所以只能在类型合适的表达式上使用。但是宏的参数可以是各种类型，整型，长整型，单浮点数等等，因为宏是与类型无关的只是一个替换而已。

#undef repeat

void _preprocessor_main(void){
    
    
    
    printf("%s\n",__FILE__);
    printf("%d\n",__LINE__);
    printf("%s\n",__DATE__);
    printf("%s\n",__TIME__);
    printf("%d\n",__STDC__);
    
    int a = 5;
    printf("SQUARE is %d\n",SQUARE(a + 1));//SQUARE is 11
    PRINT("%d", a);
    Print("%d", a);
    
    
}
/**
| 符号 | 样例值 | 含义 |
| ---- | ---- | ---- |
| __FILE__ | "__preprocessor.c" | 进行编译的源文件名 |
| __LINE__ | 27  | 表示文件当前行的行号 |
| __DATE__ | "Jan 16 2017" | 文件在被编译时的年月日 |
| __TIME__ | "15:51:46" | 文件在被编译时的具体时间 |
| __STDC__ | 1 | 如果编译器遵循ANSI C，其值为1，否则未定义 |
 */



///MARK: - 条件编译 -
/**
 如果我们可以选择某语句或者某组语句进行翻译或者被忽略，我们就可以使用条件编译。
 用于调试程序的语句就是一个很好的例子，它们不应该出现在程序的产品版本中，但是又不想把这些语句从源代码中删除。
 #if constant-expression
 statements
 #endif
 constant-expression（常量表达式）由预处理器进行求值。如果它的值是非零值，那么statements被编译，否则预处理器久会删除它们。
 */
//条件编译的另一个用途是在编译时选择不同的代码部分。为了支持这个功能，`#if`指令还具有可选的`#elif`(相当于if语句中的else if)和`#else`，语法表达式如下：
/**
#if condition
    //statements
#elif condition
    //statements
#else
    //statements
#endif
*/



//测试一个符号是否已经被定义了，可以使用下面两种方式
/**
#if defined(symbol)
#ifdef symbol
3
#if !defined(symbol)
#ifndef symbol
 一个C程序从源代码到程序执行，需要经过翻译和执行两个节点，翻译节点又分为编译和链接（将目标文件链接成可执行文件），其中编译分为预处理和源代码解析。这里讲到的都是发生在编译的预处理阶段的。
 避免用`#define`指令定义可以用函数实现的很长的序列的代码。
 在对表达式求值的宏中，每个宏参数出现的地方都应该加上括号，并且整个宏定义的两边也加上括号。
 
*/





