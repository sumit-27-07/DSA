#include<stdio.h>
int main(){
    int n,arr[20],i,j,a,swap,p=0;
    printf("How many numbers wants in array:");
    scanf("%d",&n);
    printf("Enter %d numbers of array:",n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    for(i=n-1;i>=0;i--){
        swap=0;
        for(j=0;j<=i;j++){
            if(arr[j]>arr[j+1]){
                a=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=a;
                swap++;
            }
        }
        if(swap==0){
            break;
        }
        p++;
    }
    printf("Sorted array:");
    for(i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    printf("\nNumber of passes:%d",p);
}