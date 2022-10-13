#include<stdio.h>
int main(){
    int x,n,arr[20],i,j;
    printf("How many numbers wants in array:");
    scanf("%d",&n);
    printf("Enter %d numbers of array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=0;i<n;i++){
        /*for(j=i;j>0;j--){
            if(arr[j]<arr[j-1]){
              x=arr[j-1];
              arr[j-1]=arr[j];
              arr[j]=x;
            }
        }*/
        x=arr[i];
        j=i-1;
        while(arr[j]>x && j>=0){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=x;
    }
    printf("Sorted array:");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}