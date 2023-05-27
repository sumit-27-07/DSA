#include<stdio.h>

int partition(int *arr,int s,int e){
    int c=0,pivot,pivotindex;
    pivot=arr[s];
    for(int i=s+1;i<=e;i++){
        if(pivot>=arr[i]){
           c++; 
        }
    }
    pivotindex=s+c;

    int temp;
    temp=arr[pivotindex];
    arr[pivotindex]=arr[s];
    arr[s]=temp;

    int i=s,j=e;
    while(i<pivotindex&&pivotindex<j){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotindex&&j>pivotindex){
            int n;
            n=arr[i];
            arr[i]=arr[j];
            arr[j]=n;
            i++;
            j--;
        }
    }
    return pivotindex;
}
void quicksort(int arr[],int s,int e){
    if(s>=e){
        return;
    }
    int p;
    p=partition(arr,s,e);
    quicksort(arr,s,p-1);
    quicksort(arr,p+1,e);
}
int main(){
    int arr[20];
    int n;
    printf("How many numbers wants in array:");
    scanf("%d",&n);
    printf("Enter elements of array:\n");
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("Sorted array:");
    for(int i=0;i<n;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}