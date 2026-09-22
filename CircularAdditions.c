#include <stdio.h>
#include <stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* addToEmpty(int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=temp;
    return temp;
}

struct node* addBeg(struct node* tail, int data){
    struct node* newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=tail->next;
    tail->next=newP;
    return tail;
}
struct node* addEnd(struct node* tail,int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->data=data;
    temp->next=tail->next;
    tail->next=temp;
    tail=tail->next;
    return tail;
}
struct node* addAfterPos(struct node* tail,int data, int position){
    struct node* newP=malloc(sizeof(struct node));
    newP->data=data;
    newP->next=NULL;
    struct node* p=tail->next;
    while(position!=1){
        p=p->next;
        position--;
    }
    newP->next=p->next;
    p->next=newP;

    if(p==tail){
        tail=tail->next;
    }
    
    return tail;
}
void print(struct node* tail){
    struct node* p=tail->next;
    do{
        printf(" %d",p->data);
        p=p->next; 
    }while(p!=tail->next);
}

int main(){
    int data = 45;
 struct node* tail;
tail=addToEmpty(data);
tail=addBeg(tail,60);
tail=addEnd(tail,70);
tail=addEnd(tail,79);
tail=addBeg(tail,4);
    tail=addAfterPos(tail,66,4);
print(tail);
    return 0;
}
