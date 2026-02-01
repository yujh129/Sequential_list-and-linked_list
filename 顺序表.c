#include<stdio.h>
#include<stdlib.h>

#define MAX 1000
typedef int ElemType;

typedef struct 
{
    ElemType *data;
    int length;
}Seqlist;

//初始化:Seqlist* initlist()
//增->尾插:void appendElem(Seqlist* L,ElemType e),指定位置插入:void add_data_to_pos(Seqlist* L,int pos,ElemType e)
//删->void delete_data(Seqlist* L,int* delete_pos,ElemType* e)
//改->void modify_data(Seqlist* L,ElemType* e,int* modify_pos,ElemType target_e)
//查->int find_data(Seqlist* L,ElemType e)

int find_data_pos(ElemType arr[],int left,int right,ElemType target){
    if(left>right){
        return -1;
    }

    int mid=left+(right-left)/2;
    if(arr[mid]==target){
        return mid;
    }
    else if(arr[mid]<target){
        return find_data_pos(arr,mid+1,right,target);
    }
    else{
        return find_data_pos(arr,left,mid-1,target);
    }
}

Seqlist* initList(){
    Seqlist* L=(Seqlist*)malloc(sizeof(Seqlist));
    L->data=(ElemType*)malloc(MAX*sizeof(ElemType));
    L->length=0;
    return L;
}

void appendElem(Seqlist* L,ElemType e){
    if(L->length>=MAX){
        printf("error");
        return;
    }
    L->data[++L->length-1]=e;
    
}

void print_ListElem(Seqlist* L){
    if(L->length==0){
        printf("List is empty");
    }
    for(int i=0;i<L->length;i++){
        printf("%d ",*(L->data+i));
    }    
    printf("\n");
}

void add_data_to_pos(Seqlist* L,int pos,ElemType e){
    //pos:下标
    if(pos>L->length){
        printf("error\n");
    }
    if(pos==L->length){
        L->data[pos]=e;
        L->length++;
    }
    for(int i=L->length-1;i>=pos;i--){
        L->data[i+1]=L->data[i];
    }   
    L->data[pos]=e;
    L->length++;
}

void delete_data(Seqlist* L,int* delete_pos,ElemType* e){
    if(delete_pos==NULL&&e==NULL){
        printf("please scanf only one ptr\n");
        return;
    }
    if(L->length==0){
        printf("empty_error\n");
        return;
    }
    int pos;
    if(delete_pos==NULL&&find_data_pos(L->data,0,L->length-1,*e)==-1){
        printf("not find that value\n");
        return;
    }
    else{
        pos=(delete_pos==NULL)?find_data_pos(L->data,0,L->length-1,*e):*delete_pos;
        for(int i=pos+1;i<L->length;i++){
            *(L->data+i-1)=*(L->data+i);
        }
        L->length--;
    }
}

void modify_data(Seqlist* L,ElemType* e,int* modify_pos,ElemType target_e){
    if(modify_pos==NULL&&e==NULL){
        printf("please scanf only one ptr\n");
        return;
    }
    if(L->length==0){
        printf("empty_error\n");
        return;
    }
    int pos;
    if(modify_pos==NULL&&find_data_pos(L->data,0,L->length-1,*e)==-1){
        printf("not find that value\n");
        return;
    }
    else{
        pos=(modify_pos==NULL)?find_data_pos(L->data,0,L->length-1,*e):*modify_pos;
        printf("before is %d\n",*(L->data+pos));
        *(L->data+pos)=target_e;
    }
}

int find_data(Seqlist* L,ElemType e){
    return find_data_pos(L->data,0,L->length-1,e);
}

void clear_list(Seqlist* L){
    free(L->data);
    free(L);
    printf("OK");
}

int main(){
    Seqlist* L=initList();
    for(ElemType i=1;i<=10;i++){
        appendElem(L,i);
    }
    ElemType value=5;
    int pos=4;
    modify_data(L,&value,NULL,6);
    print_ListElem(L);
    clear_list(L);
    return 0;
}