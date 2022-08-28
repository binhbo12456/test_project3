#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

bool searchPosition(char* array[], int id){
    if (id == atoi(array[5])) {
        printf("\n====== FOUND ====== \n");
        printf("id %s \t ", array[0]);
        printf("name %s \t ",array[1]);
        printf("birth date %s/%s/%s \t ", array[2],array[3], array[4]);
        printf("position %s \t ", array[5]);
        printf("salary %s",array[6]);
        return true;
    } else {
        return false;
    }
}

int findByPosition(FILE *fp){

    int id;
    printf("    + 1 = director\n"
           "    + 2 = manager\n"
           "    + 3 = team leader\n"
           "    + 4 = staff\n"
           "    + 5 = season staff\n");
    printf("Nhap ID Chuc vu Nhan vien Can Tim  \n");
    scanf("%d", &id);

    fseek(fp, 0, SEEK_SET);
    char row[MAXCHAR];
    char *token;
    char *array[7];

//    while (feof(fp) != true)
    do
    {
        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        int i = 0;
        while(token != NULL) {
            array[i++] = token;
            token = strtok(NULL, ",");
        }
        if (searchPosition(array, id)){
//            return 0;
        }
    }while ( fgets(row, MAXCHAR, fp));

    return 0;
}