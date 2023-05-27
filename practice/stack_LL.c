#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
};struct node *top=NULL;
int isfull(struct node *top){
    struct node *p=(struct node *) malloc(sizeof(struct node));
    if(p==NULL){
        return 1;
    }
    return 0;
}
int isempty(struct node *top){
    if(top==NULL){
        return 1;
    }
    return 0;
}
void push(struct node *ptr){
    if(isfull(ptr)){
        printf("Stack is overflow\n");
    }
    else{
        struct node *p=(struct node *) malloc(sizeof(struct node));
        printf("Enter data for push:");
        scanf("%d",&p->data);
        p->next=top;
        top=p;
    }
}
void pop(struct node *ptr){
    if(isempty(ptr)){
        printf("Stack Underflow\n");
    }
    else{
        int x;
        x=top->data;
        printf("Deleted number=%d\n",x);
        top=top->next;
    }
}
void peek(struct node *ptr){
    int pos;
    struct node *p=ptr;
    printf("Enter position for peek a number:");
    scanf("%d",&pos);
    for(int i=0;i<pos-1;i++){
        p=p->next;
    }
    printf("Peek Number:%d\n",p->data);
}
void display(struct node *p){
    printf("Numbers in stack:\n");
    while(p!=NULL){
        printf("%d\n",p->data);
        p=p->next;
    }
}
int main(){
    int choice;
    printf("STACK OPERATION USING LINKED LIST\n");
    printf("1.PUSH\n2.POP\n3.DISPLAY\n4.PEEK\n5.EXIT\n");
    do
    {
        printf("Enter Choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(top);
            break;
        case 2:
            pop(top);
            break;
        case 3:
            display(top);
            break;
        case 4:
            peek(top);
            break;
        case 5:
            printf("Exit");
            break;
        default:
            printf("Please enter correct choice\n");
            break;
        }
    } while (choice!=5);
    return 0;
}
