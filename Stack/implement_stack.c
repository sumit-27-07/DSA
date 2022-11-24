#include<stdio.h>
int stack[10];
int top=-1;
void push(){
    int data;
    printf("Enter data for push:");
    scanf("%d",&data);
    if(top!=10){
        top++;
        stack[top]=data;
    }
    else{
        printf("Stack is overflow\n");
    }
}
int pop(){
    int x;
    if(top==-1){
        printf("Stack is Underflow\n");
    }
    else{
        x=stack[top];
        top--;
        return x;
    }
}
void display(){
    int i=top;
    printf("Elements in stack:\n");
    while(i>=0){
        printf("%d\n",stack[i]);
        i--;
    }
}
void peek(){
    int x,pos;
    printf("Enter position for peek:");
    scanf("%d",&pos);
    x=top-pos+1;
    printf("Element in position[%d]:%d\n",pos,stack[x]);
}
int main(){
    int choice,x;
    printf("\n\tSTACK OPERATIONS USING ARRAY");
    printf("\n\t--------------------------------");
    printf("\n\t 1.PUSH\n\t 2.POP\n\t 3.DISPLAY\n\t 4.PEEK\n\t 5.EXIT\n");
    do{
    printf("Enter choice:");
    scanf("%d",&choice);
    switch (choice)
    {
    case 1:{
        push();
        break;
    }
    case 2:{
        x=pop();
        printf("Deleted number=%d\n",x);
        break;
    }
    case 3:{
        display();
        printf("Press Next Choice\n");
        break;
    }
    case 4:{
        peek();
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