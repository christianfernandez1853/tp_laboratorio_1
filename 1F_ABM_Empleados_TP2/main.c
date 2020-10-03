#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "InterfaceLab.h"
#include "ArrayEmployees.h"

#define EMP_SIZE 2

int main()
{
    sEmployee arrayEmployee[EMP_SIZE];
    int exitStatus;
    int employeeIndex;
    int freeIndex;
    int initResult;
    int menuChoice;
    int newId;
    int previousId = 1;
    int searchId;
    int sortOrder;
    int superiorToAvgSalariesCounter = 0;
    float averageSalary = 0;
    float totalSalary = 0;

    initResult = array_initEmployees(arrayEmployee, EMP_SIZE);

    // *** Solo para el desarrollador *** //
    if(initResult == -1)
    {
        UI_printDivider();
        printf("ERROR:\nParametros invalidos en la inicializacion del array de empleados. ");
    }

    UI_PrintHeader();

    do
    {
        menuChoice = UI_PrintMenu();


        switch(menuChoice)
        {
            case 1: //*** ALTA EMPLEADOS ***//
                system("cls");

                freeIndex = array_getFreePlaceInArray(arrayEmployee, EMP_SIZE);

                if(freeIndex == -1)
                {
                    UI_printDivider();
                    printf("ATENCION:\nLa base de datos de empleados se encuentra llena (%d empleados cargados).\nElimine un empleado para poder ingresar uno nuevo. \n", EMP_SIZE);
                }
                else
                {
                    newId = previousId;
                    previousId++;
                    array_loadArrayField(arrayEmployee, EMP_SIZE, newId);
                    array_showNewEmployeeLoaded(arrayEmployee, newId);
                }
                break;

            case 2: //*** MODIFICACION EMPLEADOS ***//
                system("cls");

                if(previousId == 1)
                {
                    UI_printDivider();
                    printf("NO DISPONIBLE:\nLa base de datos de empleados se encuentra vacia.\nDebes realizar el alta de un empleado primero.");
                }
                else
                {
                    UI_printDivider();
                    printf("Ingrese el numero de ID del empleado a modificar:  ");
                    scanf("%d", &searchId);
                    employeeIndex = array_findEmployeeById(arrayEmployee, EMP_SIZE, searchId);
                    if(employeeIndex != -1)
                    {
                        array_modifyEmployee(arrayEmployee, EMP_SIZE, employeeIndex);
                    }
                    else
                    {
                        UI_printDivider();
                        system("cls");
                        printf("No se encontro el ID. ");
                    }
                }

                break;

            case 3: //*** BAJA EMPLEADOS ***//
                system("cls");

                if(previousId == 1)
                {
                    UI_printDivider();
                    printf("NO DISPONIBLE:\nLa base de datos de empleados se encuentra vacia.\nDebes realizar el alta de un empleado primero.");
                }
                else
                {
                    UI_printDivider();
                    printf("Ingrese el numero de ID del empleado a eliminar:  ");
                    scanf("%d", &searchId);
                    employeeIndex = array_findEmployeeById(arrayEmployee, EMP_SIZE, searchId);
                    if(employeeIndex != -1)
                    {
                        array_removeEmployee(arrayEmployee, EMP_SIZE, employeeIndex);
                    }
                    else
                    {
                        UI_printDivider();
                        system("cls");
                        printf("No se encontro el ID. ");
                    }
                }

                break;

            case 4: //*** MOSTRAR EMPLEADOS ***//
                system("cls");

                if(previousId == 1)
                {
                    UI_printDivider();
                    printf("NO DISPONIBLE:\nLa base de datos de empleados se encuentra vacia.\nDebes realizar el alta de un empleado primero.");
                }
                else
                {
                    UI_printDivider();
                    printf("                               LISTADO DE EMPLEADOS: \n");
                    UI_printDivider();
                    printf("Seleccione una opcion para obtener el listado ordenado por apellido y sector:\n\n");
                    printf("[0] - Descendente\n");
                    printf("[1] - Ascendente\n\n");
                    scanf("%d", &sortOrder);
                    system("cls");

                    array_sortEmployees(arrayEmployee, EMP_SIZE, sortOrder);
                    array_printEmployees(arrayEmployee, EMP_SIZE);
                    array_totalSalaryAndAverage(arrayEmployee, EMP_SIZE, &totalSalary, &averageSalary);

                    printf("\n\nTotal Sueldos: $%.2f\n", totalSalary);
                    printf("Sueldo Promedio: $%.2f\n", averageSalary);
                    superiorToAvgSalariesCounter = array_superiorToAvgSalary(arrayEmployee, EMP_SIZE, averageSalary);
                    printf("Cantidad de empleados que superan el sueldo promedio: %d", superiorToAvgSalariesCounter);
                }

                break;

            case 5: //*** SALIR DEL PROGRAMA ***//
                exitStatus = UI_ExitAlert();
                break;

            default:
                system("cls");
                UI_printDivider();
                printf("ATENCION:\nOpcion invalida.\nIngrese una opcion correcta: ");
        }

    } while(exitStatus != 1);

    return 0;
}
