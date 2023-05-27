#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *create(struct node *head){
    struct node *ptr;
    ptr=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for insert:");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    struct node *p;
    if(head==NULL){
        head=ptr;
        p=head;
        return head;
    }
    else{
        p->next=ptr;
        p=ptr;
        return head;
    }
}
struct node *insert_head(struct node *head){
    struct node *ptr;
    ptr=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for insert at beginning:");
    scanf("%d",&ptr->data);
    ptr->next=head;
    return ptr;
}
struct node *insert_inside(struct node *head){
    struct node *p=head;
    struct node *ptr;
    ptr=(struct node *) malloc(sizeof(struct node));
    int pos;
    printf("Enter position for insert:");
    scanf("%d",&pos);
    printf("Enter data for insert inside:");
    scanf("%d",&ptr->data);
    for(int i=1;i<pos-1;i++){
        p=p->next;
    }
    ptr->next=p->next;
    p->next=ptr;
    return head;
}
struct node *insert_end(struct node *head){
    struct node *ptr;
    ptr=(struct node *) malloc(sizeof(struct node));
    struct node *p=head;
    while(p->next!=NULL){
        p=p->next;
    }
    printf("Enter number for insert in end:");
    scanf("%d",&ptr->data);
    p->next=ptr;
    ptr->next=NULL;
    return head;
}
struct node *delete_head(struct node *head){
    struct node *ptr=head;
    head=ptr->next;
    free(ptr);
    return head;
}
struct node *delete_inside(struct node *head){
    struct node *p=head;
    int pos,i;
    printf("Enter position for delete number:");
    scanf("%d",&pos);
    for(i=1;i<pos-1;i++){
        p=p->next;
    }
    struct node *ptr;
    ptr=p->next;
    p->next=ptr->next;
    free(ptr);
    return head;
}
struct node *delete_end(struct node *head){
    struct node *p=head;
    struct node *q;
    q=head->next;
    while(q->next!=NULL){
        q=q->next;
        p=p->next;
    }
    p->next=NULL;
    free(q);
    return head;
}
void traversal(struct node *ptr){
    printf("Elements in linked list:");
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    int i;
    struct node *head=NULL;
    for(i=0;i<4;i++){
        head=create(head);
    }
    traversal(head);
    /*head=insert_head(head);
    traversal(head);
    head=insert_inside(head);
    traversal(head);
    head=insert_end(head);
    traversal(head);
    head=delete_head(head);
    traversal(head);
    head=delete_inside(head);
    traversal(head);*/
    head=delete_end(head);
    traversal(head);
    return 0;
}