/* quick template for quit/continue program*/

#include <stdio.h>


int main()
{ 
  int num,flag =0;
  char ch;

do 
  {
    printf("Enter num:");
    scanf("%d", &num);

    printf("\n press 'q' to quit, 'y' to continue:");
    scanf(" %c", &ch);

    if(ch =='q')
      flag = 1;
    if(ch =='y')
      flag = 0;

  
  }while(flag==0);
   return 0;

}

