//Problem8-3.c
// A C program to define a struct matrix, with members
// float mat[10][10];  // to hold matrix of size up to 10x10
// int rows;               // to hold the number of rows in mat
// int cols;                // to hold the number of cols in mat
// In main( ), declare matA of type matrix,
// In a function, prompt the user for the number of rows and columns and input data into matA
// In another function, output matA to the screen.
// Main will need to call each function.

#include <stdio.h>

struct matrix
{
       float mat[10][10]; // to hold matrix of size up to 10x10
       int rows;          // to hold the number of rows in mat
       int cols;          // to hold the number of cols in mat
};

void inputMatrix(struct matrix *matA);
void displayMatrix(struct matrix matA);

main()
{
     struct matrix matA;
     inputMatrix(&matA);    // calling input function
     displayMatrix(matA);   // calling display function

}
// function to input matrix
void inputMatrix(struct matrix *matA)
{
     int i,j;
     printf("please enter the number of rows in matA:  ");   //enter rows
     scanf("%d",&((*matA).rows));
     printf("please enter the number of columns in matA:  ");   // enter columns
     scanf("%d",&(matA->cols));
     printf("please enter the contents of matA, one row at a time\n");
     for(i=0; i<(*matA).rows; i++)       // enter elements one row at a time
     {
              printf("Row %d:  ",i+1);
              for(j=0; j<(*matA).cols; j++)
              {
                    scanf("%f",&((*matA).mat[i][j]));

              }
     }
}
// function to display matrix
void displayMatrix(struct matrix matA)
{
     int i,j;
     printf("The matrix is:\n");
     for(i=0; i<matA.rows; i++)
     {
              printf("Row %d:  ",i+1);
              for(j=0; j<matA.cols; j++)
              {
                    printf("\t%8.2f",matA.mat[i][j]);
              }
              printf("\n");
     }
}
