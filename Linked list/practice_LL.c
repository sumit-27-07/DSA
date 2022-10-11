#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};struct node *head=NULL;
struct node *create(struct node *head,int i){
    struct node *p;
    p=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for node[%d]:",i);
    scanf("%d",&p->data);
    p->next=NULL;
    p->prev=NULL;
    struct node *ptr;
    if(head==NULL){
        head=p;
        ptr=p;
        return head;
    }
    else{
        ptr->next=p;
        p->prev=ptr;
        ptr=p;
        return head;
    }
}
struct node *insert_head(struct node *head){
    struct node *r;
    r=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for insert at head:");
    scanf("%d",&r->data);
    r->next=head;
    r->prev=NULL;
    head=r;
    return head;
}
struct node *insert_pos(struct node *head){
    struct node *r;
    int pos;
    printf("Enter position for insert:");
    scanf("%d",&pos);
    r=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for insert:");
    scanf("%d",&r->data);
    struct node *temp=head;
    int i=1;
    while(i!=pos-1){
        temp=temp->next;
        i++;
    }
    r->next=temp->next;
    r->prev=temp;
    temp->next=r;
    return head;
}
struct node *insert_tail(struct node *head){
    struct node *r;
    r=(struct node *) malloc(sizeof(struct node));
    printf("Enter data for insert at tail:");
    scanf("%d",&r->data);
    struct node *ptr=head;
    while(ptr->next!=NULL){
        ptr=ptr->next;
    }
    ptr->next=r;
    r->prev=ptr;
    r->next=NULL;
    return head;
}
struct node *delete_head(struct node *head){
    struct node *p=head;
    head=p->next;
    head->prev=NULL;
    free(p);
    printf("Linked list after delete head element:\n");
    return head;
}
struct node *delete_pos(struct node *head){
    int pos;
    printf("Enter position for deleting node:");
    scanf("%d",&pos);
    int i=1;
    struct node *t=head;
    while(i!=pos-1){
        t=t->next;
        i++;
    }
    struct node *s=t->next;
    t->next=s->next;
    s->next->prev=t;
    free(s);
    printf("Linked list after delete element of given position:\n");
    return head;
}
struct node *delete_tail(struct node *head){
    struct node *p=head;
    struct node *q=p->next;
    while(q->next!=NULL){
        p=p->next;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    printf("Linked list after delete tail element:\n");
    return head;
}
struct node *reverse(struct node *head){
    struct node *previous=NULL;
    struct node *curr=head;
    struct node *forward=NULL;
    while(curr!=NULL){
        forward=curr->next;
        curr->prev=forward;
        curr->next=previous;
        previous=curr;
        curr=forward;
    }
    printf("Linked list after reverse:\n");
    return previous;
}
struct node *reverse_k(struct node *head,int k){
    struct node *prev=NULL;
    struct node *curr=head;
    struct node *next=NULL;
    int count=0;
    while(count<k&&curr!=NULL){
        next=curr->next;
        curr->next=prev;
        curr->prev=next;
        prev=curr;
        curr=next;
        count++;
    }
    if (next!=NULL){
        head->next=reverse_k(next,k);
    }
    return prev;
}
void swap_nodes(struct node **head){
    int x,y;
    printf("Enter two number for swap node:");
    scanf("%d%d",&x,&y);
    if(x==y){
        return;
    }
    struct node *currx,*prevx=NULL,*curry,*prevy=NULL;
    currx=*head;
    curry=*head;
    while(currx&&currx->data!=x){
        prevx=currx;
        currx=currx->next;
    }
    while(curry&&curry->data!=y){
        prevy=curry;
        curry=curry->next;
    }
    if(currx==NULL||curry==NULL){
        return;
    }
    if(prevx!=NULL){
        prevx->next=curry;
    }
    else{
        *head=curry;
    }
    if(prevy!=NULL){
        prevy->next=currx;
    }
    else{
        *head=currx;
    }
    struct node *temp=NULL;
    temp=curry->next;
    curry->next=currx->next;
    currx->next=temp;
    printf("Linked list after swap nodes:\n");
}
void display(struct node *ptr){
    struct node *q=ptr;
    int i=1;
    while(q!=NULL){
        printf("Data at node[%d]:%d\n",i,q->data);
        q=q->next;
        i++;
    }
}
void rev_display(struct node *ptr){
    struct node *q=ptr;
    int i=1;
    while(q->next!=NULL){
        q=q->next;
    }
    printf("Linked list in reverse order:\n");
    while(q!=NULL){
        printf("Data at node[%d]:%d\n",i,q->data);
        i++;
        q=q->prev;
    }
}
int main(){
    int n;
    printf("Enter how much node want to create:");
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        head=create(head,i+1);
    }
    display(head);
    /*rev_display(head);
    head=insert_head(head);
    display(head);
    head=insert_pos(head);
    display(head);
    head=insert_tail(head);
    display(head);
    head=delete_head(head);
    display(head);
    head=delete_pos(head);
    head=delete_tail(head);
    display(head);
    head=reverse(head);
    display(head);
    swap_nodes(&head);
    display(head);*/
    int k;
    printf("Enter value of k pattern:");
    scanf("%d",&k);
    head=reverse_k(head,k);
    display(head);
    return 0;
}