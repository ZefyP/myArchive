/* a program to read the first character from the file "first.txt" and displaying it on the screen */

#include <stdio.h>
main()
{
      FILE *myFile;
      char c;
      myFile=fopen("first.txt","r");  // open first.txt for reading - first.txt must be in same folder as c programme

      fscanf(myFile, "%c", &c);
      printf("%c",c);  // display the value of c on the screen


      /*Alternatively you can do:

        c=fgetc(myFile);  // get a single character from the file, store it in the variable c

        putchar(c);  // display the value of c on the screen  */

      fclose(myFile);

}
