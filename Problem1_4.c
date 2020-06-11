/* program that opens a file called first.txt for writing, then writes */
/* hello world to the file                                             */
#include <stdio.h>
main()
{
      FILE *myFile;
      myFile=fopen("first.txt","w");// open first.txt for writing - this will be in the same folder as the c program
      fprintf(myFile,"Hello World\n");
      fclose(myFile);
}

