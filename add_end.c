#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};
struct node* add_element(struct node* head,int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node* add_beg( struct node* head, int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    temp->next=head;
    head->prev=temp;
    head=temp;

    return head;

}
struct node* add_end( struct node* head, int data){
    struct node *temp,*tp;
    temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    tp=head;
    while(tp->next!=NULL){
        tp=tp->next;
    }
    tp->next=temp;
    temp->prev=tp;
    return head;
}
int main(){
struct node* head=NULL;
    head=add_element(head, 45);
    head=add_beg(head, 35);
    head=add_end(head,60);
    struct node* ptr;
    ptr=head;
    while(ptr!=NULL){
        printf(" %d", ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
