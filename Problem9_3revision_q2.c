
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_NUM 400
struct entry
{   int index;
    char name[64];
    int calories;
    int protein;
};

int entries,i=0;
int addEntry(struct entry S[], int num);

int main() {
int num;
struct entry S[4];
FILE *fin;
fin=fopen("myText.txt", "r");

//printf("How many foods will you enter?\n");
//scanf("%d", &num);
entries=addEntry(S,num);
return entries;
}


int addEntry(struct entry S[], int num) {
int i=0,a,total;
FILE *fin;
fin=fopen("myText.txt", "a");

//printf("How many foods will you enter?\n");
//scanf("%d", &num);
if(fin!=NULL){

    do{
    int a;
    printf("\nNumber of dishes to append:", );
    scanf("%d",&a);
    total = num+a;
    if(total>MAX_NUM)
        printf("You have exceeded 400 entries in list. Cannot add more!\n");
    }while(total>MAX_NUM);

    for (i=1; i!=a ; i++)
    {
    printf("name of food;\n");
    scanf("%s",&S[i].name);

    printf("calories;\n");
    scanf("%d",&S[i].calories);

    printf("protein;\n");
    scanf("%d", &(S[i].protein));

    printf("\n%s %d %d for index %d\n\n",(S[i].name), (S[i].calories), (S[i].protein),i);
    } // end for loop
}else printf("\nfile could not open");
fclose(fin);
return num;
}





