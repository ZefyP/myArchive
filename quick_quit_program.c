/*quick template for quit/continue program*/
#include <stdio.h>

bool quit(char c);

int main()
{ 
  int flag =0;

do 
  {
	
	/*your code here*/

   
    

  
  }while(!quit());
   return 0;

}

quit(char c)
{
	printf("\n press 'q' to quit, 'y' to continue:");
    scanf(" %c", &c);
	
	if(c =='q')
		int  flag = true;
    if(c =='y')
		flag = false;
  
	return flag;
}


