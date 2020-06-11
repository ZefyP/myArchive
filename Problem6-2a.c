/* Problem6-2a.c to solve a quadratic equation, using coefficients input by the user. */
/* Prompt the user to input three float numbers A, B and C, which will be the        */
/* coefficients in a quadratic equation.  These are the values that will be accepted */
/* for A, B and C:                                                                   */
/*	A > -1.0                                                                         */
/* -10.0 < B < 10.0                                                                  */
/*	C < 0.1                                                                          */
/* If the user inputs an out-of-range value, the program should prompt the user for  */
/* the value again and input the value again.                                        */
/* Calculate y(x), for x = 0, 1, 2, … , 49 in a function using pass by address for y.*/
/* Display a table of the x and y values, with the x values as integers and the      */
/* y values as floating point numbers shown to 1 decimal place.  Your table should   */
/* have a header row to label the columns as x and y(x).                             */

#include <stdio.h>

#define SIZE 50
#define A_MIN -1.0
#define B_MAX 10.0
#define B_MIN -10.0
#define C_MAX 0.1

void quadratic(int x, float A, float B, float C, float *y);

main()
{
  int x, xMaxY=0;
  float y, maxY=0;
  float A,B,C;

  printf( "Quadratic equation calculation\n" );
  /* input coefficients, and check that each is in range */
  do
  {
  	printf( "Please input the coefficient A (A > %.1f)\n", A_MIN );
    scanf( "%f",&A );
  } while( A<=A_MIN );
  do
  {
    printf("Please input the coefficient B (%.1f < B < %.1f)\n", B_MIN, B_MAX);
    scanf( "%f",&B );
  } while( B<=B_MIN || B>=B_MAX );
  do
  {
    printf("Please input the coefficient C (C < %.1f)\n", C_MAX);
    scanf( "%f",&C );
  } while( C>=C_MAX );

  /* print header row */
  printf(" x    y(x)\n");
  printf("__    ____\n");

  /* for each x in range, calculate y and print x and y */
  for( x=0; x<SIZE; x++)
  {
    quadratic(x,A,B,C,&y); /*   A*x*x + B*x + C */
    printf ("%2d    %.1f\n",x,y );
  } /* end for */

/* that's it  - end main */
}
/* function float quadratic(int x, float A, float B, float C);  */
void quadratic(int x, float A, float B, float C, float *y)
{
      *y= A*x*x + B*x + C;
}

