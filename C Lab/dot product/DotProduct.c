#include <stdio.h>
#include <stdlib.h>

int * allocVector(int n)
{
    return (int *)malloc(n*sizeof(int));
}

int dotproduct(int * V1, int * V2, int n)
{
    // write code here
    int result,i;

    for (i = 0; i < n; i++)
    {
        result += V1[i] * V2[i];
    }

    return result;


    return 0;
}

int main()
{
    const int n = 10;
    int i;
    int * R = allocVector(n);
    int * C = allocVector(n);

    printf("First Vector Contains:");
    for (i = 0; i < n; i++){
        R[i] = i;
        printf("%d ", R[i]);
    }
    printf("\n");

    printf("The Second Vector Contains:");
    for (i = 0; i < n; i++){
        C[i] = 2*i;
        printf("%d ", C[i]);
    }
    printf("\n");

    printf("The dot product of the vectors is %d\n",dotproduct(R,C,n));
    return 0;
}
