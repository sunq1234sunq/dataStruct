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
}

Node* getTail(Node *L){
    if(L == NULL) return NULL;

    Node *current = L;
    while(current -> next != NULL){
        current = current -> next;
    }
    return current;
}

void printList(Node *L){
    Node *current = L -> next;
    while(current != NULL){
        printf("%d ->", current -> data);
        current = current -> next;
    }
    printf(" NULL \n");
}

void insertAtHead(Node *L, Elemtype e){
    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = e;
    newNode -> next = L -> next;
    L -> next = newNode;
}

void insertAtTail(Node *Tail, Elemtype e){
    if (Tail == NULL) return;
    
    Node *newNode = (Node*)malloc(sizeof(Node));

    newNode -> data = e;
    newNode -> next = NULL;
    Tail -> next = newNode;

}

int main(){
    Node *list = initList(); // 返回的是头节点的指针

    insertAtHead(list, 10);
    insertAtHead(list, 20);
    insertAtHead(list, 30);

    Node *Tail = getTail(list);
    insertAtTail(Tail, 40);
    printList(list);

    return 0;
}