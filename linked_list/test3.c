#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct node{
    Elemtype data;
    struct node *next;  
}Node;

// 使用头节点的单链表, str1和str2分别指向两个单词所在单链表的头节点，找出共同后缀的起始位置
// 当两个单词具有相同后缀时，可以共享相同的后缀存储空间

// loading, being。应该先找到尾节点，然后再步进比较第一个不同的后一个位置就是起始位置

int findPublicPos(Node *str1, Node *str2){
    Node *head1 = str1;
    Node *head2 = str2;
    
    int length1 = getListLength(str1);
    int length2 = getListLength(str2);
    // 假设length1 大于 length2
    int i = 0;
    for(i = 0; i< length1 - length2; i++){
        head1 = head1 -> next;
    }

    int move = 0;
    while(head1 -> data != head2 -> data){
        head1 = head1 -> next;
        head2 = head2 -> next;
        move++;
    }

    return i + move;

}

int getListLength(Node *str){
    Node *head = str;
    if(head == NULL) {return 0;}

    int length = 0;
    while(head != NULL){
        head = head -> next;
        length++;
    }
    return length;
}



