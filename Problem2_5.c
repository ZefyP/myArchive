/* a program to read the file "first.txt" one word at a time, displaying them on the screen */
/* one word on a new line.  When the program reaches EOF, it should close the file and   */
/* terminate.                                                                               */
#include <stdio.h>
main()
{
      FILE *myFile;
      char c;
      myFile=fopen("matrix2.txt","r");  // open first.txt for reading - first.txt must be in same folder as c programme

      while(fscanf(myFile, "%c", &c)!=EOF){
        if(c==' ')
            c='\n';  // if c is a space, set c to a newline
        printf("%c",c);  // display the value of c on the screen

      }

      /*Alternatively you can do:
      do
      {
        c=fgetc(myFile);  // get a single character from the file, store it in the variable c
        if(c==' ')
            c='\n';  // if c is a space, set c to a newline
        putchar(c);  // display the value of c on the screen
      }while(c!=EOF);  // continue looping until an end of file was read for c*/

      fclose(myFile);

}
