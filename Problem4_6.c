/* A program to print a table of RPM, linear velocity and
angular velocity.
 */

#include <stdio.h>

void linearVelocity(int rpm, int d);   // function declaration
float angularVelocity(float vel, int d);
void printTable(int rpm, float vel, float omega);

#define PI 3.142
#define RPM 1000

main(){
	int RPM1[30]={1000,2000,3000,4000,5000,6000,7000,8000,9000,10000}, i, j;
	float v[30], omega[30], D[3];

	printf("Enter 3 different values for the diameter\n");
	for(i=0;i<3;i++){
        scanf("%f",&D[i]);          //diameter D in metres
	}



	for(j=0;j<3;j++){                   //looping over all the diameter values
        printf(" RPM\t v\tomega\t for diameter %0.2f\n",D[j]);
        for(i=0;i<10;i++){            //looping over all the rpm values
            v[i]=(PI*D[j]*RPM1[i])/60;
            omega[i] = 2*v[i]/D[j];
            printTable(RPM1[i], v[i], omega[i]);
            }
        printf("\n \n");
	} //end for

} //end main


// function definition to print values in a table
void printTable(int rpm, float vel, float omega){
    printf("%5d %7.2f %7.2f\n", rpm, vel, omega);

}
