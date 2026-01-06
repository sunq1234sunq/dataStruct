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

int insertAtPos(Node *L, int pos, Elemtype e){
    // 先找到插入的位置
    Node *P = L;
    int i = 0;
    while(i< pos-1){
        P = P -> next;
        i++;
        if(P == NULL){
            return 0;
        }
    }

    Node *newNode = (Node*)malloc(sizeof(Node));
    newNode -> data = e;
    newNode -> next = P -> next;
    P -> next = newNode;
    return 1;
}

int deleteNode(Node*L, int pos){
    Node *P = L;
    int i = 0;
    while(i < pos-1){
        P = P -> next;
        i++;
        if(P == NULL){
            return 0;
        }
    }
    // P现在指向要删除的前驱node
    Node *toDelete = P -> next; // delete指向要删除的node，这个node->next存放了下一个node的地址
    P -> next = toDelete -> next;
    free(toDelete); // 此时被删除节点相当于被孤立出来了，堆内存需要释放
    return 1;
}

int releaseList(Node *L){
    // 链表默认不删除头节点
    // 需要两个指针，先保存头节点的next指针。
    // Node *current = L;
    // current = L -> next; // 冗余了，直接让current指向删除的节点就行 
    Node *current = L -> next;
    Node *q;

    // 判断是不是到尾指针了
    while (current != NULL)
    {
        q = current -> next;
        free(current);
        current = q;
    }
    L -> next = NULL;
}

int main(){
    Node *list = initList(); // 返回的是头节点的指针

    insertAtHead(list, 10);
    insertAtHead(list, 20);
    insertAtHead(list, 30);

    Node *Tail = getTail(list);
    insertAtTail(Tail, 40);
    printList(list);

    insertAtPos(list, 2, 25);
    printList(list);
    deleteNode(list, 3);
    printList(list);

    releaseList(list);
    printList(list);

    return 0;
}