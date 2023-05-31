#include<stdio.h>
# define m 10
void swap(float *a,float *b){
    float temp=*a;
    *a=*b;
    *b=temp;
}

void knapsack(float weight[],float cost[],float capacity,int n){
    float ratio[n];
    int i,j;
    for(i=0;i<n;i++){
        ratio[i]=cost[i]/weight[i];
    }
    for(i=0;i<n;i++){
        int max=i;
        for(int j=i+1;j<n;j++){
            if(ratio[j]>ratio[max]){
                max=j;
            }
        }
        swap(&ratio[i],&ratio[max]);
        swap(&cost[i],&cost[max]);
        swap(&weight[i],&weight[max]);
    }
    
    float profit=0.0;
    for(i=0;i<n;i++){
        if(capacity<weight[i]){
            profit += (capacity/weight[i])*cost[i];
            break;
        }
        else{
            capacity -= weight[i];
            profit += cost[i];
        }
    }
    printf("Total profit:%.2f",profit);
}

int main(){
    int n;
    printf("Number of elements:");
    scanf("%d",&n);
    int i;
    float weight[n],cost[n];
    
    for(i=0;i<n;i++){
        printf("Element[%d]\n",i+1);
        printf("Enter weight:");
        scanf("%f",&weight[i]);
        printf("Enter cost:");
        scanf("%f",&cost[i]);
    }

    float capacity;
    printf("Enter knapsack capacity:");
    scanf("%f",&capacity);

    knapsack(weight,cost,capacity,n);
    
    return 0;
}