#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;
typedef struct Node
{
    ElemType data;
    struct Node* prev,*next;
}Node;

int find_pos(Node* head,ElemType value){
    int pos=1;
    Node* val=head->next;
    if(val==NULL){
        printf("empty\n");
    }
    while(val!=NULL&&val->data!=value){
        val=val->next;
        pos++;
    }
    if(pos>head->data){
        return -1;
    }
    return pos;
}

Node* find_node(Node* head,int pos){
    int i=1;
    Node* val=head->next;
    while(i<pos){
        i++;
        val=val->next;
    }
    return val;
}

Node* initlist(){
    Node* head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->prev=NULL;
    head->next=NULL;
    return head;    
}

void insertHead(Node* head,ElemType e){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=e;
    newnode->prev=head;
    newnode->next=head->next;
    if(head->next!=NULL){
        head->next->prev=newnode;
    }
    head->next=newnode;
    head->data++;
}

void insertTail(Node* head,ElemType e){
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=e;
    newnode->next=NULL;
    newnode->prev=NULL;
    Node* val=head->next;
    if(val==NULL){
        newnode->prev=head;
        head->next=newnode;
        head->data++;
        return;
    }
    while(val->next!=NULL){
        val=val->next;
    }
    newnode->prev=val;
    val->next=newnode;
    head->data++;
}

void insertNode(Node* head,int pos,ElemType e){
    if(pos==1){
        insertHead(head,e);
        return;
    }
    if(pos==head->data+1){
        insertTail(head,e);
        return;
    }
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=e;
    Node* val=head->next;
    int i=1;
    while (i<pos-1)
    {
        val=val->next;
        i++;
        if(val==NULL){
            return;
        }
    }
    newnode->prev=val;
    newnode->next=val->next;
    val->next->prev=newnode;
    val->next=newnode;
    head->data++;
}

void deleteNode(Node* head,ElemType* e,int* delete_pos){
    if(delete_pos==NULL&&e==NULL){
        printf("error");
    }
    int pos;
    pos=(delete_pos==NULL)?find_pos(head,*e):*delete_pos;
    if(pos==0){
        printf("error");
        return;
    }
    Node* val=find_node(head,pos);
    if(pos==head->data){
        val->prev->next=NULL;
        free(val);
        head->data--;
        return;
    }
    val->next->prev=val->prev;
    val->prev->next=val->next;
    free(val);
    head->data--;
}

void print_list(Node* head){
    printf("the length of list=%d\n",head->data);
    if(head->next==NULL){
        printf("the list is empty\n");
        return;
    }
    Node* val=head->next;
    while(val!=NULL){
        printf("%d ",val->data);
        val=val->next;
    }
    printf("\n");
}

void free_node(Node* head){
    Node* cur=head->next;
    if(cur==NULL){
        return;
    }
    Node* next;
    while(cur!=NULL){
        next=cur->next;
        free(cur);
        cur=next;
    }
    head->next=NULL;
    head->data=0;
}

int main(){
    Node* head=initlist();

    for(ElemType i=1;i<=10;i++){
        insertTail(head,i);
    }
    print_list(head);
    free_node(head);
    return 0;
}
