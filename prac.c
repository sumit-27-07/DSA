#include<stdio.h>

void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void merge(int arr[],int l,int m,int r){
    int n1=m-l+1,n2=r-m;
    int l1[n1],l2[n2],i,j;
    for(i=0;i<n1;i++){
        l1[i]=arr[l+i];
    }
    for(i=0;i<n2;i++){
        l2[i]=arr[m+i+1];
    }
    i=0,j=0;
    int k=l;
    while(i<n1 && j<n2){
        if(l1[i]<=l2[j]){
            arr[k]=l1[i];
            i++;
        }
        else{
            arr[k]=l2[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=l1[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k]=l2[j];
        j++;
        k++;
    }
}
void mergesort(int arr[],int l,int r){
    if(l<r){
        int m=(l+r)/2;
        mergesort(arr,l,m);
        mergesort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

void heapify(int arr[],int i,int n){
    int largest=i;
    int left=2*i,right=2*i+1;
    if(left<=n && arr[left]>arr[largest]){
        largest=left;
    }
    if(right<=n && arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(&arr[largest],&arr[i]);
        heapify(arr,largest,n);
    }
}
void heapsort(int arr[],int n){
    int size=n;
    while(size>1){
        swap(&arr[1],&arr[size]);
        size--;
        heapify(arr,1,size);
    }
}
int main(){
    int arr[6]={-1,5,4,3,2,1};
    int i,j,temp,n=5;
    //mergesort(arr,0,4);
    for(i=n/2;i>0;i--){
        heapify(arr,i,n);
    }
    heapsort(arr,n);
    printf("Sorted array:");
    for(i=1;i<6;i++){
        printf("%d  ",arr[i]);
    }
    return 0;
}