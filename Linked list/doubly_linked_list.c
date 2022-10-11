#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
    struct node *prev;
};
void traversal(struct node *ptr){
	int i=1;
	while(ptr != NULL){
		printf("Element[%d]:%d\n",i,ptr->data);
		i++;
		ptr=ptr->next;
	}
}
void reverse(struct node *ptr){
    printf("Reverse Linked List:\n");
    do{
        printf("Element:%d\n",ptr->data);
		ptr=ptr->prev;
    }while(ptr->prev != NULL);
    printf("Element:%d\n",ptr->data);
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
    head->prev=NULL;
	head->next=second;
	
	second->data=36;
    second->prev=head;
	second->next=third;
	
	third->data=12;
    third->prev=second;
	third->next=fourth;
	
	fourth->data=15;
    fourth->prev=third;
	fourth->next=NULL;
	traversal(head);
    reverse(fourth);
	return 0;
}

