/* Problem6-1a.c
Read in four marks for each of 10 students from the file “marks.txt”
and write out the average mark for each student to the screen.  You should
calculate the average mark in a function, using pass by address.
/*                                                      */
#include <stdio.h>
void average(float m1, float m2, float m3, float m4, float *meanMark);
main()
{
      FILE *myFile;
      float av;
      float mark1, mark2, mark3, mark4, meanMark=0;
      int i;
      myFile=fopen("matrix2.txt","r");
      printf("Matrix is:\t\t\t\t\t\t|Average Mark\n");
      for(i=0; i<10; i++)
      {
             fscanf(myFile,"%d %d %d %d",&mark1,&mark2,&mark3,&mark4);
             average(mark1,mark2,mark3,mark4,&meanMark);
             printf("%6.2f %6.2f %6.2f %6.2f\t\t\t\t|mean=%6.2f\n",mark1,mark2,mark3,mark4,meanMark);
             //printf("%6.2f %6.2f %6.2f %6.2f\t\t\t\t|mean=%6.2f\n",mark1,mark2,mark3,mark4,meanMark);
      }
      fclose(myFile);
}

void average(float m1, float m2, float m3, float m4, float *meanMark)
{
      *meanMark= (m1+m2+m3+m4)/4;

}



