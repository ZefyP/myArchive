/* program that averages four marks */
#include <stdio.h>
#define NUMMARKS 4  // define constant number of marks
int main()
{
      float mark1, mark2, mark3, mark4,average,sum;
      int i;
      sum=0.0;
      printf("please enter marks, one at a time\n");

      printf("enter mark:\n");
      scanf("%f",&mark1);
      printf("enter mark:\n");
      scanf("%f",&mark2);
      printf("enter mark:\n");
      scanf("%f",&mark3);
      printf("enter mark:\n");
      scanf("%f",&mark4);
      sum=mark1+mark2+mark3+mark4;  // accumulate sum

      average=sum/NUMMARKS;  // divide accumulated sum by number of marks to get average
      printf("average was:  %.2f\n",average); // print average to 2 d.p.
      return 0;
}



