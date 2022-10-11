#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};
struct node *r=NULL;
struct node *f=NULL;
void enqueue(){
    int num;
    struct node *n=(struct node *)malloc(sizeof(struct node));
    if(n==NULL){
        printf("Queue is full");
    }
    else{
        printf("Enter number for insert in queue:");
        scanf("%d",&num);
        n->data=num;
        n->next=NULL;
        if(f==NULL){
            f=r=n;
        }
        else{
            r->next=n;
            r=n;
        }
    }
}
int dequeue(){
    int x;
    if(r==f){
        printf("Queue is empty\n");
    }
    else{
        x=f->data;
        printf("Deleted element:%d\n",x);
        f=f->next;
        return x;
    }

}
void display(struct node *ptr){
    printf("Element in queue:");
    while(ptr!=NULL){
        printf("%d  ",ptr->data);
        ptr=ptr->next;
    }
    printf("\n");
}
int main(){
    int choice;
    printf("\n\t QUEUE OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.ENQUEUE\n\t 2.DEQUEUE\n\t 3.DISPLAY\n\t 4.EXIT\n");
    do{
        printf("Enter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue();
            break;
        case 2:
            dequeue();
            break;
        case 3:
            display(f);
            break;
        case 4:
            printf("\nEXIT POINT");
            break;
        
        default:
            printf("\n Please Enter a Valid Choice(1/2/3/4)");
        }
    }while(choice!=4);
    return 0;
}