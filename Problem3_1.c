/* A simple program to demonstrate using functions to find the area
and perimeter of a rectangle
 */

#include <stdio.h>

float RectArea(float l, float w);   // function declaration
float RectPerimeter(float l, float w);

main(){
	float length, width, area, per;

	printf("Please enter the length and width of the rectangle:");
	scanf("%f %f", &length, &width);
	area= RectArea(length,width);
	printf("Area of rectangle is %.2f.\n",area);
	per= RectPerimeter(length,width);
	printf("Perimeter of rectangle is %.2f.",per);
} //end main

// function definition to find area of a rectangle
float RectArea(float l, float w){
	return l*w;
}

// function definition to find perimeter of a rectangle
float RectPerimeter(float l, float w){
    return 2*(l+w);
}
