#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

void traversal(struct node *ptr){
	int i=1;
	while(ptr != NULL){
		printf("Element[%d]:%d\n",i,ptr->data);
		i++;
		ptr=ptr->next;
	}
}

//case 1
struct node * insertatfirst(struct node *head,int data){
	struct node *ptr=(struct node *) malloc(sizeof(struct node));
	ptr->next=head;
	ptr->data=data; 
	return ptr;
}

//case 2
struct node * insert_between(struct node *head,int data,int index){
	struct node *ptr=(struct node *) malloc(sizeof(struct node));
	struct node *p=head;
	int i=0;
	while(i!=index-1){
		p=p->next;
		i++;
	}
	ptr->data=data;
	ptr->next=p->next;
	p->next=ptr;
	return head;
}

//case 3
struct node * insert_end(struct node *head,int data){
	struct node *ptr=(struct node *) malloc(sizeof(struct node));
	struct node *p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	ptr->data=data;
	p->next=ptr;
	ptr->next=NULL;
	return head;
}

//case 4
struct node * insert_after_node(struct node *head,struct node *prevnode,int data){
	struct node *ptr=(struct node *) malloc(sizeof(struct node));
	ptr->next=prevnode->next;
	prevnode->next=ptr;
	ptr->data=data; 
	return head;
}

int main(){
	struct node *head;
	struct node *second;
	struct node *third;
	struct node *fourth;
	head=(struct node *) malloc(sizeof(struct node));
	second=(struct node *) malloc(sizeof(struct node));
	third=(struct node *) malloc(sizeof(struct node));
	fourth=(struct node *) malloc(sizeof(struct node));
	head->data=25;
	head->next=second;
	
	second->data=36;
	second->next=third;
	
	third->data=12;
	third->next=fourth;
	
	fourth->data=15;
	fourth->next=NULL;
	traversal(head);
	
	//head=insertatfirst(head,42);
	//printf("Element of linked list after insert an element at first:\n");
	//traversal(head);
	
	//head=insert_between(head,49,3);
	//printf("Element of linked list after insert an element at between:\n");
	//traversal(head);
	
	//head=insert_end(head,91);
	//printf("Element of linked list after insert an element at end:\n");
	//traversal(head);
	
	head=insert_after_node(head,third,100);
	printf("Element of linked list after insert an element after node:\n");
	traversal(head);
	return 0;
}


