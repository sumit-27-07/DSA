#include<stdio.h>
void swap(float *a,float *b){
    float temp=*a;
    *a=*b;
    *b=temp;
}
int main(){
    int n;
    printf("Number of elements:");
    scanf("%d",&n);
    int i;
    float ratio[n],weight[n],cost[n];
    printf("Enter weight of elements:");
    for(i=0;i<n;i++){
        scanf("%f",&weight[i]);
    }
    printf("Enter cost of elements:");
    for(i=0;i<n;i++){
        scanf("%f",&cost[i]);
    }
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
    float capacity;
    float profit=0.0;
    printf("Enter knapsack capacity:");
    scanf("%f",&capacity);
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
    printf("Total profit:%f",profit);
    return 0;
}