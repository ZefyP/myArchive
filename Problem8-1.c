/* Problem8-1.c for problem 1 on problem sheet 7
A program to use calloc to dynamically reserve space for a 1D float array.
Prompt the user to enter the size from the keyboard.   After you have
reserved space for the array, prompt the user to enter the array elements
one by one.  Echo the elements to the screen in reverse order.
  */

#include <stdio.h>
#include <stdlib.h>

main()
{
      float *listPtr;
      int listSize;
      int i;
      printf("how big do you want the list to be?\n");
      scanf("%d",&listSize);
      listPtr=(float *)calloc(listSize,sizeof(float));
      for(i=0; i<listSize; i++)
      {
               printf("enter a float value for list element %d: ",i+1);
               scanf("%f",(listPtr+i));
      }
      printf("the numbers you entered were: \n");
      for(i=0; i<listSize; i++)
      {
               printf("%.2f\n",*(listPtr+i));
      }

}



