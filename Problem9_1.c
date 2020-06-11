/* Problem 9-1 which calculates the stress and strain of a column of diameter d
when subjected to a compression load l. Data is stored in a struct. An array of
struct is used as well as various functions.
 */

#include <stdio.h>
#include <math.h>

#define PI 3.142
#define E 30000000
#define SIZE 2   // change this depending on how many times the user wants to enter d and p

struct strength
{
       float p;    // load
       float d;    // diameter
       float stress;
       float strain;

};

void getData(struct strength *data);
void calStressStrain(struct strength SS[]);
void printSS(struct strength data);


main()
{
	int size,i;
	struct strength test1[SIZE];
	float area;

	getData(test1);
	calStressStrain(test1);

	printf("Diameter \t Load \t         Stress \t  Strength\n");
	printf("-------- \t ---- \t         ------ \t  --------\n");
	for(i=0;i<SIZE;i++){

    	printSS(test1[i]);


	}
}

//obtaining diameter of column and compression load
void getData(struct strength *data){
	int i;

	for(i=0;i<SIZE;i++){
    	printf("\nPlease enter diameter of column (in m) < 0.1m\n");
    	scanf("%f",&(*(data+i)).d);
    	printf("Please enter compression load (in N) > 5kN\n");
    	scanf("%f",&(*(data+i)).p);
    }

}

//calculating stress and strain in array of struct
void calStressStrain(struct strength SS[]){
	int i;
	float area;

	for(i=0;i<SIZE;i++){


    	//Calculating stress and strain
    	area = (PI*SS[i].d*SS[i].d)/4;
    	SS[i].stress = SS[i].p/area;
    	SS[i].strain = SS[i].stress/E;
    }
}

//printing the data
void printSS(struct strength data){

	printf("%0.2f m\t      %0.2f N\t %.2e Pa\t  %.2f\n", data.d, data.p,data.stress, data.strain);
}
