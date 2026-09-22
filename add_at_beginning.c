#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int data;
    struct node* next;
};
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
int main(){
struct node* head=malloc(sizeof(struct node));
    head->prev=NULL;
    head->data=45;
    head->next=NULL;
    head=add_beg(head, 35);
    struct node* ptr=head;
    while(ptr!=NULL){
        printf(" %d", ptr->data);
        ptr=ptr->next;
    }
    return 0;
}
