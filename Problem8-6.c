/* Problem 8-6.c                                                      */
/* Program to input a week's worth of 24 temperature readings per day */
/* from a file, find and print the daily average                      */
/* Using structures and functions */

#include <stdio.h>

#define SAMPLESIZE 24
#define WEEKSIZE 7

struct dayTemp{
       int data[SAMPLESIZE][WEEKSIZE];
       float average[WEEKSIZE];
};

void calculateAverage(struct dayTemp *temperature);

main()
{
	struct dayTemp inp;
	int i,j;
    //float average[WEEKSIZE];

	FILE *fin;

	fin = fopen( "Temperatures-7.txt","r" );  /* open file for input */
	if( fin != NULL )  /* if fin is NULL, the file did not open successfully */
	{
        for( i=0; i<SAMPLESIZE; i++ ) /* read 1 row at a time from the file*/
		{
			fscanf( fin, "%d %d %d %d %d %d %d", &inp.data[i][0], &inp.data[i][1], &inp.data[i][2], &inp.data[i][3], &inp.data[i][4], &inp.data[i][5], &inp.data[i][6] );
			printf( "%d %d %d %d %d %d %d\n", inp.data[i][0], inp.data[i][1], inp.data[i][2], inp.data[i][3], inp.data[i][4], inp.data[i][5], inp.data[i][6]  );
		}

		fclose( fin );                    /* close the input file */

		/* a day's temperatures are stored in an array in a specific struct element, so find the average for each array */

        calculateAverage(&inp);

        for(j=0;j<WEEKSIZE;j++){
            printf( "Day %d average temperature was %.2f \n", j,inp.average[j]);}


    } else printf( "The file could not be opened - program aborting\n" );

}

/*****************************************************************************/
/* function to calculate average, given array of data and size as parameters */
/*****************************************************************************/
void calculateAverage(struct dayTemp *temperature)
{
      int i,j;
      float sum;

      for(j=0;j<WEEKSIZE;j++){
        sum=0.0;
        for( i=0; i<SAMPLESIZE; i++ )
        {
            sum = sum+temperature->data[i][j];
        }
        temperature->average[j] = sum/SAMPLESIZE;
      }
}

