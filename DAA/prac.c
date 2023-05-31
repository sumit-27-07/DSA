#include<stdio.h>
#include<stdbool.h>
struct Graph{
    int weight;
    int src;
    int dest;
};
int parent[20];
# define inf 9999
int find(int i){
    while(parent[i]>-1){
        i=parent[i];
    }
    return i;
}
int union1(int x,int i){
    parent[x]=i;
}
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void kruskal(struct Graph g[],int v,int e){
    int i,j,min;
    for(i=0;i<e;i++){
        min=i;
        for(j=i;j<e;j++){
            if(g[min].weight >g[j].weight){
                min=j;
            }
        }
        swap(&g[i].src,&g[min].src);
        swap(&g[i].dest,&g[min].dest);
        swap(&g[i].weight,&g[min].weight);
    }
    for(i=0;i<v;i++){
        parent[i]=-1;
    }
    int p1,p2,cost=0;
    for(i=0;i<e;i++){
        p1=find(g[i].src);
        p2=find(g[i].dest);
        if(p1!=p2){
            union1(p1,p2);
            cost += g[i].weight;
            printf("%d->%d:%d\n",g[i].src,g[i].dest,g[i].weight);
        }
    }
    printf("Minimum cost:%d",cost);
}
int main(){
    int i,e,v;
    printf("Enter number of vertices and edges:");
    scanf("%d%d",&v,&e);
    struct Graph g[v];
    printf("Enter all vertex details:\n");
    for(i=0;i<v;i++){
        printf("Enter source vertex:");
        scanf("%d",&g[i].src);
        printf("Enter destination vertex:");
        scanf("%d",&g[i].dest);
        printf("Enter weight of edge:");
        scanf("%d",&g[i].weight);
    }
    kruskal(g,v,e);
    return 0;
}