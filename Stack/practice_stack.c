#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int *arr;
    int top;
};
int isfull(struct stack *ptr){
    if(ptr->size-1==ptr->top){
        return 1;
    }
    return 0;
}
int isempty(struct stack *ptr){
    if(ptr->top==-1){
        return 1;
    }
    return 0;
}
void push(struct stack *s){
    int num;
    printf("Enter data for push:");
    scanf("%d",&num);
    if(isfull(s)){
        printf("Stack is overflow\n");
    }
    else{
        s->top++;
        s->arr[s->top]=num;
    }
}
int pop(struct stack *s){
    if(isempty(s)){
        printf("Stack is Empty\n");
    }
    else{
        int x=s->arr[s->top];
        s->top=s->top-1;;
        return x;
    }
}
char *infix_postfix(char *infix){
    struct stack *s=(struct stack *)malloc(sizeof(struct stack));
    s->size=10;
    s->top=-1;
    s->arr=(char *)malloc(s->size*sizeof(char));
    char *postfix=
}
void display(struct stack *s){
    int i=s->top;
    printf("Data in stack:\n");
    while(i>=0){
        printf("%d\n",s->arr[i]);
        i--;
    }
}
int main(){
    /*struct stack *s;
    s->size=10;
    s->top=-1;
    s->arr=(int *)malloc(s->size*sizeof(int));
    int x,choice;
    printf("\tSTACK OPERATION USING ARRAY\n");
    printf("\t---------------------------\n");
    printf("\t1.PUSH\n\t2.POP\n\t3.DISPLAY\n\t4.EXIT\n");
    do{
        printf("Enter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(s);
            break;
        case 2:
            x=pop(s);
            printf("Deleted Number:%d\n",x);
            break;
        case 3:
            display(s);
            break;
        case 4:
            printf("EXIT\n");
            break;
        default:
            printf("ENTER VALID CHOICE(1/2/3/4):\n");
        }
    }while(choice!=4);*/
    return 0;
}