#include<stdio.h>
#include<stdlib.h>
struct stack{
    int size;
    int top;
    char *arr;
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
void push(struct stack *ptr,char val){
    if(isfull(ptr)){
        printf("Stack is overflow");
    }
    else{
        ptr->top++;
        ptr->arr[ptr->top]=val;
    }
}
char pop(struct stack *ptr){
        char x=ptr->arr[ptr->top];
        ptr->top=ptr->top-1;
        return x;
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
int parenthesis(char *exp){
    struct stack *sp;
    sp->size=50;
    sp->top=-1;
    sp->arr=(char *) malloc(sp->size * sizeof(char));
    int i;
    for (i=0;exp[i]!='\0';i++){
        if(exp[i]=='('){
            push(sp,'(');
        }
        else if(exp[i]==')'){
            if(isempty(sp)){
                return 0;
            }
            pop(sp);
        }
    }
    if(isempty(sp)){
        return 1;
    }
    else{
       return 0; 
    }
}
int main(){
    char *exp="(2+4)+5)";
    parenthesis(exp);
    if(parenthesis(exp)){
        printf("Parenthesis match");
    }
    else{
       printf("Parenthesis not match"); 
    }
    return 0;
}