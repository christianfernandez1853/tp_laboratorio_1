#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "DataLab.h"
#include "MathLab.h"
#include "InterfaceLab.h"


//================================================================================================================================================//
//                                                          ENTRADA DE DATOS                                                                      //
//================================================================================================================================================//


//============================================================ NUMERICOS =========================================================================//

/** \brief Solicita al usuario un numero entero, por ejemplo: LEGAJO. El input del usuario es
           validado entre el minimo y el maximo permitido por la funcion.
 *
 * \param  int* pResult                              Dirección de memoria donde se guarda el numero (validado) ingresado por el usuario
 * \param  char* message                             Mensaje que deseamos mostrar al usuario al pedir el numero
 * \param  int min                                   Numero minimo permitido por la funcion
 * \param  int max                                   Numero maximo permitido por la funcion
 * \return                                           Devuelve 0: OK / -1: Error de parametros
 *
 */

int data_getValidatedInt(int* pResult, char* message, int min, int max)
{
    int returns = -1; // Se inicializa con el valor de error
    int exitFlag = 0; // Termina el loop cuando es == 1
    char buffer[50]; // Almacenamiento de inputs del usuario

    if(pResult != NULL && message != NULL && min <= max)
    {
        do
        {
            UI_printDivider();
            printf("%s", message);
            scanf("%s", buffer);

            if(math_isNumber(buffer) == 0)
            {
                printf("El valor ingresado no es un numero. \n");
            }
            else
            {
                if(math_numberIsFractional(atof(buffer)) == 1)
                {
                    printf("El numero ingresado no es valido. \n");
                }
                else
                {
                    if(atoi(buffer) >= min && atoi(buffer) <= max)
                    {
                        *pResult = atoi(buffer);
                        returns = 0; // OK
                        exitFlag = 1; // Termina el loop
                    }
                    else
                    {
                        printf("El numero ingresado esta fuera del rango permitido. (MIN: %d - MAX: %d) \n", min, max);
                    }
                }
            }

        } while(exitFlag == 0);
    }

    return returns;
}

//**************************************************************************************************************************************************//

/** \brief Solicita al usuario un numero flotante, por ejemplo: SUELDO. El input del usuario es
           validado entre el minimo y el maximo permitido por la funcion.
 *
 * \param  int* pResult                              Dirección de memoria donde se guarda el numero (validado) ingresado por el usuario
 * \param  char* message                             Mensaje que deseamos mostrar al usuario al pedir el numero
 * \param  int min                                   Numero minimo permitido por la funcion
 * \param  int max                                   Numero maximo permitido por la funcion
 * \return                                           Devuelve 0: OK / -1: Error de parametros
 *
 */

int data_getValidatedFloat(float* pResult, char* message, float min, float max)
{
    int returns = -1; // Se inicializa con el valor de error
    int exitFlag = 0; // Termina el loop cuando es == 1
    char buffer[50]; // Almacenamiento de inputs del usuario

    if(pResult != NULL && message != NULL && min <= max)
    {
        do
        {
            UI_printDivider();
            printf("%s", message);
            scanf("%s", buffer);

            if(math_isNumber(buffer) == 0)
            {
                printf("El valor ingresado no es un numero. \n");
            }
            else
            {
                if(atof(buffer) >= min && atof(buffer) <= max)
                {
                    *pResult = atof(buffer);
                    returns = 0; // OK
                    exitFlag = 1; // Termina el loop
                }
                else
                {
                    printf("El numero ingresado esta fuera del rango permitido. (MIN: %.2f - MAX: %.2f) \n", min, max);

                }
            }

        } while(exitFlag == 0);
    }

    return returns;
}

//=============================================================== CARACTERES ======================================================================//

/** \brief Solicita al usuario un caracter, por ejemplo: A. El input del usuario es
           validado entre el minimo y el maximo permitido por la funcion.
 *
 * \param  int* pResult                              Dirección de memoria donde se guarda el caracter (validado) ingresado por el usuario
 * \param  char* message                             Mensaje que deseamos mostrar al usuario al pedir el caracter
 * \param  int min                                   Caracter minimo permitido por la funcion
 * \param  int max                                   Caracter maximo permitido por la funcion
 * \return                                           Devuelve 0: OK / -1: Error de parametros
 *
 */

int data_getValidatedChar(char* pResult, char* message, char min, char max)
{
    int returns = -1; // Se inicializa con el valor de error
    int exitFlag = 0; // Termina el loop cuando es == 1
    char buffer; // Almacenamiento de inputs del usuario

    if(pResult != NULL && message != NULL && min <= max)
    {
        do
        {
            UI_printDivider();
            printf("%s", message);
            fflush(stdin);
            scanf("%c", &buffer);

            if(!(isalpha(buffer)))
            {
                printf("El valor ingresado no es un caracter alfabetico. \n");
            }
            else
            {
                if(buffer >= min && buffer <= max)
                {
                    *pResult = buffer;
                    returns = 0; // OK
                    exitFlag = 1; // Termina el loop
                }
                else
                {
                    printf("El caracter ingresado esta fuera del rango permitido. (MIN: %c - MAX: %c) \n", min, max);
                }
            }

        } while(exitFlag == 0);
    }

    return returns;
}

//================================================================ ARRAYS =========================================================================//

/** \brief Solicita al usuario una cadena de texto, por ejemplo: NOMBRE. El input del usuario es
           validado alfabeticamente, no permite otro tipo de caracteres.
 *
 * \param  char input[]                              Array de caracteres donde se guarda la cadena de texto ingresada por el usuario
 * \param  char* message                             Mensaje que deseamos mostrar al usuario al pedir la cadena de texto
 * \param  int arraySize                             Tamaño del array de caracteres enviado
 * \return                                           Devuelve 0: OK / -1: Error de parametros
 *
 */

int data_getValidatedAlphaString(char input[], char* message, int arraySize)
{
    int returns = -1;
    int exitFlag = 0; // Termina el loop cuando es == 1
    char buffer[arraySize];
    int notAlphaFlag = 0; // Alerta al programa si la cadena no es alfabetica cuando es == 1

    int i;

    if(message != NULL)
    {
        do
        {
            notAlphaFlag = 0;

            UI_printDivider();
            printf(message);
            scanf(" %[^\n]", buffer);

            for(i = 0; i < strlen(buffer); i++)
            {
                if(!(isalpha(buffer[i])) && !(isspace(buffer[i])))
                {
                    UI_printDivider();
                    printf("Solo es posible ingresar caracteres alfabeticos y espacios \n");
                    notAlphaFlag = 1; // Alerta
                    break; // Termina el for al encontrar un caracter invalido
                }
            }

            if(notAlphaFlag == 0) // Sino hubo errores
            {
                strcpy(input, buffer);
                returns = 0;
                exitFlag = 1;
            }

        } while(exitFlag != 1);
    }

    return returns;
}

//**************************************************************************************************************************************************//

/** \brief Solicita y guarda en un array distintos tipos de datos relacionados. Los valores
           a ingresar se validan antes de ser aceptados. Modificar aquí dependiendo el pedido,
           los tipos de datos pueden variar.
 *
 * \param   int firstParam[]                            Solicita el primer array
 * \param   int secondParam[]                           Solicita el segundo array
 * \param   int thirdParam[]                            Solicita el tercer array
 * \param   int arraySize[]                             Solicita el tamaño del array
 *
 */

void data_getRelatedArrays(int firstParam[], float secondParam[], char thirdParam[][21], int arraySize)
{

    int bufferLegajo;
    int minLegajo = 0;
    int maxLegajo = 999;
    float bufferSueldo;
    float minSueldo = 10000.00;
    float maxSueldo = 500000.00;

    char bufferNombres[21];

    int i;

    for(i = 0; i < arraySize; i++)
    {

        if(data_getValidatedInt(&bufferLegajo, "Ingrese legajo: ", minLegajo, maxLegajo) == 0)
        {
            firstParam[i] = bufferLegajo;
        }

        if(data_getValidatedFloat(&bufferSueldo, "Ingrese sueldo: ", minSueldo, maxSueldo) == 0)
        {
            secondParam[i] = bufferSueldo;
        }

        if(data_getValidatedAlphaString(bufferNombres, "Ingrese nombre: ", arraySize) == 0)
        {
            strcpy(thirdParam[i], bufferNombres);
            data_upperStringInitials(thirdParam[i]);
        }
    }
}


//================================================================================================================================================//
//                                                          SALIDA DE DATOS                                                                       //
//================================================================================================================================================//


//================================================================ ARRAYS =========================================================================//

/** \brief Muestra un array de numeros enteros.
 *
 * \param  int array[]                              Solicita el array de enteros
 * \param  int arraySize                            Solicita el tamaño del array
 *
 */

void data_showIntArray(int array[], int arraySize)
{
    int i;

    if(arraySize >= 0)
    {
        for(i = 0; i < arraySize; i++)
        {
            UI_printDivider();
            printf("%d - %d", i, array[i]);
        }
    }
    else
    {
        UI_printDivider();
        printf("El tamaño del array no es valido. \n");
    }
}

//**************************************************************************************************************************************************//

/** \brief Muestra un array de numeros flotantes.
 *
 * \param  float array[]                            Solicita el array de flotantes
 * \param  int arraySize                            Solicita el tamaño del array
 *
 */

void data_showFloatArray(float array[], int arraySize)
{
    int i;

    if(arraySize >= 0)
    {
        for(i = 0; i < arraySize; i++)
        {
            UI_printDivider();
            printf("%d - %.2f", i, array[i]);
        }
    }
    else
    {
        UI_printDivider();
        printf("El tamaño del array no es valido. \n");
    }
}

//**************************************************************************************************************************************************//

/** \brief Muestra un conjunto de arrays relacionados. Modificar aquí
 *         dependiendo el pedido, los tipos de datos pueden variar.
 *
 * \param int firstParam[]                            Solicita el primer array.
 * \param int secondParam[]                           Solicita el segundo array
 * \param int thirdParam[]                            Solicita el tercer array
 * \param int arraySize[]                             Solicita el tamaño del array
 *
 */

void data_showRelatedArrays(int firstParam[], float secondParam[], char thirdParam[][21], int arraySize)
{
    int i;

    UI_printDivider();
    printf("========== Lista de Empleados ==========\n\n");
    printf("Legajo        Sueldo       Nombre\n");

    for(i = 0; i < arraySize; i++)
    {
        printf("_____________________________________\n");
        printf("%4d %10.2f %10s\n", firstParam[i], secondParam[i], thirdParam[i]);
    }
}


//================================================================================================================================================//
//                                                          ORDENAMIENTO DE DATOS                                                                 //
//================================================================================================================================================//

/** \brief Ordena un array de enteros en forma ascendente (LtoH: Lowest to Highest)
 *
 * \param  int* pArray                                  Solicita la direcion de memoria del array a ordenar
 * \param  int arraySize                                Solicita el tamaño del array a ordenar
 * \return
 *
 */

int data_orderingIntArrayLtoH(int* pArray, int arraySize)
{
    int returns = -1;
    int buffer;
    int newArraySize;

    int flagSwap;
    int i;

    if(pArray != NULL && arraySize >= 0)
    {
        newArraySize = arraySize - 1;

        do
        {
            flagSwap = 0;

            for(i = 0; i < newArraySize; i++)
            {
                if(pArray[i] > pArray[i+1])
                {
                    flagSwap = 1;
                    buffer = pArray[i];
                    pArray[i] = pArray[i+1];
                    pArray[i+1] = buffer;
                }
            }

            newArraySize--;

        } while(flagSwap);

        returns = 0;
    }
    return returns;
}

//**************************************************************************************************************************************************//

/** \brief Ordena un array de enteros en forma descendente (HtoL: Highest to Lowest)
 *
 * \param  int* pArray                                  Solicita la direcion de memoria del array a ordenar
 * \param  int arraySize                                Solicita el tamaño del array a ordenar
 * \return
 *
 */

int data_orderingIntArrayHtoL(int* pArray, int arraySize)
{
    int returns = -1;
    int buffer;
    int newArraySize;

    int flagSwap;
    int i;

    if(pArray != NULL && arraySize >= 0)
    {
        newArraySize = arraySize - 1;

        do
        {
            flagSwap = 0;

            for(i = 0; i < newArraySize; i++)
            {
                if(pArray[i] < pArray[i+1])
                {
                    flagSwap = 1;
                    buffer = pArray[i];
                    pArray[i] = pArray[i+1];
                    pArray[i+1] = buffer;
                }
            }

            newArraySize--;

        } while(flagSwap);

        returns = 0;
    }
    return returns;
}

//**************************************************************************************************************************************************//

/** \brief Ordena un array de floats en forma ascendente (LtoH: Lowest to Highest)
 *
 * \param  float* pArray                                  Solicita la direcion de memoria del array a ordenar
 * \param  int arraySize                                Solicita el tamaño del array a ordenar
 * \return
 *
 */

int data_orderingFloatArrayLtoH(float* pArray, int arraySize)
{
    int returns = -1;
    float buffer;
    int newArraySize;

    int flagSwap;
    int i;

    if(pArray != NULL && arraySize >= 0)
    {
        newArraySize = arraySize - 1;

        do
        {
            flagSwap = 0;

            for(i = 0; i < newArraySize; i++)
            {
                if(pArray[i] > pArray[i+1])
                {
                    flagSwap = 1;
                    buffer = pArray[i];
                    pArray[i] = pArray[i+1];
                    pArray[i+1] = buffer;
                }
            }

            newArraySize--;

        } while(flagSwap);

        returns = 0;
    }
    return returns;
}

//**************************************************************************************************************************************************//

/** \brief Ordena un array de floats en forma descendente (HtoL: Highest to Lowest)
 *
 * \param  float* pArray                                  Solicita la direcion de memoria del array a ordenar
 * \param  int arraySize                                Solicita el tamaño del array a ordenar
 * \return
 *
 */

int data_orderingFloatArrayHtoL(float* pArray, int arraySize)
{
    int returns = -1;
    float buffer;
    int newArraySize;

    int flagSwap;
    int i;

    if(pArray != NULL && arraySize >= 0)
    {
        newArraySize = arraySize - 1;

        do
        {
            flagSwap = 0;

            for(i = 0; i < newArraySize; i++)
            {
                if(pArray[i] < pArray[i+1])
                {
                    flagSwap = 1;
                    buffer = pArray[i];
                    pArray[i] = pArray[i+1];
                    pArray[i+1] = buffer;
                }
            }

            newArraySize--;

        } while(flagSwap);

        returns = 0;
    }
    return returns;
}

//**************************************************************************************************************************************************//

/** \brief Ordena numericamente en forma numerica ascendente (LtoH: Lowest to Highest) un conjunto de arrays relacionados. Modificar aquí
 *         dependiendo el pedido, los tipos de datos pueden variar.
 *
 * \param   int firstParam[]                            Solicita el primer array. Posee el criterio de ordenamiento.
 * \param   int secondParam[]                           Solicita el segundo array
 * \param   int thirdParam[]                            Solicita el tercer array
 * \param   int arraySize[]                             Solicita el tamaño del array
 *
 */

void data_orderingRelatedArraysNumLtoH(int firstParam[], float secondParam[], char thirdParam[][21], int arraySize)
{
    int i;
    int j;

    int auxInt;
    float auxFloat;
    char auxString[100];

    for(i = 0; i < arraySize - 1; i++)
    {
        for(j = i+1; j < arraySize; j++)
        {
            if(firstParam[i] > firstParam[j]) // El criterio de ordenamiento estara dado por el primer parametro
            {
                auxInt = firstParam[i];
                firstParam[i] = firstParam[j];
                firstParam[j] = auxInt;

                auxFloat = secondParam[i];
                secondParam[i] = secondParam[j];
                secondParam[j] = auxFloat;

                strcpy(auxString, thirdParam[i]);
                strcpy(thirdParam[i], thirdParam[j]);
                strcpy(thirdParam[j], auxString);
            }
        }
    }
}

//**************************************************************************************************************************************************//

/** \brief Ordena numericamente en forma numerica descendente (HtoL: Highest to Lowest) un conjunto de arrays relacionados. Modificar aquí
 *         dependiendo el pedido, los tipos de datos pueden variar.
 *
 * \param   int firstParam[]                            Solicita el primer array. Posee el criterio de ordenamiento.
 * \param   int secondParam[]                           Solicita el segundo array
 * \param   int thirdParam[]                            Solicita el tercer array
 * \param   int arraySize[]                             Solicita el tamaño del array
 *
 */

void data_orderingRelatedArraysNumHtoL(int firstParam[], float secondParam[], char thirdParam[][21], int arraySize)
{
    int i;
    int j;

    int auxInt;
    float auxFloat;
    char auxString[100];

    for(i = 0; i < arraySize - 1; i++)
    {
        for(j = i+1; j < arraySize; j++)
        {
            if(firstParam[i] < firstParam[j]) // El criterio de ordenamiento estara dado por el primer parametro
            {
                auxInt = firstParam[i];
                firstParam[i] = firstParam[j];
                firstParam[j] = auxInt;

                auxFloat = secondParam[i];
                secondParam[i] = secondParam[j];
                secondParam[j] = auxFloat;

                strcpy(auxString, thirdParam[i]);
                strcpy(thirdParam[i], thirdParam[j]);
                strcpy(thirdParam[j], auxString);
            }
        }
    }
}

//**************************************************************************************************************************************************//

/** \brief Convierte un array de caracteres en minusculas y luego las iniciales en mayusculas.
 *
 * \param char string[]                                 Solicita el array de caracteres a transformar
 *
 */

void data_upperStringInitials(char string[])
{
    int i;
    strlwr(string);
    string[0] = toupper(string[0]);

    for(i = 0; i < strlen(string); i++)
    {
        if(isspace(string[i]))
        {
            string[i+1] = toupper(string[i+1]);
        }
    }
}
