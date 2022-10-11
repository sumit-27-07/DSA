#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;
};
struct node * detect_loop(struct node *head){
    struct node *slow=head;
    struct node *fast=head;
    while(slow!=NULL&&fast!=NULL){
        fast=fast->next;
        if(fast!=NULL){
            fast=fast->next;
        }
        slow=slow->next;
        if(slow==fast){
            return slow;
        }
    }
    return NULL;
}
struct node * beg_of_loop(struct node *head){
        struct node *slow=head;
        struct node *fast=detect_loop(head);
        while(fast!=slow){
            fast=fast->next;
            slow=slow->next;
        }
        return slow;
}
struct node *remove_loop(struct node *head){
    struct node *beg_element=beg_of_loop(head);
    struct node *temp=beg_element;
    while(temp->next!=beg_element){
        temp=temp->next;
    }
    temp->next=NULL;
}
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
    struct node *fifth;
    struct node *sixth;
    struct node *seventh;
	head=(struct node *) malloc(sizeof(struct node));
	second=(struct node *) malloc(sizeof(struct node));
	third=(struct node *) malloc(sizeof(struct node));
	fourth=(struct node *) malloc(sizeof(struct node));
    fifth=(struct node *) malloc(sizeof(struct node));
    sixth=(struct node *) malloc(sizeof(struct node));
    seventh=(struct node *) malloc(sizeof(struct node));
	head->data=25;
	head->next=second;
	
	second->data=36;
	second->next=third;
	
	third->data=12;
	third->next=fourth;
	
	fourth->data=15;
	fourth->next=fifth;

    fifth->data=20;
	fifth->next=sixth;

    sixth->data=80;
	sixth->next=seventh;

    seventh->data=19;
	seventh->next=fourth;
	//traversal(head);
    if(detect_loop(head)){
        struct node *p=detect_loop(head);
        printf("Loop is detect at %d",p->data);
    }
    else{
        printf("Loop is not present");
    }
    struct node *q=beg_of_loop(head);
    printf("\nFirst element of loop:%d\n",q->data);

    remove_loop(head);
    traversal(head);
    return 0;
}

