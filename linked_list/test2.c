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


// 上面的时间复杂度是O(2n), 使用快慢指针，快指针先走pos，慢指针再走。快指针到达末尾慢指针正好到倒数第pos

int findK2(Node *L, int pos){
    Node* fast = L;
    Node* slow = L;

    for (int i = 0; i < pos; i++)
    {
        if(fast == NULL) {return 0;}
        fast = fast -> next;
    }

    while(fast != NULL){
        fast = fast -> next;
        slow = slow -> next;
    }

    return slow -> data;
    
}