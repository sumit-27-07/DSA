#include<stdio.h>
int m[9][9],s[9][9];
#define inf 99999
void chainmatrixmul(int arr[],int n){
    int x,k,i,j,p;
    for(i=1;i<=n;i++){
        m[i][i]=0;
    }
    for(i=n;i>0;i--){
        for(j=i+1;j<=n;j++){
                for(k=i;k<j;k++){
                    x=m[i][k]+m[k+1][j]+arr[i-1]*arr[k]*arr[j];
                    if(x<m[i][j]){
                        m[i][j]=x;
                        s[i][j]=k;
                    }
                }
        }
    }
    printf("Minimum number of multiplication:%d\n",m[1][n]);
}
int main(){
    int n;
    printf("Enter number of matrix:");
    scanf("%d",&n);
    int i,j,arr[n];
    printf("Enter the dimension array:\n");
    for(i=0;i<n+1;i++){
        scanf("%d",&arr[i]);
    }
    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            m[i][j]=inf;
            s[i][j]=0;
        }
    }
    
    chainmatrixmul(arr,n);
    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d  ",m[i][j]);
        }
        printf("\n");
    }

    for(i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("%d  ",s[i][j]);
        }
        printf("\n");
    }
    return 0;
}