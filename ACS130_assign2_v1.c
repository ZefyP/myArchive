/*
Created by: Zafeiria Pissaki 24.03.2020 Registration number:180162853
This program reads elements from a file and creates a matrix with dimensions selected by the user.
Then it creates a 2x2 sub-matrix so as to find the inverse. Coordinates of 2x2 chosen by the user.
The matrix size is determined by the user, and the maximum size of matrix allowed is 10x10.
The program uses a structure for the matrix, as well as several functions
for inputting the matrix, displaying the matrix, finding the inverse.
The program loops back to the start if the user wants to do this.

Must check if a 2x2 sub matrix can be formed, eg. size of original matrix 2x1.
It also checks for special cases such as a 1x1 matrix, as well as a
determinant = 0, since in this case the inverse does not exist.

An additional function, checkSize checks that an integer 0< and <11 has been entered.
If not the user is asked to enter an integer again and again.
Another function, nameMatrix is used to enter the single character name for the matrix as well as check that the character entered is a character between a-z or A-Z.*/

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct matrix
{
    char name; //to hold the 1 character name of the matrix
    float mValues[10][10]; // to hold the values in the matrix for up to 10x10
    int nrows;
    int ncols;
    int quit ;
};

//Function declarations
void matrixInput (struct matrix *matA, FILE *in);
void matrixDisplay(struct matrix mat);
float matrixDeterminant(struct matrix matA, struct matrix *mat, int *check);
void matrixInverse(struct matrix matA, float determinant, struct matrix *matD);
void nameMatrix(char *name);
int checkSize(int num ,int flag);

int main(){
    char another = '1' ;
    int i,j,n, trace,temp=0,OK,quit,flag=1;
    float determinant;
    struct matrix matA; //original matrix
    struct matrix matB; //sub-matrix 2x2
    struct matrix matC; //inverse matrix
    FILE *fin;


    while(another=='1')
    {
        fin = fopen("matrix2.txt","r");      //open file to read

    if (fin!=NULL)
    {   matrixInput(&matA,fin); //takes info from file called fin , and enters it to matA
        matrixDisplay(matA);

        printf("\nFinding the determinant now!\n");
        determinant=matrixDeterminant(matA,&matB,&flag); //finding the determinant
        if(flag==1){
                printf("\nThe determinant is%8.2f for:\n",determinant);
                matrixDisplay(matB);

                printf("\nFinding the inverse now!\n");
                matrixInverse(matB,determinant,&matC);          //finding the inverse

                printf("\nThe inverse of the matrix is:\n");
            matrixDisplay(matC);
            }else if(flag==0)
                {printf("The determinant<0 and inverse do not exist\n\n");
                 printf("flag %d.\n",flag);
                }else{
                    matrixDisplay(matB);
                    printf("The determinant=0 and inverse does not exist!\n\n");
                    printf("this is your flag %d",flag);
                }

        fclose(fin);

do {
	printf("Would you like to input another matrix? (type 1 for yes and 0 for no)\n");
    // Check in case user gives valid input
    if (scanf("%d", &quit) != 1) {
        getchar();
        printf(" Your input is not an integer.\n");
        }else{
            if(quit==0)
            another = '0'; //program will terminate after loop
            else if (quit==1)
			another = '1'; //program will redo the loop for another matrix
                else
                printf("Out of limits. Only 1 and 0 are valid.\n");
            }

    } while (quit!=0 && quit!=1);


    fflush(stdin);
    }else{
        printf("error: something went wrong with your file. The program terminated.");
        return 0;}//end of file available check
    }//end of while loop for another matrix

    return 0;
}

void matrixInput (struct matrix *matA, FILE *in){ //user chooses name and assigns size of matrix
    nameMatrix(&matA->name);
    int temp,temp1,flag;
    FILE *fin;
    fin = fopen("matrix2.txt", "r");
do{ //ROWS
    printf("Please input the size of matrix you want to input.\nHow many rows?(max 10):\n ");
    scanf("%d",&temp);
    }while(checkSize(temp,flag) == 0);
    (*matA).nrows=temp;

do{ //COLUMNS
    printf("How many columns?(max 10):\n ");
    scanf("%d",&temp1);
    }while (checkSize(temp1,flag)==0);
    (*matA).ncols=temp1;

    printf("\nThis is your initial matrix:\n %d x %d \n ",matA->nrows, matA->ncols);
    //enter info from file fin to matrix matA:
    int i,j;
	    for(i=0; i<10; i++){
            for( j=0; j<10; j++ )//read 1 row at a time from the file
            {fscanf( fin, "%2f ", &(*matA).mValues[i][j]);
            }//end of row
		}//end of matrix
}

void matrixDisplay(struct matrix mat)
{   int i,j;
    for(i=0; i<mat.nrows; i++){
        printf("\n|| Row %d: ",i+1);
        for( j=0; j<mat.ncols; j++ ){// read 1 row at a time from the file
        printf("%0.2f\t", mat.mValues[i][j]); }//end of row
		printf("||\n"); }//end of matrix
}

float matrixDeterminant(struct matrix matA, struct matrix *mat, int *check)
{//called in main as matrixDeterminant(matA,&matB,&flag);
    int i=1,j=1;
    float det;
    printf("For the submatrix:");
    nameMatrix(&mat->name); //User names the matrix

  //Condition for starting matrix bigger than 2x2.
    int flag,flag2;
if (matA.nrows!=2 && matA.ncols!=2){
    //ROWS
    printf("\nenter the number of row where start the 2x2 matrix (between 1 and %d inclusive):", matA.nrows-1);
    do {
    flag = scanf(" %d",&i);
    // Check in case user gives a letter or something
    if ( flag != 1) {
        getchar();
        printf("Not an int\n");
        printf("\nenter the number of row where start the 2x2 matrix (between 1 and %d inclusive):", matA.nrows-1);
    }else if(i<1 || (i>matA.nrows-1)){
    	printf("Out of limits\n");
    	printf("\nenter the number of row where start the 2x2 matrix (between 1 and %d inclusive):", matA.nrows-1);
	}
} while ((flag != 1) || (i<1 || (i>matA.nrows-1)));

    //COLUMNS
	printf("enter the number of column where start the 2x2 matrix:(between 1 and %d inclusive):", matA.ncols-1);
	do {
		 flag2 = scanf(" %d",&j);
	    // Check in case user gives a letter or something
	    if ( flag2 != 1) {
	        getchar();
	        printf("Not an int\n");
            printf("enter the number of column where start the 2x2 matrix:(between 1 and %d inclusive):", matA.ncols-1);
	    }else if(j<1 || (j>matA.ncols-1)){
    	printf("Out of limits\n");
    	printf("enter the number of column where start the 2x2 matrix:(between 1 and %d inclusive):", matA.ncols-1);
		}
	} while ((flag2 != 1) || (j<1 || (j>matA.ncols-1)));
	}


    //Calculate determinant = (A*C)-(B*D) with coordinates from matA:
    det = ( (matA.mValues[i-1][j-1])*(matA.mValues[i][j]) ) - ( (matA.mValues[i-1][j]) *  (matA.mValues[i][j-1]) ) ;
    //Assigning the matA values to mat 2x2 matrix ( in main it's called matrixDeterminant(matA,&matB,&flag); )
    mat->mValues[0][0]=matA.mValues[i-1][j-1];  //A
    mat->mValues[0][1]=matA.mValues[i-1][j];    //B
    mat->mValues[1][0]=matA.mValues[i][j-1];    //C
    mat->mValues[1][1]=matA.mValues[i][j];      //D
    mat->nrows=2; //sets number of rows and cols for the display of matB
    mat->ncols=2;
    //Assigning flag per case, so that it changes the behaviour of main.
    if (det>0) {
     *check=1;
     }else if (det==0 || det<0){
     *check=0;}
     return det;
}//end of matrixDeterminant()

void matrixInverse(struct matrix matA, float determinant, struct matrix *matD)
{// the input in main will be: matrixInverse(matB,determinant,&matC);
/*calculation of inverse is: (1/det)*adj(A)
Consider matrix: || A B || The inverse is ||D/det -B/det||
                 || C D ||.               ||-C/det A/det||.
The calculation is: A=D/det , B=-B/det,C=-C/det,D=A/det . */
    nameMatrix(&matD->name);
    float A,B,C,D;
    A=matA.mValues[1][1]/determinant;      //A
    B=-(matA.mValues[0][1])/determinant;   //-B
    C=-(matA.mValues[1][0])/determinant;   //-C
    D=matA.mValues[0][0]/determinant;      //D
    matD->mValues[0][0]= A;//entering the values to the inverse matrix
    matD->mValues[0][1]= B;
    matD->mValues[1][0]= C;
    matD->mValues[1][1]= D;
    matD->nrows=2;
    matD->ncols=2;
}//end of matrixInverse()

int checkSize(int num ,int flag){
    if(sizeof(num)==sizeof(int))
        {
        if (num>1&&num<11){
            flag=1;
            }else if(num==0 || num==1){
                    printf("Your matrix is too small to have a determinant and inverse.\n");
                    flag=0;}
                    else{
                    printf("Invalid input.Please try again.\n");
                    flag=0;
                    getchar();}
        }
    return flag;
};//end of checkSize()

void nameMatrix(char *name)
{   int OK=0;
    printf("\nName your matrix with a letter (e.g.A,B..): ");
    do{
        scanf(" %c",name);
        if((*name >= 'a' && *name <= 'z') || (*name >= 'A' && *name <= 'Z')){ //condition for alphabet
        printf("\nYour matrix is called: %c\n",*name);
        OK=1;
        } else{
            printf("Invalid input.Please try again.\n");
            getchar();}
    }while (OK!=1);
}//end of nameMatrix()
