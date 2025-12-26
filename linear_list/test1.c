#include <stdio.h>

#define MAXSIZE 100
typedef int ElemType;

// 顺序表结构体定义
typedef struct{
    ElemType data[MAXSIZE];
    int length; 
}SeqList;

// 初始化顺序表
void InitList(SeqList *L){
    L->length = 0;
}

int main(){
    // 声明一个顺序表并初始化
    SeqList list;
    InitList(&list);
    printf("%d\n", list.length);
    printf("%d\n", list.data[0]);
    printf("%zu", sizeof(list.data));
    
}



