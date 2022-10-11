#include<stdio.h>
#include<stdlib.h>
struct stack{
    int top1;
    int top2;
    int *arr;
    int size;
};
void push1(struct stack *ptr){
    int data;
    printf("Enter data for push:");
    scanf("%d",&data);
    if(ptr->top2-ptr->top1==0){
        printf("Stack is overflow");
    }
    else{
        ptr->top1++;
        ptr->arr[ptr->top1]=data;
    }
}
void push2(struct stack *ptr){
    int data;
    printf("Enter data for push:");
    scanf("%d",&data);
    if(ptr->top2-ptr->top1==0){
        printf("Stack is overflow");
    }
    else{
        ptr->top2--;
        ptr->arr[ptr->top2]=data;
    }
}
int pop1(struct stack *ptr){
    int x;
    x=ptr->arr[ptr->top1];
    ptr->top1--;
    return x;
}
int pop2(struct stack *ptr){
    int x;
    x=ptr->arr[ptr->top2];
    ptr->top2++;
    return x;
}
void display1(struct stack *ptr){
    int i;
    if(ptr->top1>=0){
        printf("Elements in Stack1:\n");
        for(i=ptr->top1;i>=0;i--){
            printf("%d\n",ptr->arr[i]);
        }
    }
}
void display2(struct stack *ptr){
    int i;
    if(ptr->top2<ptr->size){
        printf("Elements in Stack2:\n");
        for(i=ptr->top2;i<ptr->size;i++){
            printf("%d\n",ptr->arr[i]);
        }
    }
}
int main(){
    struct stack *sp;
    sp->size=10;
    sp->top1=-1;
    sp->top2=10;
    sp->arr=(int *) malloc(sp->size * sizeof(int));
    int x,y,choice;
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH1\n\t 2.PUSH2\n\t 3.POP1\n\t 4.POP2\n\t 5.DISPLAY1\n\t 6.DISPLAY2\n\t 7.EXIT\n");
    do{
    printf("Enter choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:{
        push1(sp);
        break;
    }
    case 2:{
        push2(sp);
        break;
    }
    case 3:{
        x=pop1(sp);
        printf("Deleted number=%d\n",x);
        break;
    }
    case 4:{
        y=pop2(sp);
        printf("Deleted number=%d\n",y);
        break;
    }
    case 5:{
        display1(sp);
        printf("Press Next Choice\n");
        break;
    }
    case 6:{
        display2(sp);
        printf("Press Next Choice\n");
        break;
    }
    case 7:{
        printf("\n\t EXIT POINT ");
        break;
    }
    default:{
        printf ("\n\t Please Enter a Valid Choice(1/2/3/4/5/6/7)");
    }
    }
    }while(choice!=7);
    return 0;
}