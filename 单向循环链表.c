#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct Node{
    ElemType data;
    struct Node* next;
}Node;

void insertTail(Node* head,ElemType e){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=e;
    temp->next=head;
    Node* val=head->next;
    if(val==head){
        head->next=temp;
    }else{
    while(val->next!=head){
        val=val->next;
    }
    val->next=temp;
    }
    head->data++;
}

Node* initList(){
    Node* head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=head;
    return head;
}

void print_list(Node* head){
    printf("the length of list=%d\n",head->data);
    Node* val=head->next;
    if(val==head){
        printf("the list is empty\n");
        return;
    }
    while(val!=head){
        printf("%d ",val->data);
        val=val->next;
    }
    printf("\n");
}

int main(){
    Node* head=initList();
    for(int i=1;i<=10;i++){
        insertTail(head,i);
    }
    print_list(head);
    return 0;
}