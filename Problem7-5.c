/* Problem 7-5                                                                  */
/* A C program which inputs and displays a 5 by 3 matrix                      */
/* uses function void inputMatrix(float matA[][COLS] to input the matrix       */
/* uses function void outputMatrix(float m) to print the matrix                   */


#include <stdio.h>
#include <string.h>

#define ROWS 5
#define COLS 3


void inputMatrix(float matA[][COLS]);
void outputMatrix(float m);


main()
{
    int i,j;
    float matA[ROWS][COLS];

    inputMatrix(matA);

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            outputMatrix(matA[i][j]);
        }
        printf("\n");
    }


}

void inputMatrix(float matA[][COLS]){
    int i, j;

    printf("Enter elements for a 5 by 3 matrix, row by row:\n");

    for(i=0;i<ROWS;i++){
        for(j=0;j<COLS;j++){
            scanf("%f",&matA[i][j]);
        }
    }
}

void outputMatrix(float m){

    printf("%0.2f  ",m);


}
