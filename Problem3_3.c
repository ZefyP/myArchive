/* A program to print a table of RPM, linear velocity and
angular velocity of a propeller.
This program demonstrates calling a function from within another function.
*/

#include <stdio.h>

void linearVelocity(int rpm, int d);   // function declaration
float angularVelocity(float vel, int d);
void printTable(int rpm, float vel, float omega);

#define PI 3.142
#define RPM 1000

main(){
	int RPM1, i;
	float v, omega, D;

	printf("Enter a value for the diameter\n");
	scanf("%f",&D);          //diameter D in metres

	printf(" RPM\t v\tomega\n");

	for(i=0;i<10;i++){            //looping over all the rpm values
        RPM1 = RPM*(i+1);
        linearVelocity(RPM1, D);

	}
} //end main

// function definition to calculate linear velocity
void linearVelocity(int rpm, int d){
    float vel, omega;
	vel= (PI*d*rpm)/60;      //converting rpm to linear velocity (m/s)

	omega = angularVelocity(vel, d);  // calling a function within another function
    printTable(rpm, vel, omega);

}

// function definition to calculate angular velocity
float angularVelocity(float vel, int d){
    return 2*vel/d;                    //converting linear vel (m/s) to angular vel (rad/s)
}

// function definition to print values in a table
void printTable(int rpm, float vel, float omega){
    printf("%5d %7.2f %7.2f\n", rpm, vel, omega);

}
