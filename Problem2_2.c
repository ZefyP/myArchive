/* program 2 that states if roots of quadratic equation
are real and equal, real or complex.  */
#include <stdio.h>
//#include <math.h>
int main()
{
      int a, b, c;

      //cEntering values for a, b and c
      printf("Enter values for a, b and c (separated by a space)\n");
      scanf("%d %d %d", &a, &b, &c);
      printf("a=%d, b=%d, c=%d\n",a,b,c);

      printf("Quadratic root calculator:\n");

      // calculating if the roots are real, complex or real and equal
      if(b*b>4*a*c){
        printf("roots are real\n");
      }
      else if(b*b==4*a*c){
        printf("roots are real and equal\n");

      }
      else{
        printf("roots are complex\n");
      }

      return 0;
}
