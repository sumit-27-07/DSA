#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *create(struct node *head,int i){
    struct node *ptr;
    ptr=(struct node *) malloc(sizeof(struct node));
    struct node *p;
    printf("Enter value[%d] of list:",i);
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    if(head==NULL){
        head=ptr;
        p=head;
        return(head);
    }
    else{
        p->next=ptr;
        p=ptr;
        return(head);
    }
}
/*struct node *insert_head(struct node *head){
    struct node *ptr;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter data for insert at head:");
    scanf("%d",&ptr->data);
    ptr->next=head;
    return ptr;
}
struct node *insert_end(struct node *head){
    struct node *ptr;
    struct node *p=head;
    ptr=(struct node *)malloc(sizeof(struct node));
    printf("Enter data for insert at end:");
    scanf("%d",&ptr->data);
    ptr->next=NULL;
    while(p->next!=NULL){
        p=p->next;
    }
    p->next=ptr;
    return (head);
}
struct node *insert_pos(struct node *head,int data,int pos){
    int i=1;
    struct node *ptr;
    struct node *p=head;
    ptr=(struct node *)malloc(sizeof(struct node));
    while(i!=pos-1){
        p=p->next;
        i++;
    }
    ptr->data=data;
    ptr->next=p->next;
    p->next=ptr;
    return (head);
}*/
struct node *delete_first(struct node *head){
	head=head->next;
	return(head);
}
struct node *delete_end(struct node *head){
	struct node *p=head;
	struct node *q=head->next;
	while(q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	p->next=NULL;
	free(q);
	return (head);
}
struct node *delete_pos(struct node *head){
    struct node *p=head;
    int n,i=1;
    printf("Enter position for delete number:");
    scanf("%d",&n);
    if(n==1){
        head=p->next;
        free(p);
        return head;
    }
    while(i!=n-1){
        i++;
        p=p->next;
    }
    struct node *q=p->next;
    p->next=q->next;
    free(q);
    return head;
}
void print(struct node *ptr){
    int i=1;
    while(ptr!=NULL){
        printf("Value at Node[%d]:%d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
}
int main(){
    int i,n,data,pos;
    struct node *head=NULL;
    printf("Enter size of linked list:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head=create(head,i+1);
    }
    print(head);

    /*head=insert_head(head);
    print(head);

    printf("Enter position for insert:");
    scanf("%d",&pos);
    printf("Enter data for insert:");
    scanf("%d",&data);
    head=insert_pos(head,data,pos);
    print(head);

    head=insert_end(head);
    print(head);*/
    printf("Linked list after delete head element:\n");
    head=delete_first(head);
    print(head);
    printf("Linked list after delete element of given position:\n");
    head=delete_pos(head);
    print(head);
    printf("Linked list after delete end element:\n");
    head=delete_end(head);
    print(head);
    return 0;
}