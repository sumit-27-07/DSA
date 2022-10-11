#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
    struct node *prev;
};struct node *head=NULL;
struct node *create(struct node *head){
    struct node *newnode;
    newnode=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for insert:");
    newnode->next=NULL;
    newnode->prev=NULL;
    scanf("%d",&newnode->data);
    struct node *p;
    if(head==NULL){
        head=newnode;
        p=newnode;
        return head;
    }
    else{
        newnode->prev=p;
        p->next=newnode;
        p=newnode;
        return head;
    }
}
struct node *insert(struct node *head){
    struct node *new=(struct node *) malloc(sizeof(struct node));
    int pos;
    printf("Enter position for insert:");
    scanf("%d",&pos);
    printf("Enter data for insert:");
    scanf("%d",&new->data);
    new->next=NULL;
    new->prev=NULL;
    //insert at head
    if(pos==1){
        new->next=head;
        return(new);
    }
    //insert at given location and at tail
    else{
        int i=1;
        struct node *p=head;
        while(i!=pos-1){
            p=p->next;
            i++;
        }
        new->next=p->next;
        new->prev=p;
        p->next=new;
        return head;
    }
}
struct node *delete(struct node *head,int n){
    struct node *p=head;
    int pos;
    printf("Enter position for delete number:");
    scanf("%d",&pos);

    //for deleting head
    if(pos==1){
        head=p->next;
        free(p);
        return head;
    }

    //for deleting node between linked list
    else if(pos<n){
        int i=1;
        while(i!=pos-1){
            p=p->next;
            i++;
        }
    struct node *q=p->next;
    struct node *r=q->next;
    p->next=q->next;
    r->prev=p;
    free(q);
    return head;
    }

    //for deleting tail node
    else if(pos==n){
        int i=1;
        while(i!=pos-1){
            p=p->next;
            i++;
        }
        struct node *q=p->next;
        p->next=NULL;
        free(q);
        return head;
    }
}
void traversal(struct node *ptr){
    int i=1;
    while(ptr!=NULL){
        printf("Value at node[%d]:%d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
}
int main(){
    int n;
    printf("How many nodes wants to create:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head=create(head);
    }
    traversal(head);
    head=insert(head);
    traversal(head);
    n++;
    head=delete(head,n);
    traversal(head);
    return 0;
}