/* A program to read in 4 marks for each of 10 students */
/* from a file "marks.txt", and write out all the marks and the average mark for each student to the   */
/* screen.  Write helpful text along with the output to the screen, and format the   */
/* average marks appropriately.                                                      */
#include <stdio.h>
main()
{
      FILE *myFile;
      float average;
      float mark1, mark2, mark3, mark4;
      int i;
      myFile=fopen("marks.txt","r");
      printf("Marks\t\t\t\t\t\t\t|Average Mark\n");
      for(i=0; i<10; i++)  // assume there will be 10 students, therefore a row for each student
      {
             fscanf(myFile,"%f %f %f %f",&mark1,&mark2,&mark3,&mark4);  //assume there will be 4 marks on each row
             average=(mark1+mark2+mark3+mark4)/4;
             printf("%6.2f %6.2f %6.2f %6.2f\t\t\t\t|%6.2f\n",mark1,mark2,mark3,mark4,average);
      }
      fclose(myFile);

}


