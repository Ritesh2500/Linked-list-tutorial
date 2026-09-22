#include <stdio.h>
#include <stdlib.h>

struct node{
    struct node* prev;
    int data;
    struct node* next;   
};
struct node* addToEmpty( struct node* head, int data){
    struct node* temp=malloc(sizeof(struct node));
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    head=temp;
    return head;
}
struct node* addToEnd(struct node* head, int data){
    struct node* temp=malloc(sizeof(struct node));
    struct node* ptr=head;
    temp->prev=NULL;
    temp->data=data;
    temp->next=NULL;
    
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=temp;
    temp->prev=ptr;
    
    return head;
}

struct node* CreateList( struct node* head){
    int n,data,i;
    printf("Enter number of nodes to create in list");
    scanf("%d",&n);

    if(n<=0)
        return head;
    
    printf("Enter data for node 1:");
    scanf("%d", &data);
    head=addToEmpty(head,data);

    for(i=1;i<n;i++){
        printf("Enter data of node %d :", i+1);
        scanf("%d",&data);
        head=addToEnd(head,data);
    }
    return head;
    
}
struct node* deleteFirst( struct node* head){
    head=head->next;
    free(head->prev);
    head->prev=NULL;
    return head;
}
struct node* deletelast(struct node* head){
    struct node *temp,*temp2;
    temp=head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp2=temp->prev;
    temp2->next=NULL;
    free(temp);
    temp=NULL;
    return head;
}
int main(){
struct node* head=NULL;
 struct node* ptr;
head=CreateList(head);

    ptr=head;
    while(ptr!= NULL){
        printf(" %d", ptr->data);
        ptr=ptr->next;
    }
      printf(" \n");
    head=deletelast(head);
    struct node* ptr2=head;
    while(ptr2!=NULL){
        printf(" %d",ptr2->data);
        ptr2=ptr2->next;
    }
    return 0;
}
