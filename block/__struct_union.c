//
//  __struct_union.c
//  block
//
//  Created by 王望 on 17/1/10.
//  Copyright © 2017年 Will. All rights reserved.
//

#include "__struct_union.h"

#if 0
struct {
    int   a;
    char  b;
    float c;
} x;
//如果声明了两个结构体，不管这两个的结构体成员变量是否一样，他们两个仍然是不同的类型。但是我们可以使用一个标签来为相同的成员列表提供一个名字。


struct SAMETAG {
    int   a;
    char  b;
    float c;
};

struct SAMETAG value1;
struct SAMETAG value2;

typedef struct{
    int   a;
    char  b;
    float c;
} TypedefWholeStruct;//TYPEDEF_STRUCT是类型名称而不是一个结构体的标签。

TypedefWholeStruct value5;
TypedefWholeStruct value6 ;

struct COMPlex{
    float            f;
    int              a[20];
    long             *lp;
    TypedefWholeStruct tf[10];
    struct           SAMETAG  s;
    struct           SAMETAG  sa[10];
    struct           SAMETAG  *sp;
};//结构体的成员可以是标量，数组，指针，或者其他的结构体
//结构变量的成员是通过点操作符(.)访问的。

struct Link_List{
    int age;
    float weight;
    struct Link_List *next;
};

void struct_dot(void){
    struct COMPlex *p;
    struct COMPlex complex;
    
    printf("%p,%f,%d,%d\n",complex.a,p->f,*(p -> a),(*p).s.a);
}
#endif



typedef struct{
    short b[2];
    int a;
}EX2;


typedef struct EX{
    int a;
    char b[3];
    EX2 c;
    struct EX *d;
} EX;


void __struct_point_mem(void){
    
    EX2 ex2 = {{5,2},20};
    EX ex = {10,"HI",ex2,0};
    EX *px = &ex;
    
    printf("px is %p\n",px);//结构ex在内存中的地址
    
    printf("px is %d, the other is %d\n",px -> a,(*px).a);//px指向的结构ex的成员a的值。
    
    int *pa = &px->a;
    printf("ex成员a的地址是 %p，ex的首地址是 %p, pa is %d\n",pa,px,*pa);
    
    printf("px->b is %p , b成员的第二个元素 %c\n",px->b,px->b[1]);//px->b为一个数组名字，单独使用数组名为一个指向数组的首地址指针。下标操作符的算术优先级小于->操作符
    
    //嵌套结构
    //px->c.b[2] = *(px->c.b + 1)
    printf("ex成员变量c结构的成员b的第二个元素是 is %d，第一个元素是 %d\n",*(px->c.b + 1),*px->c.b);
    
    EX y;
    ex.d = &y;//因为在上面没有给ex的d成员变量赋一个有意义的值，所以这个新建一个结构y，让ex的d成员指针指向y的地址。这个链表的next指针指向下一个结构一样。
    printf("px is %p\n",px);
#if 0
    (*ex.d).a;//ex.d是一个指针，通过间接操作符获取这个指针指向的结构，然后取得这个结构的a成员变量。
    (*px->d).a;//px->d是通过->操作符获取的d成员，后面的操作和上面一样。
    px->d->a;//px->d取得d成员，这时候d和px一样是一个指向结构的指针，所以可以继续使用->操作符获取结构成员a
    ex.d->a;//和第三个类似，只是和第三个获取指针的方式不同而已
    (*px->d).a;//这个操作和第二个类似
    
    //可以使用sizeof操作符得到一个结构的长度，其中包括了边界对齐而跳过的字节。
    //4,3,8
    printf("ex is %lu\n",sizeof(ex));
    printf("ex address is %p,%p\n",px,&ex);
    printf("a is %p,b is %p,c is %p,d is %p\n",&px->a,px->b,&px->c,&px->d);
    printf("a length is %ld\n",(char *)px->b - (char *)&px->a);
    printf("b length is %ld\n",(char *)&px->c - (char *)&px->b);
    printf("c length is %ld\n",(char *)&px->d - (char *)&px->c);
    printf("d length is %ld\n",sizeof(px->d));
    printf("c.a length is %ld\n",sizeof(px->c.a));
    printf("c.b length is %ld\n",sizeof(px->c.b));
    printf("__offsetof %lu,%lu,%lu,%lu",__offsetof(EX, a),__offsetof(EX, b),__offsetof(EX, c),__offsetof(EX, d));
    
    int get_struct_sum(EX2 const *px);
    EX2 *px2 = &ex2;
    printf("get_struct_sum %d\n",get_struct_sum(px2));
    
#endif
    
    _struct_practice();
    
}
//这里不使用结构作为函数参数而是使用结构指针作为参数：是因为相对于整个结构，结构指针在函数调用时候被拷贝时不管是时间还是空间上都有优势，把拷贝压到栈上的效率也会提高很多。而且这里还可以使用之前提到的`register`关键字，让堆栈中的参数复制到寄存器上以获得更快的速度。
//使用const是为了防止在函数内部对调用程序的结构变量进行修改。
int get_struct_sum(EX2 const *px){
    
    int sum = px->a;
    for (int index = 0; index < sizeof(px->b)/sizeof(px->b[0]); index++) {
        sum += px->b[index];
    }
    //px->a = 10;不允许类似的操作发生，所以我在px指针前面添加了一个const
    return sum;
}


void _struct_practice(void){
    typedef struct NODE{
        int a;
        struct NODE *b;
        struct NODE *c;
    }NODE;
    
    NODE nodes[5] = {
        {5  , nodes + 3, NULL},
        {15 , nodes + 4, nodes + 3},
        {22 , NULL     ,  nodes + 4},
        {12 , nodes + 1, nodes},
        {18 , nodes + 2, nodes + 1}
    };
    
    NODE *np = nodes + 2;
    NODE **npp = &(nodes[1].b);//保存b的地址
    
    printf("1. nodes is %p\n",nodes);//nodes数组的地址
    printf("2.&nodes[3].c->a is %p\n",&nodes[3].c->a);//第四个元素结构变量的成员c结构指针指向的结构变量成员a，并取得地址
    //printf("3.nodes.a %d\n",nodes.a);//因为nodes不是一个结构变量所以不能去取得a成员，可以修改为(*nodes).a
    printf("4.&nodes->a is %p\n",&nodes -> a);//取得第一个数组元素结构变量的成员a的地址
    printf("5.nodes[3].a is %d\n",nodes[3].a);//取得第四个元素结构变量成员a的值，12
    printf("6.np is %p\n",np);//一个地址，数组nodes第二个元素的内存地址
    printf("7.nodes[3].c is %p\n",nodes[3].c);//地址
    printf("8.np -> a is %d\n",np->a);//第二个元素结构变量a成员的值
    printf("9.nodes[3].c->a is %d\n",nodes[3].c->a);//取值
    printf("10.np->c->c->a is %d\n",np->c->c->a);//12
    //printf("11.*nodes is %p\n",*nodes);//返回数组第一个子结构变量
    printf("12. npp is %p\n",npp);//保存第二个元素成员b的地址
    //printf("13. *nodes.a is %d\n",*nodes).a); 这是一个错误的表达式，因为.运算符比*运算符高，所以要先算.运算符，但是nodes表示的是一个地址不是结构变量，不能使用点运算符。可以加一个括号(*nodes).a
    printf("14. (*nodes).a is %d\n",(*nodes).a);//为上一个错误表达式的正确表达式
    
    //printf("15. npp -> a is %d\n",npp -> a);//保存b的地址，不是结构变量，可以使用(*npp)->a，通过间接运算符取得这个结构变量
    printf("16.(*npp)->a is %d\n",(*npp)->a);
    
    printf("17 nodes->a is %d.\n",nodes->a);//nodes是一个指向第一个结构变量的指针，获取第一个结构变量的成员a
    printf("18.nodes[3].b->b is %p\n",nodes[3].b->b);
    //printf("19.*nodes[3].b->b is %p\n",*nodes[3].b->b);一个struct
    printf("19 &np->c->c->a is %p.\n",&np->c->c->a);
}






