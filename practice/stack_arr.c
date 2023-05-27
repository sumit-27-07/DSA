#include<stdio.h>
#include<stdlib.h>
int top=-1;
int n=5;
int stack[5];
int isfull(){
    if(top==n-1){
        return 1;
    }
    return 0;
}
int isempty(){
    if(top==-1){
        return 1;
    }
    return 0;
}
void push(){
    if(isfull()){
        printf("Stack overflow");
    }
    else{
        int num;
        printf("Enter data for push:");
        scanf("%d",&num);
        top++;
        stack[top]=num;
    }
}
void pop(){
    if(isempty()){
        printf("Stack underflow");
    }
    else{
        int x;
        x=stack[top];
        printf("Deleted number:%d\n",x);
        top--;
    }
}
void peek(){
    int pos,x;
    printf("Enter position for peek the number:");
    scanf("%d",&pos);
    x=top-pos+1;
    printf("Peek Number:%d\n",stack[x]);
}
void display(){
    printf("Elemets in stack:\n");
    int i=top;
    for(int k=i;k>=0;k--){
        printf("%d\n",stack[k]);
    }
}
int main(){
    push();
    push();
    push();
    push();
    display();
    pop();
    peek();
    return 0;
}