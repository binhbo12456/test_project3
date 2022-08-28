#ifndef A_H
#define A_H

struct employee{
    int id;
    char name[50];
    struct {
        int day;
        int month;
        int year;
    } Date;
    int position;
    int salary;
};

#endif