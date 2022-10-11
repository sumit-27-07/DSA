#include<stdio.h>
int main(){
    int arr[10],sum=0,i,j,n,num;
    printf("Enter number of elements in array:");
    scanf("%d",&n);
    printf("Enter elements of array:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    printf("Enter sum of subarray:");
    scanf("%d",&num);
    for(i=0;i<n;i++){
        sum=0;
        for(j=i;j<n;j++){
            sum=sum+arr[j];
            if(sum==num){
                printf("Sum of Subarray from position %d to %d = %d\n",i+1,j+1,sum);
                break;
            }
        }
    }
    return 0;
}