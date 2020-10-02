#include <stdio.h>
#include <stdlib.h>
#include "DataLab.h"
#include "InterfaceLab.h"
#include "ArrayEmployees.h"

#define EMPTY 1
#define FULL 0



/** \brief Inicializa la estructura indicando que todos los campos de la misma estan vacios.
 *
 * \param  sEmployee* arrayName[]                               Puntero al array de la estructura a inicializar
 * \param  int arraySize                                        Solicita el tamaño de la estructura
 * \return                                                      Devuelve: -1 (Puntero NULL o arraySize invalido)
 *                                                                         0 (Si no hay errores de parametros)
 */

int array_initEmployees(sEmployee* arrayName, int arraySize)
{
    int returns = -1;
    int i;

    if(arrayName != NULL && arraySize >= 1)
    {
        for(i = 0; i < arraySize; i++)
        {
            arrayName[i].isEmpty = EMPTY;
        }

        returns = 0;
    }

    return returns;
}

//**************************************************************************************************************************************************//

/** \brief Analiza donde hay un espacio libre en la estructura y devuelve la posicion
 *
 * \param  sName arrayName[]                                     Puntero del array de la estructura
 * \param  int arraySize                                         Solicita el tamaño del array
 * \return                                                       Devuelve: la posicion donde hay un campo vacio en el array
 *                                                                         0: si el array esta vacio
 *                                                                        -1: si el array esta lleno
 *
 */

int array_getFreePlaceInArray(sEmployee* arrayName, int arraySize)
{
    int i;

    if(arrayName != NULL && arraySize >= 1)
    {
        for(i = 0; i < arraySize; i++)
        {
            if(arrayName[i].isEmpty != FULL || i != arraySize)
            {
                break; // Termina el loop cuando encuentra un lugar vacio
            }

            if(i == arraySize) // Si i llego a la ultima posicion del array, entonces no hay lugar vacio
            {
                i = -1;
            }
        }
    }

    return i;
}
//**************************************************************************************************************************************************//

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

 int array_newID(sEmployee* newEmployee, int arraySize, int previousID)
 {
     int newID;

     newID = previousID + 1;

     return newID;
 }

//**************************************************************************************************************************************************//

/** \brief Solicita al usuario llenar los campos de datos de la estructura y devuelve los mismos.
 *
 * \return sEmployee newEmployee                                    Devuelve el campo de la estructura ya cargado
 *
 */

int array_loadArrayField(sEmployee* newEmployee, int arraySize, int newId)
{
    float minSalary = 16875.00; // Sueldo min de ejemplo (minimo en ARG)
    float maxSalary = 1000000.00; // Sueldo max de ejemplo
    int minSector = 1;
    int maxSector = 5;

    UI_printDivider();
    printf("                                 NUEVO EMPLEADO: \n\n");
    printf("                                    ID - #%d", newId);

    data_getValidatedAlphaString(newEmployee[newId].name, "Ingrese Nombre: ", arraySize);
    data_upperStringInitials(newEmployee[newId].name);
    data_getValidatedAlphaString(newEmployee[newId].lastName, "Ingrese Apellido: ", arraySize);
    data_upperStringInitials(newEmployee[newId].lastName);
    data_getValidatedFloat(&newEmployee[newId].salary, "Ingrese Sueldo: ", minSalary, maxSalary);
    data_getValidatedInt(&newEmployee[newId].sector, "Ingrese Sector: ", minSector, maxSector);
    newEmployee[newId - 1].isEmpty = 0;

    return 0;
}

//**************************************************************************************************************************************************//

/** \brief Muestra un campo especifico del array ya cargado
 *
 * \param sEmployee arrayName                                      Solicita el campo del array a mostrar
 *
 */

void array_showNewEmployeeLoaded(sEmployee* arrayName, int newId)
{
    system("cls");
    UI_printDivider();
    printf("Nuevo empleado cargado correctamente: ");
    UI_printDivider();
    printf("\n %-4s %-21s %-21s %-15s %-2s\n", "ID", "Nombre", "Apellido", "Sueldo", "Sector");
    printf("\n#%-4d %-21s %-21s $%-15.2f %-2d\n",
           arrayName[newId].id, arrayName[newId].name, arrayName[newId].lastName, arrayName[newId].salary, arrayName[newId].sector);
}

//**************************************************************************************************************************************************//

/** \brief Muestra todos los campos de la estructura cargados hasta el momento
 *
 * \param  sName structArray[]                                      Solicita el array de la estructura a mostrar
 * \param  int arraySize                                            Solicita el tamaño del array
 *
 */
/*
void STR_showAllStruct(sName structArray[], int arraySize)
{
    UI_printDivider();

    int i;

    printf("\n%-4s %-21s %-21s %-15s %-2s", "ID", "NOMBRE", "APELLIDO", "SUELDO", "SECTOR");

    for(i=0; i < arraySize; i++)
    {
        if(structArray[i].isEmpty == FULL)
        {
            STR_showSpecifStructData(structArray[i]);
        }
    }
}
*/


