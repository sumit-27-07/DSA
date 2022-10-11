#include<stdio.h>
void print(int sum){
    if(sum>0){
        printf("Number of units of water filled:%d",sum);
    }
    else{
        printf("No water filled");
    }
}
int main(){
    int k,arr[20],i,j,n,sum=0;
    printf("Enter number of elements in array:");
    scanf("%d",&k);
    printf("Enter elements of array:\n");
    for(i=0;i<k;i++){
        scanf("%d",&arr[i]);
    }
    if(arr[0]>arr[k-1]){
        n=arr[k-1];
    }
    else if(arr[0]==arr[k-1]){
        n=arr[k-1];
    }
    else{
        n=arr[0];
    }
    for(j=1;j<=k-2;j++){
        sum=sum+(n-arr[j]);
    }
    print(sum);
    return 0;
}