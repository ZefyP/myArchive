/* Problem 7-2.c                                           */
/* A program which inputs a list of 5 values into a       */
/* float array, then calls a function to sort the list     */
/* in ascending order.   The function prototype should     */
/* be                                                      */
/*void sort(float anArray[]);                            */
#include <stdio.h>

#define SIZE 5

void sort(float anArray[]);

main()
{
      float myArray[SIZE];
      int i;
      printf("please enter %d float values: \n",SIZE);
      for(i=0; i<SIZE; i++)
      {
        scanf("%f", &myArray[i]);
      }
      sort(myArray);
      printf("the values sorted in ascending order are:\n");
      for(i=0; i<SIZE; i++)
      {
        printf("%0.2f\n", myArray[i]);
      }

}
/* function void sort(float array[]);                                */
/* to sort the contents of an array                                    */
/* sort in ascending order                                             */
/* original array gets overwritten with sorted array                   */
/* (this is a bubble sort)                                             */
void sort(float anArray[])
{
     float temp;
     int i, j;
     for(i=0; i<SIZE; i++)
     {
              for(j=0; j<SIZE-1; j++)
              {
                    if(anArray[j]>anArray[j+1])
                    {
                         temp=anArray[j+1];
                         anArray[j+1]=anArray[j];
                         anArray[j]=temp;
                    }
              }
     }
}





