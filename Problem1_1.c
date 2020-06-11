/* Program to input 2 numbers and report their sums and product in the form of 2 equations */
#include <stdio.h>
int main()
{
      int num1, num2, sum, product;
      printf("please input two integer numbers (each <1000)...\n");
      scanf("%d %d",&num1,&num2);  /* note it would be good practice to check if these are in range*/
      sum = num1+num2;
      product = num1*num2;
      printf("%d + %d = %d\n",num1,num2,sum);   // adding the numbers
      printf("%d * %d = %d\n",num1,num2,product); // multiplying the numbers
      return 0;
}
