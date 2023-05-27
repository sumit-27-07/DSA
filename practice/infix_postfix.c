#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack
{
    int top;
    int size;
    char *arr;
};
char stacktop(struct stack *s){
    char ch=s->arr[s->top];
    return ch;
}
void push(struct stack *s,char ch){
    s->top++;
    s->arr[s->top]=ch;
}
char pop(struct stack *s){
    char ch=s->arr[s->top];
    s->top--;
    return ch;
}
int isempty(struct stack *s){
    if(s->top==-1){
        return 1;
    }
    return 0;
}
int isoperator(char ch){
    if(ch=='+'||ch=='-'||ch=='*'||ch=='/'){
        return 1;
    }
    return 0;
}
int precedence(char ch){
    if(ch=='*'||ch=='/'){
        return 3;
    }
    else if(ch=='+'||ch=='-'){
        return 2;
    }
    else{
        return 0;
    }
}
char *infix_postfix(char *infix){
    struct stack *sp=(struct stack *) malloc(sizeof(struct stack));
    sp->size=20;
    sp->top=-1;
    sp->arr=(char *) malloc(sp->size*sizeof(char));
    char *postfix=(char *) malloc((strlen(infix)+1)*sizeof(char));
    int i=0,j=0;
    while(infix[i]!='\0'){
        if(!isoperator(infix[i])){
            postfix[j]=infix[i];
            i++;
            j++;
        }
        else{
            if(precedence(infix[i])>precedence(stacktop(sp))){
                push(sp,infix[i]);
                i++;
            }
            else{
                postfix[j]=pop(sp);
                j++;
            }
        }
    }
    while(!isempty(sp)){
        postfix[j]=pop(sp);
        j++;
    }
    postfix[j]='\0';
    return postfix;
}
int main(){
    char infix[20];
    printf("Enter infix equation: ");
    scanf("%s",&infix);
    printf("Postfix Equation of %s : %s",infix,infix_postfix(infix));
    return 0;
}