#include<stdio.h>
void insert(int arr[],int m,int n,int num);
void create_arr(int arr[],int m);
int main(){
	int m,n,i,num,p;
	int arr[10];
	printf("Enter number of elements in array:");
	scanf("%d",&m);
	create_arr(arr,m);
	
	//Insert element in array
	printf("Enter position to insert a number:");
	scanf("%d",&n);
	printf("Enter a number:");
	scanf("%d",&num);
	insert(arr,m,n,num);
	m=m+1;
	printf("Array after insertion:");
	for(i=0;i<m;i++){
		printf("\t%d\t",arr[i]);
	}
	return 0;
}
void create_arr(int arr[],int m){
	printf("Enter elements of array:");
	for(int i=0;i<m;i++){
		scanf("%d",&arr[i]);
	}
}
void insert(int arr[],int m,int n,int num){
	for(int i=m-1;i>=n-1;i--){
		arr[i+1]=arr[i];
	}
	arr[n-1]=num;
}

