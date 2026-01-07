#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct node{
    Elemtype data;
    struct node *next;  
}Node;

// 查找链表中倒数第k个位置上的节点

// 倒数第k个位置， 正数length - k
// 
int findK(Node *L, int pos){
    if (L == NULL || pos <= 0) {
        return 0; 
    }

    Node *current = L -> next;
    int length = 0;

    while (current != NULL){
        current = current -> next;
        length++;
    }if(length < pos) {return 0;}

    current = L -> next; // 这里不需要重新声明Node *current
    int posC = length - pos;
    int currentPos = 0;
    while(current != NULL && currentPos < posC){
        current = current -> next;
        currentPos++;    
    }
    if(current != NULL){
        return current -> data;
    }else return 0;
}


