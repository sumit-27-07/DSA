#include<stdio.h>
#include<stdlib.h>
struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};
int isfull(struct queue *q){
    if(q->size-1==q->rear){
        return 1;
    }
    else{
        return 0;
    }
}
void enqueue_r(struct queue *q){
    int num;
    printf("Enter number for insert in queue:");
    scanf("%d",&num);
    if(isfull(q)){
        printf("Queue is full\n");
    }
    else if(q->rear==-1){
        q->rear=q->front=0;
        q->arr[q->rear]=num;
    }
    else{
        q->rear++;
        q->arr[q->rear]=num;
    }
}
void enqueue_f(struct queue *q){
    int num;
    if(q->front==0){
        printf("Space not present in front of queue");
    }
    else{
        printf("Enter number for insert in queue:");
        scanf("%d",&num);
        q->front--;
        q->arr[q->front]=num;
    }
}
int dequeue_f(struct queue *q){
    int x;
    if(q->front==q->rear+1||q->front==-1){
        printf("Queue is empty\n");
        q->front=q->rear=-1;
    }
    else{
        x=q->arr[q->front];
        q->front++;
        printf("Deleted element:%d\n",x);
        return x;
    }
    return 0;
}
int dequeue_r(struct queue *q){
    int y;
    if(q->rear+1==q->front){
        printf("Queue is empty\n");
        q->front=q->rear=-1;
    }
    else{
        y=q->arr[q->rear];
        printf("Deleted element:%d\n",y);
        q->rear--;
        return y;
    }
    return 0;
}
void display(struct queue *q){
    printf("Elements in queue:");
    int i=q->front;
    if(q->front==q->rear+1){
        printf("No elements in queue\n");
    }
    else{
        do{
            printf("%d  ",q->arr[i]);
            i++;
        }while(i!=q->rear+1);
        printf("\n");
    }
}
int main(){
    struct queue *q;
    q->size=5;
    q->front=q->rear=-1;
    q->arr=(int *)malloc(q->size*sizeof(int));
    int choice;
    printf("\n\t QUEUE OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.ENQUEUE_REAR\n\t 2.ENQUEUE_FRONT\n\t 3.DEQUEUE_FRONT\n\t 4.DEQUEUE_REAR\n\t 5.DISPLAY\n\t 6.EXIT\n");
    do{
        printf("Enter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            enqueue_r(q);
            break;
        case 2:
            enqueue_f(q);
            break;
        case 3:
            dequeue_f(q);
            break;
        case 4:
            dequeue_r(q);
            break;
        case 5:
            display(q);
            break;
        case 6:
            printf("\nEXIT POINT");
            break;
        
        default:
            printf("\n Please Enter a Valid Choice(1/2/3/4)");
        }
    }while(choice!=6);
    return 0;
}