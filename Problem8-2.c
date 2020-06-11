//Problem8-2.c
// A C program to define a struct matrix, with members
// float mat[10][10];  // to hold matrix of size up to 10x10
// int rows;               // to hold the number of rows in mat
// int cols;                // to hold the number of cols in mat
// In main( ), declare matA of type matrix, prompt the user
// for the number of rows and columns, input data into matA, output matA to the screen
// add the matrix to itself and display to the screen
#include <stdio.h>

struct matrix
{
       float mat[10][10]; // to hold matrix of size up to 10x10
       int rows;          // to hold the number of rows in mat
       int cols;          // to hold the number of cols in mat
};

main()
{
     int i,j, choice, quit;
     struct matrix matA;

   do{

    do{
        printf("please enter the number of rows in matA (<10):  ");
        scanf("%d",&matA.rows);
    }while(matA.rows<0||matA.rows>10);


    do{
        printf("please enter the number of columns in matA(<10):  ");
        scanf("%d",&matA.cols);
    }while(matA.cols<0||matA.cols>10);

    printf("please enter the contents of matA, one row at a time\n");
    for(i=0; i<matA.rows; i++)
        {
            printf("Row %d:  ",i+1);
            for(j=0; j<matA.cols; j++)
            {
                scanf("%f",&matA.mat[i][j]);
            }
        }

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

        printf("Adding the matrix to itself.\n");
        for(i=0; i<matA.rows; i++)
        {

            for(j=0; j<matA.cols; j++)
            {
                matA.mat[i][j] = matA.mat[i][j] + matA.mat[i][j];
            }

        }

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



        fflush(stdin);
        printf("Would you like to quit? Yes=1, No = 0.\n");
        scanf("%d",&quit);


     }while(quit==0);

}

