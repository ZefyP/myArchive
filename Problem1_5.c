/* program to opens a file first.txt for appending, then writes the string */
/* "an extra line\n" to the opened file and finally close it.  Use program */
/* above to display the new contents of the file                           */
#include <stdio.h>
main()
{
      FILE *myFile;
      myFile=fopen("first.txt","a");  // open first.txt for appending - first.txt much be in same folder as C program
      fprintf(myFile,"An extra line\n");
      fclose(myFile);
}

