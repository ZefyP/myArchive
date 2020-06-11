/* a program that enters a temperature in degrees centigrade and converts it to degrees Fahrenheit */
/* Formula. °C x 9/5 + 32 = °F                                                                     */

#include <stdio.h>
int main()
{
      float centigrade, fahrenheit;
      printf("please enter temperature in degrees centigrade..\n");
      scanf("%f",&centigrade);
      fahrenheit=centigrade* 9.0/5.0 + 32.0;  // ujse standard conversion formula
      printf("in fahrenheit that is: %.1f\n",fahrenheit);
      return 0;
}


