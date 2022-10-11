#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node * next;
}; struct node *top=NULL;
int isempty(struct node *top){
    if(top==NULL){
        return 1;
    }
    return 0;
}
int isfull(struct node *top){
    struct node *p=(struct node *) malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    return 0;
}
int push(struct node *ptr){
    if(isfull(ptr)){
        printf("Stack overflow");
    }
    else{
        struct node *p=(struct node *) malloc(sizeof(struct node));
        printf("Enter data for push:");
        scanf("%d",&p->data);
        p->next=top;
        top=p;
    }
}
int pop(struct node *ptr){
    if(isempty(ptr)){
        printf("Stack is empty");
    }
    else{
        int x=top->data;
        top=top->next;
        return x;
    }
}
void peek(struct node *ptr){
    struct node *p=ptr;
    int i=0,pos;
    printf("Enter position for peek the value:");
    scanf("%d",&pos);
    while(i!=pos-1){
        p=p->next;
        i++;
    }
    if(p==NULL){
        printf("Given position is wrong input\n");
    }
    else{
        printf("Number in position[%d]=%d\n",pos,p->data);
    }
}
void display(struct node *ptr){
    printf("Element in linked list:");
    while(ptr!=NULL){
        printf("\n%d",ptr->data);
        ptr=ptr->next;
    }
}
int main(){
    int choice;
    printf("\n\t STACK OPERATIONS USING LINKED LIST");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.PEEK\n\t 5.EXIT\n");
    do{
    printf("Enter choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:{
        int i,n;
        printf("How many number wants for push:");
        scanf("%d",&n);
        for(i=0;i<n;i++){
            push(top);
        }
        break;
    }
    case 2:{
        int x=pop(top);
        printf("Deleted number=%d\n",x);
        break;
    }
    case 3:{
        display(top);
        printf("\nPress Next Choice\n");
        break;
    }
    case 4:{
        peek(top);
        break;
    }
    case 5:{
        printf("\n\t EXIT POINT ");
            break;
    }
    default:{
        printf ("\n\t Please Enter a Valid Choice(1/2/3/4/5)");
    }
    }
    }while(choice!=5);
    return 0;
}