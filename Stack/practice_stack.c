#include<stdio.h>
#include<stdlib.h>
int n=10;
int stack[10];
int top=-1;
int isempty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
int isfull(){
    if(top==n-1){
        return 1;
    }
    return 0;
}
void push(){
    if(isfull()){
        printf("Stack is overflow\n");
    }
    else{
        top++;
        int num;
        printf("Enter data for push:");
        scanf("%d",&num);
        stack[top]=num;
    }
}
void pop(){
    if(isempty()){
        printf("Stack is underflow\n");
    }
    else{
        int x;
        x=stack[top];
        printf("Deleted number=%d\n",x);
        top--;
    }
}
void display(){
    int x=top;
    printf("Numbers is stack:");
    while(x>-1){
        printf("%d\t",stack[x]);
        x--;
    }
    printf("\n");
}
void peak(){
    int o,pos;
    printf("Enter position for peak value:");
    scanf("%d",&o);
    pos=top-o+1;
    printf("Peak Value=%d\n",stack[pos]);
}
int main(){
    int choice;
    printf("STACK OPERATION USING ARRAY\n");
    printf("1.PUSH\n2.POP\n3.DISPLAY\n4.PEAK\n5.EXIT\n");
    do
    {
        printf("Enter choice:");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push();
            break;
        case 2:
            pop();
            break;
        case 3:
            display();
            break;
        case 4:
            peak();
            break;
        case 5:
            printf("EXIT");
            break;
        default:
            printf("Please Enter a Valid Choice(1/2/3/4/5)\n");
        }
    } while (choice!=5);
    return 0;
}