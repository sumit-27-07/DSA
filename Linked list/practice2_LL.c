#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
    struct node *prev;
};
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
struct node *merge(struct node * head1,struct node * head2){
    struct node *p1=head1;
    struct node *p2=head2;
    struct node *dummy;
    struct node *p3=dummy;
    while(p1!=NULL&&p2!=NULL){
        if(p1->data>p2->data){
            p3->next=p2;
            p2=p2->next;
        }
        else{
            p3->next=p1;
            p1=p1->next;
        }
        p3=p3->next;
    }
    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;
        p2=p2->next;
        p3=p3->next;
    }
    return dummy->next;
}
struct node *merge_rec(struct node * head1,struct node *head2){
    if(head1==NULL){
        return head2;
    }
    if(head2==NULL){
        return head1;
    }
    struct node *result;
    if(head1->data<head2->data){
        result=head1;
        result->next=merge_rec(head1->next,head2);
    }
    else{
        result=head2;
        result->next=merge_rec(head1,head2->next);
    }
    return result;
}
struct node *make_loop(struct node *head){
    int a,b;
    printf("Enter data1 from linked list:");
    scanf("%d",&a);
    struct node *t=head;
    while(t->next!=NULL){
        t=t->next;
    }
    struct node *p=head;
    while(p->data!=a){
        p=p->next;
    }
    t->next=p;
    return head;
}
struct node *detect_loop(struct node *head){
    struct node *s=head;
    struct node *f=head;
    while(s!=NULL&&f!=NULL){
        f=f->next;
        if(f!=NULL){
            f=f->next;
        }
        s=s->next;
        if(s==f){
            return s;
        }
    }
    return NULL;
}
struct node *beg_loop(struct node *head){
    struct node *p=head;
    struct node *q=detect_loop(head);
    while(p!=q){
        p=p->next;
        q=q->next;
    }
    return p;
}
struct node *remove_loop(struct node *head){
    struct node *p=beg_loop(head);
    struct node *q=p;
    while(p->next!=q){
        p=p->next;
    }
    p->next=NULL;
}
void print(struct node *ptr){
    int i=1;
    while(ptr!=NULL){
        printf("Value at Node[%d]:%d\n",i,ptr->data);
        i++;
        ptr=ptr->next;
    }
}
int main(){
    int i,n;
    struct node *head1=NULL;
    struct node *head2=NULL;
    struct node *head;
    printf("Enter size of linked list1:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head1=create(head1,i+1);
    }
    print(head1);

    printf("Enter size of linked list2:");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        head2=create(head2,i+1);
    }
    print(head2);
    printf("After merge two linked list:\n");
    head=merge(head1,head2);
    print(head);
    make_loop(head1);
    //print(head1);
    if(detect_loop(head1)){
        struct node *p=detect_loop(head1);
        printf("Loop is detect at number %d\n",p->data);
    }
    head=beg_loop(head1);
    printf("Beginning element of loop:%d\n",head->data);
    remove_loop(head1);
    print(head1);
    return 0;
}