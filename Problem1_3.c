/* program to input the radius of a circule and calculate its diameter, circumference and area */
/* d = 2*r; c = 2*PI*r; a = PI * r*r                                                  */
#include <stdio.h>
#define PI 3.14159265359  // use a constant value for PI
int main()
{
      float r, d, c, a;
      printf("please input radius..\n");
      scanf("%f",&r);
      d=2*r;  // standard formula
      c=2*PI*r;
      a=PI*r*r;
      printf("diameter = %.2f\n",d);  // print to two decimal places using %.2f
      printf("circumference = %.2f\n",c);
      printf("area = %.2f\n",a);
      return 0;
}
