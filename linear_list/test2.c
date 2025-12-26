#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 100
typedef int ElemType;

// // 顺序表定义
// typedef struct{
//     ElemType data [MAXSIZE];
//     int length;
// }SeqList;

// // 顺序表初始化(在栈上分配内存)
// void Initlist(SeqList *list){
//     list->length = 0;
// } 

typedef struct{
    ElemType *data;
    int length;
}SeqList;

// 在堆上分配内存, 这里不用传参数，
SeqList* Initlist(){

    // 结构体本身内存
    SeqList *L = (SeqList*)malloc(sizeof(SeqList));

    // 存放数据的内存
    L->data = (ElemType*)malloc(sizeof(ElemType)* MAXSIZE);
    L->length = 0;
    return L;
}

int appendElem(SeqList *list, ElemType e){
    if(list->length > MAXSIZE){
        printf("顺序表已满");
        return 0;
    }

    list->data[list->length] = e;
    list->length++;
    return 1;
}

void listElem(SeqList *L){
    for(int i = 0; i < L->length; i++){
        printf("%d\n", L->data[i]);
    }
    printf("\n");
}

void add(SeqList *L, ElemType addNumber, ElemType pos){
    if(pos<1 || pos >L->length){
        printf("插入位置错误");
        return;
    }
    
    for(int j = L->length; j>=pos; j--){
        L->data[j] = L->data[j-1];
    }
    L->data[pos-1] = addNumber;
    L->length++; 
}

void deletePos(SeqList *L, ElemType pos, ElemType *deleteNum){
    *deleteNum = L->data[pos-1];

    if(pos<1 || pos >L->length){
        printf("删除位置错误");
        return;
    }

    for(int j = pos-1; j<L->length-1; j++){
        L->data[j] = L->data[j+1];
    }

    L->length--;
    printf("本次删除了元素%d\n",*deleteNum);
}

int firstElem(SeqList *L, ElemType queryNum){
    for(int i=0; i<L->length; i++){
        if(L->data[i] == queryNum){
            return(i+1);
            break;
        }
    }
    return 0;
}

int main(){
    // 声明线性表并初始化
    // SeqList *list = Initlist();
    SeqList *L = NULL;
    L = Initlist();

    appendElem(L, 10);
    appendElem(L, 15);
    appendElem(L, 32);
    appendElem(L, 53);
    listElem(L);

    add(L, 55, 2);
    listElem(L);
    ElemType deleteNum;
    deletePos(L,2,&deleteNum);
    listElem(L);

    printf("%d",firstElem(L,120));


}
