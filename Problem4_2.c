/* Problem 4-2.c                                                              */
/* A C program to allow the user to enter a string, store the string in a     */
/* character array of size 50, display the string to the screen, and          */
/* using a for or while loop, search the character array for the character *, */
/* and, if found, display to the screen the array index at which it was found.*/
#include <stdio.h>
#include <string.h>
#define SIZE 50
main()
{
      char string[SIZE];
      int i,length;
      printf("Please enter a string up to length 49.\n");
      scanf("%s",string);
      length=strlen(string);
      if(length<SIZE)
      {
            for(i=0; i<length; i++)
            {
                  if(string[i]=='*')
                    printf("* found at index %d\n",i);
            }
      } else printf("invalid string length, program aborting\n");

}


