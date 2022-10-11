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
struct node *reverse(struct node *head){
    struct node *prev=NULL;
    struct node *forward=NULL;
    struct node *current=head;
    while(current!=NULL){
        forward=current->next;
        current->next=prev;
        prev=current;
        current=forward;
    }
    return prev;
}
void middle_number(struct node *head){
    int i=1;
    struct node *p=head;
    struct node *q=head;
    while(p!=NULL){
        p=p->next;
        i++;
    }
    for(int j=1;j<i/2;j++){
        q=q->next;
    }
    printf("Middle Number=%d",q->data);
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

    printf("Linked list after reverse:\n");
    head=reverse(head);
    print(head);
    
    middle_number(head);
    return 0;
}