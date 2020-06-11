/* program to generate the first n numbers of the Fibonacci series */
/* F0=0, F1=1, F2=1, F3=2....   FN = F(N-1)+F(N-2)                */
#include <stdio.h>
int main()
{
      int number=0; /* length of series to generate */
      int FN;       /* FN                           */
      int FNMinus1=1,FNMinus2=0;  /*F(N-1) and F(N-2);  these will be the 1st two values in the series */
      int i; /* loop control variable */
      printf("Fibonacci series (starting from 0)\n");

      do
      {
            printf("...please enter the length (>2) of the series to generate\n");
            scanf("%d",&number);
      }while(number<3);


      printf("The series is:\n");
      printf("%d, %d",FNMinus2,FNMinus1);  // first two values in series
      for(i=2; i<number; i++)
      	{
           FN=FNMinus2+FNMinus1;
           printf(", %d",FN);  // next value in series
           FNMinus2=FNMinus1;  // prepare the two values for the next time around the loop
           FNMinus1=FN;
      	}

      printf("\nEnd of Fibonnaci sequence");
      return 0;
}



