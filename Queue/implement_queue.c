#include<stdio.h>
#include<stdlib.h>
int queue[5];
int b=0,f=0;
void enqueue(){
    int val;
    if(b==5){
        printf("Queue is overflow\n");
    }
    else{
    printf("Enter data for push:");
    scanf("%d",&val);
    queue[b]=val;
    b++;
    }
}
void dequeue(){
    
    if(f==b){
        f=0;
        b=0;
        printf("Queue is empty\n");
    }
    else{
    int x=queue[f];
    printf("Deleted Number:%d\n",x);
    f++;
    }
}
void display(){
    int i=f;
    printf("Elements in Queue:");
    while(i!=b){
        printf("%d  ",queue[i]);
        i++;
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
            display();
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