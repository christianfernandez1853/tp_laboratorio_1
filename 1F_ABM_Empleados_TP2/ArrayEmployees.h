#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} sEmployee;

int array_initEmployees(sEmployee*, int);
int array_getFreePlaceInArray(sEmployee*, int);
int array_loadArrayField(sEmployee*, int, int);
void array_showNewEmployeeLoaded(sEmployee*, int);
int array_findEmployeeById(sEmployee*, int, int);
int array_modifyEmployee(sEmployee*, int, int);
int array_removeEmployee(sEmployee*, int, int);
int array_sortEmployees(sEmployee*, int, int);
int array_printEmployees(sEmployee*, int);
int array_totalSalaryAndAverage(sEmployee*, int, float*, float*, int*);

#endif // ARRAYEMPLOYEES_H_
