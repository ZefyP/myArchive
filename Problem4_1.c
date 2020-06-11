/* Problem 4-1.c                                                            */
/* A C program to allow the user to enter 20 numbers into an integer array. */
/* After all the numbers have been entered, display the list to the screen  */
/* in reverse order.                                                        */
#include <stdio.h>
#define SIZE 20
main()
{
      int array[SIZE];
      int i;
      printf("Please enter 20 integer numbers, one per row.\n");
      for(i=0; i<SIZE; i++)
      {
            scanf("%d",&array[i]);
      }
      printf("You entered, in reverse order:\n");
      for(i=SIZE-1; i>=0; i--)
      {
            printf("%d\n", array[i]);
      }

}
