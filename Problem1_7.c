/* program that prints a table to the screen */
/* The table shows 4 marks for 2 students */


#include <stdio.h>
int main()
{
      int mark1, mark2, mark3, mark4,mark11, mark22, mark33, mark44;

      printf("please enter marks for first student, one at a time\n");

      printf("enter mark:\n");
      scanf("%d",&mark1);
      printf("enter mark:\n");
      scanf("%d",&mark2);
      printf("enter mark:\n");
      scanf("%d",&mark3);
      printf("enter mark:\n");
      scanf("%d",&mark4);

      printf("please enter marks for second student, one at a time\n");

      printf("enter mark:\n");
      scanf("%d",&mark11);
      printf("enter mark:\n");
      scanf("%d",&mark22);
      printf("enter mark:\n");
      scanf("%d",&mark33);
      printf("enter mark:\n");
      scanf("%d",&mark44);


      printf("\t Mark1   Mark2  Mark3  Mark4 \n");
      printf("Student1 %d \t %d \t %d \t %d\n", mark1, mark2, mark3, mark4);
      printf("Student2 %d \t %d \t %d \t %d", mark11, mark22, mark33, mark44);
      return 0;
}
