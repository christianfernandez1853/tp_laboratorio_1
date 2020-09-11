#include <stdio.h>
#include <stdlib.h>
#include "Interface.h"




/** \brief Muestra el encabezado del programa (solo en al inicio).
 *
 */

void PrintHeader(void)
{
    printf("_____________________________________________________________________________\n\n");
    printf("                         CALCULADORA - TP 1 \n\n");
    printf("                     por Christian Fernandez (1F) \n\n");
}




/** \brief Muestra el menu del programa y devuelve la eleccion del usuario.
 *
 * \param   float firstNumber       Solicita el primer numero para mostrarlo en el menu
 * \param   float secondNumber      Solicita el segundo numero para mostrarlo en el menu
 * \return  int menuChoice          Devuelve la opcion elegida por el usuario
 *
 */

int PrintMenu(float firstNumber, float secondNumber)
{
    int menuChoice;

    printf("_____________________________________________________________________________\n\n");
    printf("Elija una opcion para comenzar a trabajar: \n\n");
    printf("[1] - Ingresar 1er Operando (A = %f) \n", firstNumber);
    printf("[2] - Ingresar 2do Operando (B = %f) \n", secondNumber);
    printf("[3] - Calcular Operaciones (Suma - Resta - Producto - Division - Factorial) \n");
    printf("[4] - Informar Resultados. \n");
    printf("[5] - Salir de Programa. \n");
    printf("_____________________________________________________________________________\n\n");
    scanf("%d", &menuChoice);
    printf("\n");

    return menuChoice;
}




/** \brief Muestra un mensaje personalizado.
 *
 * \param char message[]            Solicita una cadena de texto
 *
 */

void PrintMessage(char message[])
{
    printf("_____________________________________________________________________________\n\n");
    printf("*** %s *** \n\n", message);
}




/** \brief Muestra un alerta al intentar salir del programa, valida la respuesta del usuario
 *         y devuelve la eleccion.
 *
 * \return char     exitChoice      Devuelve el valor de la respuesta (1: Si / 0: No)
 *
 */

int ExitAlert(void)
{
    char exitChoice;

    system("cls");

    printf("_____________________________________________________________________________\n\n");
    printf("*** Alerta: Esta seguro que desea salir del programa? (S: Si / N: No) ***  \n\n");
    printf("_____________________________________________________________________________\n\n");
    fflush(stdin);
    scanf("%c", &exitChoice);
    printf("\n");

    while(exitChoice != 's' && exitChoice != 'S' && exitChoice != 'n' && exitChoice != 'N')
    {
        printf("_____________________________________________________________________________\n\n");
        printf("*** Opcion invalida. Ingrese una opcion correcta. (S: Si / N: No) *** \n\n");
        printf("_____________________________________________________________________________\n\n");
        fflush(stdin);
        scanf("%c", &exitChoice);
        printf("\n");
    }

    if (exitChoice == 's' || exitChoice == 'S')
    {
        system("cls");

        printf("_____________________________________________________________________________\n\n");
        printf("*** Saliendo del programa... *** \n");
        printf("_____________________________________________________________________________\n\n");

        return 1;
    }

    system("cls");


    return 0;
}
