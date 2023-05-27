#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
/*int queue[10];
int front=0;
int rear=0;*/

struct node * create_node(int data){
    struct node *n=(struct node *) malloc (sizeof(struct node));
    n->data=data;
    n->left=NULL;
    n->right=NULL;
    return n;
}
struct node *buildtree(struct node *p){
    struct node *root=(struct node *) malloc (sizeof(struct node));
    int num;
    printf("Enter number :");
    scanf("%d",&num);
    root->data=num;
    root->left=NULL;
    root->right=NULL;
    if(num==-1){
        return NULL;
    }
    printf("Enter data for inserting in left of %d\n",num);
    root->left=buildtree(root->left);
    printf("Enter data for inserting in right of %d\n",num);
    root->right=buildtree(root->right);
    return root;
}
/*struct node *enqueue(struct node *p){
    queue[rear]=p->data;
    rear++;
}
int dequeue(){
    int num=queue[front];
    front++;
    return num;
}
int isempty(){
    if(front==rear){
        return 1;
    }
    return 0;
}*/
void preorder_print(struct node *p){
    if(p!=NULL){
        printf("%d  ",p->data);
        preorder_print(p->left);
        preorder_print(p->right);
    }
}
void postorder_print(struct node *p){
    if(p!=NULL){
        postorder_print(p->left);
        postorder_print(p->right);
        printf("%d  ",p->data);
    }
}
void inorder_print(struct node *p){
    if(p!=NULL){
        inorder_print(p->left);
        printf("%d  ",p->data);
        inorder_print(p->right);
    }
}
/*void level_order(struct node *p){
    enqueue(p);
    enqueue(0);
    while(!isempty()){
        int temp=queue[front];
        printf("%d  ",temp);
        dequeue();
        if(temp==0){
            printf("\n");
            if(!isempty()){
                enqueue(0);
            }
        }
        else{
            printf("%d  ",temp);
            if(p->left){
                enqueue(p->left);
            }
            if(p->right){
                enqueue(p->right);
            }
        }
    }
}*/
int main(){
    /*struct node *root=create_node(5);
    struct node *child1=create_node(3);
    struct node *child2=create_node(6);
    root->left=child1;
    root->right=child2;*/
    struct node *root=NULL;
    root=buildtree(root);
    printf("Preorder Traversal:\n");
    preorder_print(root);
    printf("\n");
    printf("Postorder Traversal:\n");
    postorder_print(root);
    printf("\n");
    printf("Inorder Traversal:\n");
    inorder_print(root);
    printf("\n");
    //level_order(root);
    return 0;
}