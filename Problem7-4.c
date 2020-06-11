/* Problem7-4.c                                                                     */
/* Modify program 1 from problem sheet 7, to read in 4 marks for each of 10 students */
/* from a file "marks.txt", and write out the average mark for each student to the   */
/* screen.  Write helpful text along with the output to the screen, and format the   */
/* average marks appropriately.  The modification is to calculate the average        */
/* in a function using a 2D array                                                     */
#include <stdio.h>

#define SIZE 4
#define STUDENTS 10
void average(float m[][SIZE], float *average);
main()
{
      FILE *myFile;
      float av[STUDENTS];
      float mark1[STUDENTS][SIZE];
      int i,j;
      myFile=fopen("marks.txt","r");
      for(i=0; i<10; i++)
      {
             fscanf(myFile,"%f %f %f %f",&mark1[i][0],&mark1[i][1],&mark1[i][2],&mark1[i][3]);  //storing marks in 2D array
      } //end reading from file
      average(mark1, av); //calling function

      for(i=0; i<10; i++){
        printf("The average marks are %0.2f\n", av[i]);
      }

      fclose(myFile);
}


void average(float m[][SIZE], float *average)
{
    float total = 0.0;
    int i,j;

    for(i=0;i<STUDENTS;i++){
        for(j=0;j<SIZE;j++){
            total = total + m[i][j];
            *(average+i) = total/SIZE;
        }
        total = 0;  //setting total to 0 for next student, uncomment this and see what happens
    }

}



