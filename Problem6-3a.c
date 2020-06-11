/* Problem6-3a.c                                            */
/* Write an area and volume calculator, using pointers, for these shapes:     */
/*	Rectangle                 */
/*  Circle                    */
/*  Triangle               */
/* Centimetres must be used for units.  All dimensions must*/
/* be positive floating point values in the range          */
/* 0.01 < dimension < 100.00 .  The area calculator should */
/* ask the user to choose the shape, and to input the      */
/* necessary values (e.g. length, width).  The calculator  */
/* should print out the area and volume to two decimal     */
/* places, along with an appropriate message.  Use a       */
/* different function for each different shape.            */
#include <stdio.h>

#define MIN 0.01
#define MAX 100.00
#define PI 3.14

void rectAreaVol(float length, float width, float height, float *area, float *volume);
void circleAreaVol(float radius, float *area, float *volume);
void triAreaVol(float base, float height, float length,float *area, float *volume);

main()
{
      float length, width, radius, base, height;
      float area, volume;
      int shape;
      char choice;
      printf("Area & volume calculator.  All dimensions must be >0.01 and < 100.0 (type ctrl+c to stop)\n");
      do
      {
        printf("please choose shape:  rectangle (type 1), circle (type 2), or triangle (type 3)\n");
        scanf("%d",&shape);
        switch(shape){
              case 1:
                    printf("rectangle\n");
                    do
                    {
                          printf("please enter length: ");
                          scanf("%f",&length);
                    } while(length<=MIN || length>=MAX);
                    do
                    {
                          printf("please enter width: ");
                          scanf("%f",&width);
                    } while(width<=MIN || width>=MAX);
                    do
                    {
                          printf("please enter height: ");
                          scanf("%f",&height);
                    } while(width<=MIN || width>=MAX);
                    rectAreaVol(length,width,height,&area,&volume);
                    printf("The area of the rectangle is %.2f cm squared.\n",area);
                    printf("The volume of the rectangle is %.2f cm cubed.\n",volume);
                    break;
              case 2:

                     printf("circle\n");
                     do
                     {
                           printf("please enter radius: ");
                           scanf("%f",&radius);
                     } while(radius<=MIN || radius>=MAX);
                     circleAreaVol(radius,&area,&volume);
                     printf("The area of the circle is %.2f cm squared.\n",area);
                     printf("The volume of the circle is %.2f cm cubed.\n",volume);
                     break;

              case 3:
                    printf("triangle\n");
                    do
                    {
                          printf("please enter base: ");
                          scanf("%f",&base);
                    } while(base<=MIN || base>=MAX);
                    do
                    {
                          printf("please enter height: ");
                          scanf("%f",&height);
                    } while(height<=MIN || height>=MAX);
                    do
                    {
                          printf("please enter length: ");
                          scanf("%f",&length);
                    } while(length<=MIN || length>=MAX);
                    triAreaVol(base,height,length,&area,&volume);
                    printf("The area of the triangle is %.2f cm squared.\n",area);
                    printf("The volume of the triangle is %.2f cm cubed.\n",volume);
                    break;

              default:
                printf("Wrong input.\n");
              } // end switch case

              fflush(stdin);
              printf("would you like to try again? Y/N\n");
              choice=getchar();

      }while(choice=='Y');
}
/* function void rectAreaVol(float length, float width, float height, float *area, float *volume); */
void rectAreaVol(float length, float width, float height, float *area, float *volume)
{
      *area= length*width;
      *volume = *area*height;
}
/* function void circleAreaVol(float radius, float *area, float *volume);  */
void circleAreaVol(float radius, float *area, float *volume)
{
      *area= radius*radius*PI;
      *volume = (4/3)*(*area)*radius;
}
/* function void triAreaVol(float base, float height, float length, float *area, float *volume);  */
void triAreaVol(float base, float height, float length, float *area, float *volume)
{
      *area= 0.5*base*height;
      *volume = *area*length;
}



