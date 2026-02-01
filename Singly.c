#include<stdio.h>
#include<stdlib.h>

typedef int ElemType;

typedef struct Node
{
    ElemType data;
    struct Node* next;
}Node;

int findnode_pos(Node* head,ElemType e){
    Node* val=head->next;
    int i=1;
    while(val!=NULL&&val->data!=e){
        val=val->next;
        i++;
    }
    if(i>head->data){
        return -1;
    }
    return i;
}

Node* find_node(Node* head,int pos){
    int i=1;
    if(pos>head->data||pos<=0){
        printf("error");
        return head;
    }
    Node* val=head->next;
    while(i!=pos){
        val=val->next;
        i++;
    }
    return val;
}

Node* find_node_before(Node* head,int pos){
    int i=1;
    if(pos>head->data||pos<=0){
        printf("error");
        return head;
    }
    Node* val=head->next;
    while(i!=pos-1){
        val=val->next;
        i++;
    }
    return val;
}

Node* initList(){
    Node* head=(Node*)malloc(sizeof(Node));
    head->data=0;
    head->next=NULL;
    return head;
}

void insertHead(Node* head,ElemType e){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=e;
    temp->next=head->next;
    head->next=temp;
    head->data++;
}

void insertTail(Node* head,ElemType e){
    Node* temp=(Node*)malloc(sizeof(Node));
    temp->data=e;
    temp->next=NULL;
    Node* val=head->next;
    if(val==NULL){
        head->next=temp;
    }else{
    while(val->next!=NULL){
        val=val->next;
    }
    val->next=temp;
    }
    head->data++;
}

void insertNode(Node* head,int pos,ElemType e){
    if(pos>head->data){
        printf("error\n");
        return;
    }
    Node* newnode=(Node*)malloc(sizeof(Node));
    newnode->data=e;
    newnode->next=NULL;
    Node* temp=head->next;
    int i=1;
    while(i<pos-1){
        temp=temp->next;
        i++;
    }
    newnode->next=temp->next;
    temp->next=newnode;
    head->data++;
}

void deleteNode(Node* head,ElemType* e,int* delete_pos){
    if(delete_pos==NULL&&e==NULL){
        printf("error");
    }
    int pos;
    pos=(delete_pos==NULL)?findnode_pos(head,*e):*delete_pos;
    Node* val=find_node_before(head,pos);
    val->next=val->next->next;
    free(find_node(head,pos));
    head->data--;
}

void free_Node(Node* head){
    Node* current=head->next;
    if(current==NULL){
        return;
    }
    Node* next;
    while(current!=NULL){
        next=current->next;
        free(current);
        current=next;
    }
    head->next=NULL;
    head->data=0;
}

void print_list(Node* head){
    printf("the length of list=%d\n",head->data);
    Node* val=head->next;
    if(val==NULL){
        printf("the list is empty\n");
        return;
    }
    while(val!=NULL){
        printf("%d ",val->data);
        val=val->next;
    }
    printf("\n");
}

Node* fast_slow_ptr(Node* head,int k){
    Node* slow,*fast;
    slow=head;
    fast=head;
    int i=0;
    while(i<k){
        fast=fast->next;
        i++;
    }
    while(fast!=NULL){
        fast=fast->next;
        slow=slow->next;
    }
    return slow;
}

void reverse_list(Node* head){
    Node* prev=NULL;
    Node* cur=head->next;
    Node* next;
    while (cur!=NULL)
    {
        next=cur->next;
        cur->next=prev;
        prev=cur;
        cur=next;
    }
    head->next=prev;
}

void delete_mid_node(Node* head){
    Node* fast=head->next;
    Node* slow=head;
    while(fast!=NULL&&fast->next!=NULL){
        fast=fast->next->next;
        slow=slow->next;
    }
    Node* temp=slow->next;
    slow->next=temp->next;
    free(temp);
    head->data--;
}

void re_sort(Node* head){
    Node* fast=head->next;
    Node* slow=head;
    while (fast!=NULL&&fast->next!=NULL)
    {
        fast=fast->next->next;
        slow=slow->next;
    }
    Node* second_head=initList();
    second_head->next=slow->next;
    slow->next=NULL;
    reverse_list(second_head);
    Node* val=head->next;
    Node* second_val=second_head->next;
    Node* val_next,* second_val_next;
    while(val->next!=NULL){
        val_next=val->next;
        second_val_next=second_val->next;
        val->next=second_val;
        second_val->next=val_next;
        val=val_next;
        second_val=second_val_next;
    }
    val->next=second_val_next;
}

int main()
{
    Node* head=initList();
    
    for(int i=1;i<=10;i++){
        insertTail(head,i);
    }
    print_list(head);
    printf("%d",findnode_pos(head,11));
    return 0;
}

