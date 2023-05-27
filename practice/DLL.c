#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *prev;
    struct node *next;
};struct node *head=NULL;
struct node *create(struct node *head){
    struct node *ptr=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for insert:");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    ptr->prev=NULL;
    struct node *p;
    if(head==NULL){
        head=ptr;
        p=ptr;
        return head;
    }
    else{
        p->next=ptr;
        ptr->prev=p;
        p=ptr;
        return head;
    }
}
struct node *insert_start(struct node *head){
    struct node *ptr=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for insert in head:");
    scanf("%d", &ptr->data);
    ptr->prev=NULL;
    ptr->next=head;
    head=ptr;
    return head;
}
struct node *insert_between(struct node *head){
    struct node *ptr=(struct node *) malloc(sizeof(struct node));
    int pos;
    printf("Enter position for insert number in linked list:");
    scanf("%d",&pos);
    printf("Enter data for insert :");
    scanf("%d", &ptr->data);
    struct node *p=head;
    for(int i=1;i<pos-1;i++){
        p=p->next;
    }
    ptr->next=p->next;
    ptr->prev=p;
    p->next=ptr;
    return head;
}
struct node *insert_end(struct node *head){
    struct node *ptr=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for insert in end:");
    scanf("%d", &ptr->data);
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    ptr->prev=p;
    ptr->next=NULL;
    return head;
}
struct node *delete_head(struct node *head){
    struct node *p=head;
    head=p->next;
    head->prev=NULL;
    free(p);
    return head;
}
struct node *delete_inside(struct node *head){
    struct node *p=head;
    struct node *q=p->next;
    int pos;
    printf("Enter position for delete number:");
    scanf("%d",&pos);
    for(int i=1;i<pos-1;i++){
        p=p->next;
        q=q->next;
    }
    p->next=q->next;
    q->next->prev=p;
    free(q);
    return head;
}
struct node *delete_end(struct node *head){
    struct node *p=head;
    struct node *q=p->next;
    while(q->next!=NULL){
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
void print(struct node *head){
    printf("Elements in Doubly linked list:");
    struct node *ptr=head;
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    int i;
    for(i=0;i<3;i++){
        head=create(head);
    }
    print(head);
    head=insert_start(head);
    print(head);
    /*head=insert_between(head);
    print(head);
    head=insert_end(head);
    print(head);
    head=delete_head(head);
    print(head);
    head=delete_inside(head);
    print(head);*/
    head=delete_end(head);
    print(head);
    return 0;
}
