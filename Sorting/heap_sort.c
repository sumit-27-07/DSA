#include<stdio.h>
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void heapify(int arr[],int n,int i){
    int largest=i;
    int left=2*i;
    int right=2*i+1;
    if(left<=n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<=n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,n,largest);
    }
}
void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(&arr[size],&arr[1]);
        size--;
        heapify(arr,size,1);
    }
}
int main(){
    int arr[6]={-1,4,5,3,2,1};
    int i,n=5;
    for(i=n/2;i>0;i--){
        heapify(arr,n,i);
    }
    heapsort(arr,n);
    printf("Sorted array:");
    for(i=1;i<=n;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}