/* Problem 4_5                                                                  */
/* A C program to work with a string of up to 500 chars to                      */
/* - write string to file                                                       */
/* - read string from file                                                      */
/* - change upper case to lower and lower case to upper                         */
/* - leave non-letters unchanged                                                */
/* - keep track of how many non-letters are in the string                       */
#include <stdio.h>
#include <string.h>

#define MAX_STRING_SIZE 500

main()
{
  int stringSize=0; /* size of string input by user */
  char string[MAX_STRING_SIZE+1]; /* original string.  Allow space for 500 chars plus null char to terminate string */
  char newString[MAX_STRING_SIZE+1]; /* new string */
  int numNonLetters=0;
  int i;
  FILE *filePtr;   // declaring file pointer
  filePtr=fopen("myFile.txt","w");

  printf("Please enter a string of up to 500 characters, with no spaces \n");
  scanf("%s",string);   /* note that if the user enters a string of length > 500, the program will crash */
  fprintf(filePtr,"%s\n",string);   // write to file
  printf("Thanks, the original string is %s\n",string);
  fclose(filePtr);

  // Question 7 starts here
  char stringFile[MAX_STRING_SIZE+1];
  FILE *fin;   // declaring file pointer
  fin=fopen("myFile.txt","r");
  fgets(stringFile,MAX_STRING_SIZE+1, fin);
  stringSize = strlen(stringFile);  /* get the length of the string */
  printf("string length is %d\n", stringSize);

  for(i=0; i<stringSize; i++ )
  {
    if( stringFile[i]>='A' && stringFile[i]<='Z' )
    {
      newString[i] = stringFile[i] + 32;  /* change upper case to lower case */
    }
    else if ( stringFile[i]>='a' && stringFile[i]<='z' )
    {
      newString[i] = stringFile[i] - 32;  /* change lower case to upper case */
    }
    else
    {
      newString[i] = stringFile[i];
	  numNonLetters = numNonLetters + 1;  /* if it was neither upper case nor lower case, then it isn't a letter, so add it to the total so far */
    }
  }
  newString[stringSize] = '\0';  /* add terminating null to new string (scanf will have added this to the original string - this is not strictly necessary */

  printf("The new string is\n%s\n",newString);
  printf("The number of non-letters in the string is %d\n", numNonLetters);

  system("pause");
}




