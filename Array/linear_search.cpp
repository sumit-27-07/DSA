#include<stdio.h>
int linearsearch(int arr[],int size,int number){
	for(int i=0;i<size;i++){
		if(arr[i]==number){
			return i;
		}
	}
	return -1;
}
int main(){
	int arr[10];
	int size,element,index;
	printf("Enter size of array:");
	scanf("%d",&size);
	printf("Enter elements of array:");
	for(int i=0;i<size;i++){
		scanf("%d",&arr[i]);
	}
	
	//linear search
	printf("Enter number for search:");
	scanf("%d",&element);
	index=linearsearch(arr,size,element);
	printf("%d present at index:%d",element,index);
	return 0;
}

