#include <stdio.h>
#include <string.h>

#define MAXCHAR 1000
#define CSVPATH "data.csv"

#include "struct.h"
#include "input.c"
#include "showData.c"
#include "findByID.c"
#include "findByPosition.c"
#include "findByYear.c"
#include "findBySalary.c"
#include "menu.c"

int main()
{
    struct employee emp;
    FILE *fp;
    fp = fopen(CSVPATH,"a+");

    if (fp == NULL)
    {
        printf("Couldn't open file\n");
        return 1;
    }
    int option;

    do {
        menu();
        printf("\n Nhap Lua Chon \n");
        scanf("%d",&option);
        switch (option) {
            case 1:
                input(&emp, fp);
                break;
            case 2:
                show_data(fp);
                break;
            case 3:
                findById(fp);
                break;
            case 4:
                findByPosition(fp);
                break;
            case 5:
                findByYear(fp);
                break;
            case 6:
                findBySalary(fp);
                break;
//            default:
//                menu();
//                break;
        }
    }   while(option != 0);

    fclose(fp);
    return 0;
}
