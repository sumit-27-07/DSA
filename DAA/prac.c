#include<stdio.h>
int main(){
    float arr[3];
    printf("Enter:");
    for(int i=0;i<3;i++){
        scanf("%f",&arr[i]);
    }
    printf("%f",arr[1]/arr[0]);
    return 0;
}