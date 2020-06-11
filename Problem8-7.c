/* Problem 8-7 which calculates the stress and strain of a column of diameter d
when subjected to a compression load l. Data is stored in a struct
 */

#include <stdio.h>
#include <math.h>

#define PI 3.142
#define E 30000000

struct strength
{
       float p;    // load
       float d;    // diameter
       float stress;
       float strain;

};


main()
{
    struct strength test1;
    float area;


    printf("Please enter diameter of column\n");
    scanf("%f",&test1.d);
    printf("Please enter compression load\n");
    scanf("%f",&test1.p);

    //Calculating stress and strain
    area = (PI*test1.d*test1.d)/4;
    test1.stress = test1.p/area;
    test1.strain = test1.stress/E;

    printf("The stress is %e and strain is %.2f for a column with diameter %.2f when subjected to a %.2f load", test1.stress, test1.strain, test1.d, test1.p);

}
