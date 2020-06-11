/* Problem 9-2 which finds the total energy consumed from 9am-5pm for a set of appliances.
The program also finds the appliance with the highest energy usage, as well as the hour in
which the most energy was consumed. These three calculations are performed in individual functions.
The code uses a structure called consumptionInfo, and an array of structs is declared to store
info about the time, appliance name and energy consumption for a list.
 */

#include <stdio.h>
#include <string.h>

#define Nitems 6
#define HOURS 8
#define SIZE 48 //currently have 8 hours and 6 items

struct consumptionInfo  // based on given format of input data file
{
	int hour;  // from 1-8
	char name[16]; // allow for 15 chars plus terminating NULL
	int watt;  // amount of electricity used in watts during that hour
};

int readFile(struct consumptionInfo list[]);  //function 1
void totalConsumption(struct consumptionInfo *list);  //function 2
void maxItem(struct consumptionInfo *list);
void findHourMostUsed(struct consumptionInfo *list);


void main(){

    struct consumptionInfo workDay[SIZE];
    int flag, i;

    flag = readFile(workDay);

    if(flag==1){
            totalConsumption(workDay);
            maxItem(workDay);
            findHourMostUsed(workDay);
    }
    else
        printf("File not found!");

}

int readFile(struct consumptionInfo list[]){

    FILE *fin;
    int i, check;
    fin = fopen("electricityConsumption.txt","r");
    if(fin!=NULL){
        for(i=0;i<SIZE;i++)
            fscanf(fin,"%d %s %d",&list[i].hour,list[i].name,&list[i].watt);
        fclose(fin);
        return check = 1;

    }
    else
        return check = 0;

}

void totalConsumption(struct consumptionInfo *list){

    int i;
    float kWatts,sum =0;
    for(i=0;i<SIZE;i++){
          printf("%d\t %s\t %d\n", (list+i)->hour, (list+i)->name,(list+i)->watt);

          sum = sum + (list+i)->watt;
    }
    kWatts = sum/1000;

    printf("The total consumption during the working day is %0.2f kW\n",kWatts);

}

void maxItem(struct consumptionInfo *list){

    int i,j,sum[Nitems] ={};
    float maxConsumption=0;
    char nameApp[16];
    for(i=0;i<Nitems;i++){
        for(j=0;j<HOURS;j++){
            sum[i] = sum[i] + (list+j+HOURS*i)->watt; }

           //printf("%d\n",sum[i]);  //printing out consumption of all appliances just as a check


         if(sum[i]>maxConsumption){
            maxConsumption = sum[i];
            strcpy(nameApp,(list+i*HOURS)->name);
         }

    }

    printf("\nAppliance %s consumed the most energy of %0.2f kW\n",nameApp,maxConsumption/1000);
}


void findHourMostUsed(struct consumptionInfo *list)
{
	int i, j, sumHourWatt[HOURS]={};
	float largestHourIndex;
	float maxHour=0;

	for(i=0;i<HOURS;i++){
       for(j=0;j<Nitems;j++){
            sumHourWatt[i] = sumHourWatt[i] + list[i+HOURS*j].watt;}

            //printf("%d\n",sumHourWatt[i]); //printing out hourly consumption just as a check

		if(sumHourWatt[i]>maxHour){
            maxHour = sumHourWatt[i];
            largestHourIndex = i+1;
		}

	}
	printf("The hour during which most electricity was consumed was hour %0.0f starting at %0.2f o'clock.\n", largestHourIndex, largestHourIndex+8);
	printf("During that hour %.2f kW was consumed.\n", maxHour/1000.0);
}
