// Problem8-5.c
// A program to convert polar coordinates (r,q) to Cartesian coordinates (x,y)
// Use struct polar with members r, q  and struct cart with members x,y
// Use function coordConv to perform the conversion.

#include <stdio.h>
#include <math.h>

struct polar // to hold the polar coordinates
{
       double r;      // distance from origin to point
       double theta;  // angle from positive x to the point in degrees
};
struct cartesian  // to hold the cartesian coordinates
{
       double x;  // x coordinate
       double y;  // y coordinate
};
void coordConv(struct polar p, struct cartesian *c);  // to convert polar coordinates to cartesian
main()
{
      struct polar myP;
      struct cartesian myC;
      printf("This program will convert polar coordinates to Cartesian.\n");
      printf("Please enter r (the distance from the origin to the point):  ");
      scanf("%lf", &myP.r);
      printf("Please enter theta (the angle measured from the positive 'x' axis to the point) in degrees:  ");
      scanf("%lf", &myP.theta);
      coordConv(myP, &myC);
      printf("For the polar coordinates %.2lf,%.2lf, the Cartesian coordinates are %.2lf,%.2lf\n", myP.r, myP.theta, myC.x, myC.y);

}
// function coordConv to convert polar coordinates to rectangular
void coordConv(struct polar p, struct cartesian *c)
{
      double rads;
      rads = (p.theta * M_PI) / 180.0;
      (*c).x = p.r * cos(rads);
      (*c).y = p.r * sin(rads);
}





