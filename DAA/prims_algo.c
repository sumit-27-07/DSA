#include<stdio.h>
#include<stdbool.h>
#define v 6
int selectMinVertex(int value[v],bool setMst[v]){
   int min=9999;
   int vertex;
   for(int i=0;i<v;++i){
      if(setMst[i]==false && value[i]<min){
         vertex=i;
         min=value[i];
      }
   }
   return vertex;
}
void findMst(int graph[v][v]){
   int parent[v];
   int value[v];
   bool setMst[v];
   for(int i=0;i<v;i++){
      value[i]=9999;
   }
   for(int i=0;i<v;i++){
      setMst[i]=false;
   }
   parent[0]=-1;
   value[0]=0;
   for(int i=0;i<v-1;++i){
      int u = selectMinVertex(value,setMst);
      setMst[u]=true;
      for(int j=0;j<v;++j){
        if(graph[u][j]!=0 && setMst[j]==false && graph[u][j]<value[j]){
         value[j]=graph[u][j];
         parent[j]=u;
        } 
      }
   }
   for(int i=1;i<v;++i){
      printf("%d->%d wt=%d \n",parent[i],i,graph[parent[i]][i]);
   }
}

int main(){
   int graph[v][v]={{0,4,6,0,0,0},
                    {4,0,6,3,4,0},
                    {6,6,0,1,8,0},
                    {0,3,1,0,2,3},
                    {0,4,8,2,0,7},
                    {0,0,0,3,7,0}};
   findMst(graph);
   return 0;
}