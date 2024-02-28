#include<stdio.h>
#include<stdlib.h>
# define v 7
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
    int visited[v]={0,0,0,0,0,0,0};
    int i=1;
    enqueue(q,i);
    printf("%d",i);
    visited[i]=1;
    while(!isempty(q)){
        int num=dequeue(q);
        for(int j=0;j<v;j++){
            if(graph[num][j]==1 && visited[j]==0){
                enqueue(q,j);
                visited[j]=1;
                printf("%d",j);
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
        q.arr=(int *) malloc(v*sizeof(int));
        q.rear=-1;
        q.front=-1;
        bfs(&q,graph);
    return 0;
}

void quicksort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    else{
        int p=partition(arr,s,e);
        quicksort(arr,s,p-1);
        quicksort(arr,p+1,e);
    }
}

int partition(int arr[],int s,int e){
    int i,j,pivotindex=s,pivot=arr[s],c=0;
    for(i=s;i<=e;i++){
        if(pivot>=arr[i]){
            c++;
        }
    }
    pivotindex=s+c;
    swap(arr[s],arr[pivotindex]);
    i=s,j=e;
    while(i<pivotindex && j>pivotindex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>=pivot){
            j--;
        }
        if(i<pivotindex && j>pivotindex){
            swap(arr[j],arr[i]);
            i++,j--;
        }
    }
    return pivotindex;
}

void chainmatrix(int matrix[n][n],int s[n][n],int p[]){
    int i,j,k,min;
    for(i=0;i<n;i++){
        m[i][i]=0;
    }
    for(i=n-1;i>0;i--){
        for(j=i+1;j<=n;j++){
            for(k=i;k<j;k++){
                min=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
                if(min<m[i][j]){
                    m[i][j]=min;
                    s[i][j]=k;
                }
            }
        }
    }
}

void shortestpath(int graph[v][v]){
    int i,j,k;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            for(k=0;k<v;k++){
                graph[i][j]=min(graph[i][j],graph[i][k]+graph[k][j]);
            }
        }
    }
}