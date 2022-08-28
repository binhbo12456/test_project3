#include <stdio.h>
#include<string.h>
#include<stdbool.h>
#include "struct.h"
#include <stdlib.h>

int getLastID(FILE *fp);

void input(struct employee *emp1, FILE *fp)
{

    start:
    if (fp == NULL)
    {
        printf("Couldn't open file\n");
    }

     emp1->id = (getLastID(fp) + 1 );
    printf("id = %d\n ", emp1->id);
     fflush(stdin);
    printf("\nEnter Name\n");
    scanf(" %[^\t\n]s", &emp1->name);
    fflush(stdin);
    printf("Enter birth date (DD/MM/YYYY): \n");
//    scanf("%d/%d/%d",&emp1->Date.day,&emp1->Date.month,&emp1->Date.year);
    printf("Enter date \n");
    scanf("%d",&emp1->Date.day);
    fflush(stdin);
    printf("Enter month \n");
    scanf("%d",&emp1->Date.month);
    fflush(stdin);
    printf("Enter year \n");
    scanf("%d",&emp1->Date.year);
    fflush(stdin);
//    printf("%d", emp1->Date.year);
    //check year
    if(emp1->Date.year>=1900 && emp1->Date.year<=9999)
    {
        //check month
        if(emp1->Date.month>=1 && emp1->Date.month<=12)
        {
            //check days
            if((emp1->Date.day>=1 && emp1->Date.day<=31) && (emp1->Date.month==1 || emp1->Date.month==3 || emp1->Date.month==5 || emp1->Date.month==7 || emp1->Date.month==8 || emp1->Date.month==10 || emp1->Date.month==12)) {
                printf("Date is valid.\n");}
            else if((emp1->Date.day>=1 && emp1->Date.day<=30) && (emp1->Date.month==4 || emp1->Date.month==6 || emp1->Date.month==9 || emp1->Date.month==11)){
                printf("Date is valid.\n");}
            else if((emp1->Date.day>=1 && emp1->Date.day<=28) && (emp1->Date.month==2)){
                printf("Date is valid.\n"); }
            else if(emp1->Date.day==29 && emp1->Date.month==2 && (emp1->Date.year % 400==0 ||(emp1->Date.year %4==0 && emp1->Date.year %100!=0))){
                printf("Date is valid.\n");}
            else{
                printf("Day is invalid.\n");goto start; }
        }
        else
        {
            printf("Month is not valid.\n"); goto start;
        }
    }
    else
    {
        printf("Year is not valid.\n"); goto start;
    }

    position:
    printf("\nEnter Position\n");
    printf("    + 1 = director\n"
           "    + 2 = manager\n"
           "    + 3 = team leader\n"
           "    + 4 = staff\n"
           "    + 5 = season staff\n");
    scanf("%d", &emp1->position);
    if( emp1->position >= 1 && emp1->position <= 5){
        printf("position is valid.\n");
    } else {
        printf("position is invalid"); goto position;
    }

    fflush(stdin);
    printf("\nEnter Salary\n");
    scanf("%d", &emp1->salary);
    fflush(stdin);
    // id, name, date, month, year, position, salary
    // int, char, int, int, int   , int, int
    fprintf(fp, "%d,%s,%d,%d,%d,%d,%d\n", emp1->id,
            emp1->name, emp1->Date.day, emp1->Date.month, emp1->Date.year, emp1->position, emp1->salary);
    fflush(fp); //make fprintf() writes immediately
    fflush(stdin);

//    fflush(NULL); linux
    printf("\nNew employee added to record");

}

int getLastID(FILE *fp){

    fseek(fp, 0, SEEK_SET);
    char row[MAXCHAR];
    char *token;
    char *array[7];

//    bool isUnique = true;
    int id = 0;
    while ( fgets(row, MAXCHAR, fp))
    {
        token = strtok(row, ",");
        int i = 0;
        while(token != NULL) {
            array[i++] = token;
            token = strtok(NULL, ",");
        }
        id = atoi(array[0]);
    }

    return id;
}