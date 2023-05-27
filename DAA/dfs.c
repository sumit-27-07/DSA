#include<stdio.h>
#define v 7
int graph[v][v]={{0,1,1,1,0,0,0},
                     {1,0,1,0,0,0,0},
                     {1,1,0,1,1,0,0},
                     {1,0,1,0,1,0,0},
                     {0,0,1,1,0,1,1},
                     {0,0,0,0,1,0,0}, 
                     {0,0,0,0,1,0,0}};
int visited[v]={0,0,0,0,0,0,0};
void dfs(int x){
    visited[x]=1;
    printf("%d",x);
    int j;
    for(j=0;j<v;j++){
        if(graph[x][j]==1 && visited[j]==0){
            dfs(j);
        }
    }
}
int main(){
    
    dfs(1);
    return 0;
}