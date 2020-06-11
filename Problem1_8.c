/* Program to input a number and without unnecessary calculations output its square, cube and fourth power */


#include <stdio.h>
int main()
{
      int number, square, cube, fourth;
      printf("please input an integer number\n");
      scanf("%d",&number);
      square=number*number;
      cube=square*number;  // reuse the square variable to reduce the number of calculations
      fourth=cube*number;  // reuse the cube variable to reduce the number of calculations
      printf("square = %d\n",square);
      printf("cube = %d\n",cube);
      printf("fourth = %d\n",fourth);
      return 0;
}

