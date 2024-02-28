#include <stdio.h>

#define MAX_SIZE 10

void multiplyMatrices(int A[][MAX_SIZE], int B[][MAX_SIZE], int C[][MAX_SIZE], int m, int n, int p) {
    int i, j, k;
    
    for (i = 0; i < m; i++) {
        for (j = 0; j < p; j++) {
            int sum = 0;
            for (k = 0; k < n; k++) {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = sum;
        }
    }
}

void displayMatrix(int matrix[][MAX_SIZE], int rows, int cols) {
    int i, j;
    
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], C[MAX_SIZE][MAX_SIZE];
    int m, n, p;
    int i, j;
    
    printf("Enter the number of rows and columns for matrix A: ");
    scanf("%d %d", &m, &n);
    
    printf("Enter the elements of matrix A:\n");
    for (i = 0; i < m; i++) {
        for (j = 0; j < n; j++) {
            scanf("%d", &A[i][j]);
        }
    }
    
    printf("Enter the number of rows and columns for matrix B: ");
    scanf("%d %d", &n, &p);
    
    printf("Enter the elements of matrix B:\n");
    for (i = 0; i < n; i++) {
        for (j = 0; j < p; j++) {
            scanf("%d", &B[i][j]);
        }
    }
    
    multiplyMatrices(A, B, C, m, n, p);
    
    printf("Resultant matrix C =\n");
    displayMatrix(C, m, p);
    
    return 0;
}
