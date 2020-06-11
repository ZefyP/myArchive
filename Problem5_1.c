// Program to use arrays and pointers and look at memory addresses as well as contents of memory.
// Input 5 integer values from the keyboard and store these in an array, using array indexing.
// Write a table to the screen, with the first column containing the memory addresses
// of the array elements, the second column containing the memory address in hex,
// and the third column containing the integer values
// held at the memory addresses.  Repeat with floats and doubles


#include <stdio.h>

#define SIZE 2

main()
{
	int i;
	int intArray[SIZE];
	float floatArray[SIZE];
	char charArray[SIZE];

	int *ptrIntArray;
	float *ptrFloatArray;
	char *ptrCharArray;

	//assign pointers to arrays to point to the start of each array
	ptrIntArray=intArray;
	ptrFloatArray=floatArray;
	ptrCharArray=charArray;

	printf("enter %d integers: \n", SIZE);
	for(i=0; i<SIZE; i++)
	{
		scanf("%d", &intArray[i]);
	}
	printf("enter %d floats: \n", SIZE);
	for(i=0; i<SIZE; i++)
	{
		scanf("%f", &floatArray[i]);
	}
	printf("enter %d chars: \n", SIZE);
	for(i=0; i<SIZE; i++)
	{
	    fflush(stdin);
		scanf("%c", &charArray[i]);
		fflush(stdin);
	}


	printf("Memory address base 10\tMemory address base 16\tcontents at address\n");
	printf("Integers:\n\n");
	for(i=0; i<SIZE; i++)
	{
		printf("%d\t\t\t%x\t\t\t%d\n",ptrIntArray+i,ptrIntArray+i,*(ptrIntArray+i));  // printing pointer without deferencing will result in memory address being printed
	}
	printf("\nFloats:\n\n");
	for(i=0; i<SIZE; i++)
	{
		printf("%d\t\t\t%x\t\t\t%f\n",ptrFloatArray+i,ptrFloatArray+i,*(ptrFloatArray+i));  // printing pointer without deferencing will result in memory address being printed
	}
	printf("\nChars:\n\n");
	for(i=0; i<SIZE; i++)
	{
		printf("%d\t\t\t%x\t\t\t%c\n",ptrCharArray+i,ptrCharArray+i,*(ptrCharArray+i));  // printing pointer without deferencing will result in memory address being printed
	}


}
