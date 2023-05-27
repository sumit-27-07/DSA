#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
struct node *solve(int inarr[],int prearr[],int &preindex,int inorderstart,int inorderend ,int n){
    if(preindex>=n ||inorderstart>inorderend){
        return NULL;
    }
    int element=prearr[preindex++];
    struct node *root=(struct node *) malloc(sizeof(struct node));
    root->data=element;
    int position;
    for(int i=0;i<n;i++){
        if(inarr[i]==element){
            position=i;
            break;
        }
    }
    root->left=solve(inarr,prearr,preindex,inorderstart,position-1,n);
    root->right=solve(inarr,prearr,preindex,position+1,inorderend,n);
    return root;
}
struct node *buildtree(int inarr[],int prearr[],int npre){
    int preindex=0;
    struct node *ans= solve(inarr,prearr,preindex,0,npre-1,npre);
    return ans;
}
void postorder_print(struct node *p){
    if(p!=NULL){
        postorder_print(p->left);
        postorder_print(p->right);
        printf("%d  ",p->data);
    }
}
void preorder_print(struct node *p){
    if(p!=NULL){
        printf("%d  ",p->data);
        preorder_print(p->left);
        preorder_print(p->right);
    }
}
int main(){
    int inorder[]={3,1,4,0,5,2};
    int preorder[] = {0,1,3,4,2,5};
    struct node *root;
    root=buildtree(inorder,preorder,6);
    postorder_print(root);
    printf("\n");
    preorder_print(root);
    return 0;
}