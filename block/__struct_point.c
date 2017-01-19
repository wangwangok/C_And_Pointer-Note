//
//  __struct_point.c
//  block
//
//  Created by 王望 on 17/1/12.
//  Copyright © 2017年 Will. All rights reserved.
//

#include "__struct_point.h"
#include <stdlib.h>

typedef struct NODE{
    struct NODE *link;//指向下一个节点（结构）的起始位置。
    int         value;
}Node;

typedef struct DNODE{
    struct DNODE *fwd;
    struct DNODE *bwd;
    int value;
}Dnode;

int _linklist_insert(Node **root_p,int new_value);

//链表

void __struct_point_main(void){
    
    //_linklist_insert(<#Node *current#>, 12);
}


//MARK: - 单链表 -
//在单链表中，每个节点包含一个指向链表下一个节点的指针。链表最后一个节点的指针字段的值为__NULL__。
//知道链表的第一个节点之后，根据指针就可以访问剩余的所有节点。所以我们可以使用一个指针来记住链表的起始位置。

//



//在进行链表的插入时，我们需要保存一个指针，使得该指针指向链表当前节点之前的那个节点的指针。

//MARK: - 单链表插入 -
//记住：是根据指针的移动来访问链表。
//0 -> false
//1 -> true
int _linklist_insert(Node **root_p,int new_value){
    Node *current = *root_p;
    Node *new;
    Node *previous = NULL;
    
    while (current != NULL & current->value < new_value) {
        previous = current;
        current = current->link;
    }
    
    new = malloc(sizeof(Node));
    if (new == NULL) {
        return 0;
    }
    new->value = new_value;
    new->link = current;
    if (previous == NULL) {
        //修改根指针
        *root_p = new;
        return 1;
    }
    previous->link = new;
    return 1;
}
//声明一个指向当前节点的指针`current`，和一个“指向当前节点的link字段的”指针`linkp`

//其中linkp为指向root指针的指针（也就是保存root变量的内存地址）。
//而root又是指向第一个节点的指针。
int _linklint_insert_point(Node const **linkp,int new_value){
    Node *new;//这里为啥子不加const，因为->操作会先通过间接操作符获取这个变量，然后再通过.点运算符获取她的成员。而且在函数中，只有一次改变new所以没有必要加const
    const Node *current;
    
    while ((current = *linkp) != NULL && current->value < new_value) {
        //**linkp = *(current -> link); 针对指针的操作大多是通过地址的修改来的，如果是修改通过间接操作符作为左值的结果的话，就是修改到了该指针指向的变量的值，所以这就是为什么由const的原因。
        *linkp = current->link;
        current = *linkp;
    }
    
    new = malloc(sizeof(Node));
    new->value = new_value;
    new->link = (Node *)current;
    *linkp = new;
    return 1;
}


//MARK: - 双向链表 -
//0 元素已经存在
//1 成功
//-1 失败
int d_linklist_insert(Dnode *rootp,int new_value){
    
    Dnode *this;
    Dnode *next;
    Dnode *new;
    
    this = rootp;
    
    for (this = rootp; (next = this->fwd) != NULL; this = next) {
        if (next->value == new_value) {
            return 0;
        }
        if (next->value > new_value) {
            break;
        }
    }
    new = malloc(sizeof(Dnode));//这个声明放在检查重复元素之后，方式内存泄漏
    if (new == NULL) {
        return -1;
    }
    new   -> value = new_value;
    this  -> fwd   = new;
    new   -> fwd   = next ?: NULL;
    if (next != NULL) {//没有在链表末插入
        next->bwd = new;
        new->bwd = next->bwd == NULL ? NULL : this;//next->bwd == NULL在表头，否则在表中
    }else{//在链表末尾
        rootp->bwd = new;
        new->bwd = this == rootp ? NULL : this;//this == rootp空链表，否则不是空链表，位于真正的末尾
    }
    return 1;
}
// 单链表是一种用指针来存储值的数据结构。链表中每个节点包含一个字段，用于指向链表的下一个节点。而双向链表每个节点包含了两个link字段。


