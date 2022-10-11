#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node *create_node(struct node *head,int i){
	struct node *p;
	p=(struct node *) malloc(sizeof(struct node));
	printf("Enter the data of node[%d]:",i);
	scanf("%d",&p->data);
	p->next=NULL;
	struct node *ptr;
	if(head==NULL){
		head=p;
		ptr=head;
		return (head);
	}
	else{
		ptr->next=p;
		ptr=p;
		return (head);
	}
}
struct node *insert_first(struct node *head,int data){
	struct node *ptr;
	ptr=(struct node *) malloc(sizeof(struct node));
	ptr->data=data;
	ptr->next=head;
	return (ptr);
}
struct node *insert_between(struct node *head,int index,int data){
	int i=0;
	struct node *p=head;
	struct node *ptr;
	ptr=(struct node *) malloc(sizeof(struct node));
	while(i!=index-1){
		p=p->next;
		i++;
	}
	ptr->data=data;
	ptr->next=p->next;
	p->next=ptr;
	return(head);
}
struct node *insert_end(struct node *head,int data){
	struct node *ptr;
	ptr=(struct node *) malloc(sizeof(struct node));
	struct node *p=head;
	while(p->next!=NULL){
		p=p->next;
	}
	ptr->data=data;
	p->next=ptr;
	ptr->next=NULL;
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
	int n,i,num,index;
	struct node *head=NULL;
	printf("Enter number of node want to create:");
	scanf("%d",&n);
	for(i=0;i<n;i++){
		head=create_node(head,i+1);
	}
	traversal(head);
	
	printf("Enter data for insertion:");
	scanf("%d",&num);
	
	//head=insert_first(head,num);
	
	//printf("Enter index for insertion:");
	//scanf("%d",&index);
	//head=insert_between(head,index,num);
	
	printf("After insertion in Linked list:\n");
	head=insert_end(head,num);
	traversal(head);
	return 0;
}

