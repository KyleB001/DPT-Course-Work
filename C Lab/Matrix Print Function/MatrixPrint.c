#include <stdio.h>
#include <stdlib.h>
int * allocVector(int n)
{
    return (int *)malloc(n*sizeof(int));
}

int ** allocMatrix(int m, int n)
{
    int ** newM = (int **)malloc(m*sizeof(int *));
    int i;
    for (i = 0; i < m; i++)
    newM[i] = allocVector(n);
    return newM;
}
void writeMatrix(int ** M, int m, int n)
{
  int i, j;
  printf("Matrix contains:\n");
  for (i = 0; i < m; i++) {
    for (j = 0; j < n; j++)
      printf("%d ", M[i][j]);
    printf("\n");
  }
  printf("\n");
}
int ** transpose(int ** M, int m, int n)
{
  int ** MT;
  int i, j;
  MT = allocMatrix(n, m);
  for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
      MT[j][i] = M[i][j];
  return MT;
}
int main()
{
    // m is the number of rows in the matrix
    const int m = 10;
    // n is the number of columns in the matrix
    const int n = 8;
    int i,j;
    // Allocate the matrix M
    int ** M = allocMatrix(m,n);
    // Initialise the Matrix
    for (i = 0; i < m; i++)
    for (j = 0; j < n; j++)
    M[i][j] = i*10+j;
    // Print the initial Matrix
    writeMatrix(M,m,n);
    // Transpose the matrix
    int ** MT = transpose(M, m, n);
    // Print the transposed Matrix
    writeMatrix(MT,n,m);
    return 0;
}