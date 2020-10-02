#include <stdio.h>
#include <stdlib.h>
#include "DataLab.h"
#include "InterfaceLab.h"
#include "ArrayEmployees.h"


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

    if(arrayName != NULL && arraySize > 0)
    {
        for(i = 0; i < arraySize; i++)
        {
            arrayName[i].isEmpty = 1;
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
    int freeIndex;

    if(arrayName != NULL && arraySize > 0)
    {
        for(i = 0; i < arraySize; i++)
        {
            if(arrayName[i].isEmpty != 0)
            {
                freeIndex = i;
                break; // Termina el loop cuando encuentra un lugar vacio
            }
        }

        if(i == arraySize) // Si i llego a la ultima posicion del array, entonces no hay lugar vacio
        {
            freeIndex = -1;
        }
    }

    return freeIndex;
}
//**************************************************************************************************************************************************//

/** \brief Solicita al usuario llenar los campos de datos del array y devuelve los mismos.
 *
 * \return sEmployee* newEmployee                                   Puntero al array de la estructura
 *
 */

int array_loadArrayField(sEmployee* newEmployee, int arraySize, int newId)
{
    float minSalary = 1.00;
    float maxSalary = 1000000.00;
    int minSector = 1;
    int maxSector = 5;
    int returns = -1;

    if(newEmployee != NULL && arraySize > 0)
    {
        UI_printDivider();
        printf("                                 NUEVO EMPLEADO: \n\n");
        printf("                                    ID - #%d", newId);

        data_getValidatedAlphaString(newEmployee[newId - 1].name, "Ingrese Nombre: ", arraySize);
        data_upperStringInitials(newEmployee[newId - 1].name);
        data_getValidatedAlphaString(newEmployee[newId - 1].lastName, "Ingrese Apellido: ", arraySize);
        data_upperStringInitials(newEmployee[newId - 1].lastName);
        data_getValidatedFloat(&newEmployee[newId - 1].salary, "Ingrese Sueldo: ", minSalary, maxSalary);
        data_getValidatedInt(&newEmployee[newId - 1].sector, "Ingrese Sector: ", minSector, maxSector);
        newEmployee[newId - 1].isEmpty = 0;

        returns = 0;
    }

    return returns;
}

//**************************************************************************************************************************************************//

/** \brief Muestra el ultimo empleado cargado.
 *
 * \param sEmployee* arrayName                                      Puntero al array de la estructura
 * \param int newId                                                 Solicita el ID a mostrar
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
           arrayName[newId - 1].id, arrayName[newId - 1].name, arrayName[newId - 1].lastName, arrayName[newId - 1].salary, arrayName[newId - 1].sector);
}

//**************************************************************************************************************************************************//

/** \brief Muestra todos los empleados cargados hasta el momento.
 *
 * \param sEmployee* arrayName                                      Puntero al array de la estructura
 * \param int newId                                                 Solicita el ID a mostrar
 *
 */

int array_ShowAllEmployes(sEmployee* arrayName, int arraySize)
{
    int returns = -1;

    int i;

    if(arrayName != NULL && arraySize > 0)
    {
        printf("\n %-4s %-21s %-21s %-15s %-2s\n", "ID", "Nombre", "Apellido", "Sueldo", "Sector");
        UI_printDivider();

        for(i = 0; i < arraySize; i++)
        {

            printf("\n#%-4d %-21s %-21s $%-15.2f %-2d\n",
                    arrayName[i].id, arrayName[i].name, arrayName[i].lastName, arrayName[i].salary, arrayName[i].sector);

            returns = 0;
        }
    }

    return returns;
}


