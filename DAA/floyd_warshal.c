#include<stdio.h>
#define v 4
#define inf 999
int min(int a,int b){
    int temp;
    if(a>b){
        return b;
    }
    else{
        return a;
    }
}
void short_path(int graph[v][v]){
    int i,j,k;
    for(i=0;i<v;i++){
        for(j=0;j<v;j++){
            for(k=0;k<v;k++){
                graph[i][j]=min(graph[i][j],(graph[i][k]+graph[k][j]));
            }
        }
    }
}
int main(){
    int graph[v][v]={{0,5,inf,10},
                     {inf,0,3,inf},
                     {inf,inf,0,1},
                     {inf,inf,inf,0}};
    short_path(graph);
    printf("All pair shortest path:\n");
    for(int i=0;i<v;i++){
        for(int j=0;j<v;j++){
            if(graph[i][j]==inf){
                printf("INF  ");
            }
            else{
                printf("%d  ",graph[i][j]);
            }
        }
        printf("\n");
    }
    return 0;
}