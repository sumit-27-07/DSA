#include<stdio.h>
void create_arr(int arr[],int n);
int main(){
	int arr[10],n,p,i;
	printf("Enter number of element:");
	scanf("%d",&n);
	create_arr(arr,n);
	printf("Original Array :");
	for(i=0;i<n;i++){
		printf("\t%d\t",arr[i]);
	}
	printf("\nEnter position for delete a number:");
	scanf("%d",&p);
	for(i=p;i<n;i++){
		arr[i-1]=arr[i];
	}
	n=n-1;
	printf("Array after delete:");
	for(i=0;i<n;i++){
		printf("\t%d\t",arr[i]);
	}
	return 0;
}
void create_arr(int arr[],int n){
	printf("Enter elements of array:");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
}

