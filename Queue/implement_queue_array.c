#include<stdio.h>
#include<stdlib.h>
struct Queue{
    int size;
    int b;
    int f;
    int *arr;
};
void enqueue(struct Queue *q){
    if(q->size==q->b+1){
        printf("Queue is Full\n");
        return;
    }
    else if(q->b==-1){
        q->b=q->f=0;
    }
    else{
        q->b++;  
    }
    printf("Enter number for enqueue:");
    scanf("%d",&q->arr[q->b]);
}
void dequeue(struct Queue *q){
   if(q->f==-1){
        printf("Queue is Empty\n");
        return;
   }
   int x=q->arr[q->f];
   if(q->f==q->b){
        q->f=q->b=-1;
   }
   else{
        q->f++;
   }
   printf("Deleted number:%d\n",x);
}
void display(struct Queue *q){
    int i=q->f;
    printf("Elements in Queue:");
    while(i!=q->b){
        printf("%d  ",q->arr[i]);
        i++;
    }
    printf("%d",q->arr[q->b]);
    printf("\n");
}
int main(){
    struct Queue *q;
    q->size=3;
    q->b=q->f=-1;
    q->arr=(int *) malloc(q->size*sizeof(int));
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
            enqueue(q);
            break;
        case 2:
            dequeue(q);
            break;
        case 3:
            display(q);
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