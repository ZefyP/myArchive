/* Problem7-1.c                                                                     */
/* Modify program 1 from problem sheet 6, to read in 4 marks for each of 10 students */
/* from a file "marks.txt", and write out the average mark for each student to the   */
/* screen.  Write helpful text along with the output to the screen, and format the   */
/* average marks appropriately.  The modification is to calculate the average        */
/* in a function using an array                                                     */
#include <stdio.h>

#define SIZE 4
float average(float *m);
main()
{
      FILE *myFile;
      float av;
      float mark1[SIZE];
      int i,j;
      myFile=fopen("marks.txt","r");
      printf("Marks\t\t\t\t\t\t\t|Average Mark\n");
      for(i=0; i<10; i++)
      {
             fscanf(myFile,"%f %f %f %f",&mark1[0],&mark1[1],&mark1[2],&mark1[3]);
             av=average(mark1);   //array name points to memory address of first element, so don't need &
             for(j=0; j<SIZE;j++){
                printf("%6.2f ",mark1[j]);
             }
             printf("%\t\t\t\t|%6.2f\n",av);
      }
      fclose(myFile);
}

// function which calculates the average using pointers
float average(float *m)
{
    float total = 0.0;
    int i;

    for(i=0;i<SIZE;i++){
      total = total + *(m+i);
    }
    return total/SIZE;
}



