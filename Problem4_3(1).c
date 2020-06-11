/* Problem 3-4.c                                                              */
/* C program that declares three strings as character arrays each of size 50. */
/* Input a string into the first character array.  Input another string into  */
/* the second character array.  In the program, compare the two strings and   */
/* say whether or not they are equal, and find and state the length of each   */
/* string.  Concatenate the first string with the second string.  Copy the    */
/* concatenated string into the third string and print it out.                */
#include <stdio.h>
#include <string.h>
#define MAX 50
main()
{
      char s1[MAX],s2[MAX],s3[MAX];
      int length1,length2,isequal;
      //fflush(stdin);
      printf("Enter string 1 (length<=20)\n");
      //scanf("%s",s1);
      gets(s1);                        // use gets to recognise a string with spaces

      printf("Enter string 2 (length<=20)\n");
      //fflush(stdin);
      //scanf("%s",s2);
      gets(s2);

      isequal=strcmp(s1,s2);

      if(isequal==0)      //checking if strings are the same
      {
            printf("The two strings are equal.\n");
      }
      else
      {
            printf("The two strings are not equal.\n");
      }

      length1=strlen(s1);
      length2=strlen(s2);
      printf("The length of string 1 is %d.\n",length1);
      printf("The length of string 2 is %d.\n",length2);

      if(length1+length2+1 <= MAX)        //concatenating the strings, and copying this into a new string variable
      {
            strcat(s1,s2);
            strcpy(s3,s1);
            printf("The concatenated string is\n%s\n",s3);  //printing the concatenated string
      } else
      {
            printf("Sorry, the strings are too long for the concatenation to take place.\n");
      }

}

