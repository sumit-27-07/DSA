#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    int *arr;
};
int isempty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    else{
        return 0;
    }
}
int isfull(struct stack *ptr){
    if(ptr->top==ptr->size-1){
        return 1;
    }
    else{
        return 0;
    }
}
void push(struct stack *ptr){
    int val;
    int x=ptr->top+1;
    printf("Enter the value at index[%d]:",x);
    scanf("%d",&val);
    if(isfull(ptr)){
        printf("Stack is overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
int pop(struct stack *ptr){
    if(isempty(ptr)){
        printf("Stack is Empty");
    }
    else{
        int x=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return x;
    }
}
void display(struct stack *ptr){
    int i;
    if(ptr->top>=0){
        printf("Elements in stack:\n");
        for(i=ptr->top;i>=0;i--){
            printf("%d\n",ptr->arr[i]);
        }
    }
    else{
        printf("Stack is empty");
    }
}
int peek(struct stack *s){
    int position,x;
    printf("Enter position for peek:");
    scanf("%d",&position);
    x=s->top-position+1;
    if(x<0){
        printf("Not a valid position for peek");
        return -1;
    }
    else{
        printf("Number at position-%d = %d\n",position,s->arr[x]);
    }
}
int main(){
    int choice,x;
    struct stack *s;
    s->size=10;
    s->top=-1;
    s->arr=(int *) malloc(s->size * sizeof(int));
    printf("\n\t STACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.PEEK\n\t 5.EXIT\n");
    do{
    printf("Enter choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:{
        push(s);
        break;
    }
    case 2:{
        x=pop(s);
        printf("Deleted number=%d\n",x);
        break;
    }
    case 3:{
        display(s);
        printf("Press Next Choice\n");
        break;
    }
    case 4:{
        peek(s);
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