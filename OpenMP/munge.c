#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#define CHUNKSIZE   10
#define N       100


int main( int argc, char *argv[] )
{

  double *x, *y;     /* the arrays                 */
  int    arraySize = 100000000;  
  int    i;
  int nthreads, tid, chunk;

  chunk = CHUNKSIZE;

  /* Allocate memory for the arrays. */
  x = (double *) malloc( (size_t) (  arraySize * sizeof(double) ) );
  y = (double *) malloc( (size_t) (  arraySize * sizeof(double) ) );

  /* Initialize x with some junk. */
  for ( i = 0; i < arraySize; i++ )
    {
      x[i] = ( (double) i ) / ( i + 1000 );
    }

#pragma omp parallel shared(x,y,arraySize) private(i)
  {
  #pragma omp parallel for 
  for ( i = 0; i < (arraySize-1); i++ )
    {
      y[i] = (x[i]/x[i+1]) + (x[i+1]*2.14) - (x[i]/5.84); 
    }
  }

  fprintf( stdout, "\nProgram successfully terminated.\n\n\a" );

  return(0);
}
