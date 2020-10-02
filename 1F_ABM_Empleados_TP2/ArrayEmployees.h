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
int array_ShowAllEmployes(sEmployee*, int);



#endif // ARRAYEMPLOYEES_H_
