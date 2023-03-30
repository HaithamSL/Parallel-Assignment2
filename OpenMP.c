#include <stdio.h>
#include <stdlib.h>
#include <omp.h>

#define M 3
#define K 2
#define N 3

int A[M][K] = {{1,4}, {2,5}, {3,6}};
int B[K][N] = {{8,7,6}, {5,4,3}};
int C[M][N];

int main(int argc, char *argv[]) {

   int i,j,n;
   #pragma omp parallel for private(i,j,n) shared(A,B,C)
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         int sum = 0;
         for(n = 0; n < K; n++){
            sum += A[i][n] * B[n][j];
         }
         C[i][j] = sum;
      }
   }

   //Prints the result matrix
   for(i = 0; i < M; i++) {
      for(j = 0; j < N; j++) {
         printf("%d ", C[i][j]);
      }
      printf("\n");
   }
}
