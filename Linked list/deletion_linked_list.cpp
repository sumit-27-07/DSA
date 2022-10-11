#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};

struct node *delete_first(struct node *head){
	head=head->next;
	return(head);
}

struct node *delete_inbetween(struct node *head,int index){
	struct node *p=head;
	int i=0;
	while(i!=index-1){
		p=p->next;
		i++;
	}
	struct node *q=p->next;
	p->next=q->next;
	free(q);
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
struct node *delete_node(struct node *head,int value){
	struct node *p=head;
	struct node *q=head->next;
	while(q->data!=value && q->next!=NULL){
		p=p->next;
		q=q->next;
	}
	if(q->data==value){
		p->next=q->next;
	}
	free(q);
	return (head);
}
void traversal(struct node *ptr){
	int i=1;
	while(ptr!=NULL){
		printf("Element[%d]:%d\n",i,ptr->data);
		i++;
		ptr=ptr->next;
	}
}
int main(){
	struct node *head;
	struct node *one;
	struct node *two;
	struct node *three;
	struct node *four;
	head=(struct node *) malloc(sizeof(struct node));
	one=(struct node *) malloc(sizeof(struct node));
	two=(struct node *) malloc(sizeof(struct node));
	three=(struct node *) malloc(sizeof(struct node));
	four=(struct node *) malloc(sizeof(struct node));
	head->data=10;
	head->next=one;
	
	one->data=20;
	one->next=two;
	
	two->data=30;
	two->next=three;
	
	three->data=40;
	three->next=four;
	
	four->data=50;
	four->next=NULL;
	
	traversal(head);
	
	//Deleting the first element
	//printf("Linked list after delete first element:\n");
	//head=delete_first(head);
	//traversal(head);
	
	//Deleting the element between linked list
	//printf("Linked list after delete element inside list:\n");
	//head= delete_inbetween(head,2);
	//traversal(head);
	
	//printf("Linked list after delete last element:\n");
	//head= delete_end(head);
	//traversal(head);
	
	printf("Linked list after delete a node by given element:\n");
	head= delete_node(head,20);
	traversal(head);
	return 0;
}


