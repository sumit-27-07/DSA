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
	return 0;
}

