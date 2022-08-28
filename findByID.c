#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<stdbool.h>

bool searchID(char* array[], int id){
    if (id == atoi(array[0])){
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

int findById(FILE *fp){
    fseek(fp, 0, SEEK_SET);

    int id;
    printf("Nhap ID Nhan vien Can Tim  \n");
    scanf("%d", &id);

    char row[MAXCHAR];
    char *token;
    char *array[7];

    while ( fgets(row, MAXCHAR, fp))
    {
//        fgets(row, MAXCHAR, fp);
        token = strtok(row, ",");
        int i = 0;
        while(token != NULL) {
            array[i++] = token;
            token = strtok(NULL, ",");
        }
        if (searchID(array, id)){
            return 0;
        }
    }
    printf("not found");
    return 0;
}