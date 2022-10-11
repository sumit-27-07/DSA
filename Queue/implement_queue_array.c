#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int b;
    int f;
    int *arr;
};
int isempty(struct Queue *q){
    if(q->b==q->f){
        return 1;
    }
    return 0;
}
int isfull(struct Queue *q){
    if(q->b==q->size){
        return 1;
    }
    return 0;
}
void enqueue(struct Queue *q){
    if(isfull(q)){
        printf("Queue is overflow\n");
    }
    else{
        int val;
        printf("Enter data for enqueue:");
        scanf("%d",&val);
        q->arr[q->b]=val;
        q->b++;
    }
}
void dequeue(struct Queue *q){
    int val;
    if(isempty(q)){
        printf("Queue is underflow\n");
        q->b=q->f=0;
    }
    else{
        val=q->arr[q->f];
        printf("Deleted element:%d\n",val);
        q->f++;
    }
}
void display(struct Queue *q){
    int i=q->f;
    printf("Elements in Queue:");
    while(i!=q->b){
        printf("%d  ",q->arr[i]);
        i++;
    }
    printf("\n");
}
int main(){
    struct Queue q;
    q.size=3;
    q.b=q.f=0;
    q.arr=(int *) malloc(q.size*sizeof(int));
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
            enqueue(&q);
            break;
        case 2:
            dequeue(&q);
            break;
        case 3:
            display(&q);
            break;
        case 4:
            printf("\nEXIT POINT");
            break;
        
        default:
            printf("\n Please Enter a Valid Choice(1/2/3/4)");
        }
    }while(choice!=4);
    /*enqueue(&q);
    enqueue(&q);
    enqueue(&q);
    enqueue(&q);
    dequeue(&q);
    dequeue(&q);*/
    return 0;
}