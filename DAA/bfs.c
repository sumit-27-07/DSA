#include<stdio.h>
#include<stdlib.h>
#define v 7
struct queue{
    int rear;
    int front;
    int *arr;
};
int isempty(struct queue *q){
    if(q->rear==q->front){
        return 1;
    }
    return 0;
}
void enqueue(struct queue *q,int x){
    if(q->rear==v){
        printf("Queue is full");
    }
    else{
        q->rear++;
        q->arr[q->rear]=x;
    }
}
int dequeue(struct queue *q){
    int y;
    q->front++;
    y=q->arr[q->front];
    return y;
}
void bfs(struct queue *q,int graph[v][v]){
    int j,i=1;
    int visited[v]={0,0,0,0,0,0,0};
    printf("%d",i);
    visited[i]=1;
    enqueue(q,i);
    while(!isempty(q)){
        int num=dequeue(q);
        for(j=0;j<v;j++){
            if(graph[num][j]==1 && visited[j]==0){
                printf("%d",j);
                visited[j]=1;
                enqueue(q,j);
            }
        }
    }
}
int main(){
    int graph[v][v]={{0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0}};
    struct queue q;
    q.rear=-1;
    q.front=-1;
    q.arr=(int *) malloc(v*sizeof(int));
    bfs(&q,graph);
    return 0;
}
