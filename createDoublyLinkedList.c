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

int main(){
struct node* head=NULL;
 struct node* ptr;
head=CreateList(head);

ptr=head;
    while(ptr!= NULL){
        printf(" %d", ptr->data);
        ptr=ptr->next;
    }
    
   return 0;
}
