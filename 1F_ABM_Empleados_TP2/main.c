#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "DataLab.h"
#include "InterfaceLab.h"
#include "ArrayEmployees.h"

#define EMP_SIZE 3

int main()
{
    sEmployee arrayEmployee[EMP_SIZE];
    int exitStatus;
    int freeIndex;
    int initResult;
    int menuChoice;
    int previousId = 1;
    int newId;

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
                printf("freeIndex is: %d", freeIndex); // BORRAR LUEGO

                if(freeIndex == -1 || freeIndex == EMP_SIZE)
                {
                    UI_printDivider();
                    printf("ATENCION:\nLa base de datos de empleados se encuentra llena %d empleados cargados.\nElimine un empleado para poder ingresar uno nuevo. \n", EMP_SIZE);
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

                if(freeIndex != -0)
                {
                    UI_printDivider();
                    printf("NO DISPONIBLE:\nLa base de datos de empleados se encuentra vacia. Debes realizar el alta de un empleado primero. \n");
                }
                else
                {
                    // modify employee
                }

                break;

            case 3: //*** BAJA EMPLEADOS ***//
                system("cls");

                break;
            case 4: //*** MOSTRAR EMPLEADOS ***//
                system("cls");

                if(freeIndex != -0)
                {
                    UI_printDivider();
                    printf("NO DISPONIBLE:\nLa base de datos de empleados se encuentra vacia. Debes realizar el alta de un empleado primero. \n");
                }
                else
                {
                    array_ShowAllEmployes(arrayEmployee, EMP_SIZE);
                }

                break;

            case 5: //*** SALIR DEL PROGRAMA ***//
                exitStatus = UI_ExitAlert();
                break;

            default:
                system("cls");
                UI_printDivider();
                printf("Opcion invalida. Ingrese una opcion correcta");
        }

    } while(exitStatus != 1);


    return 0;
}
