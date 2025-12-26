#include <stdio.h>
#include <stdlib.h>

typedef int Elemtype;

typedef struct node{
    Elemtype data;
    struct node *next;  
}Node;

Node* initList(){
    Node *head = (Node*)malloc(sizeof(Node)); // Node初始化  
    head -> data = 0;
    head -> next = NULL;
    return head;
}Node;

int main(){
    Node *list = initList();
    return 1;
}


    