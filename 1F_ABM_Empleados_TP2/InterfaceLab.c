#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "InterfaceLab.h"


/** \brief Muestra el encabezado del programa (solo en al inicio).
 *
 */

void UI_PrintHeader(void)
{
    UI_printDivider();
    printf("                      ADMINISTRACION EMPLEADOS - TP 2 \n\n");
    printf("                         Christian Fernandez (1F) \n");
}

//**************************************************************************************************************************************************//

/** \brief Muestra el menu del programa y devuelve la eleccion del usuario.
 *
 * \return  int menuChoice                                      Devuelve la opcion elegida por el usuario
 *
 */

int UI_PrintMenu(void)
{
    int menuChoice;

    UI_printDivider();
    printf("Elija una opcion para comenzar a trabajar: \n\n");
    printf("[1] - Alta de empleados\n");
    printf("[2] - Modificacion de empleados\n");
    printf("[3] - Baja de empleados\n");
    printf("[4] - Listado de empleados. \n");
    printf("[5] - Salir de Programa. \n");
    UI_printDivider();
    scanf("%d", &menuChoice);
    printf("\n");

    return menuChoice;
}

//**************************************************************************************************************************************************//

/** \brief Imprime una linea separadora.
 *
 *
 */

void UI_printDivider(void)
{
    printf("\n_____________________________________________________________________________________________\n\n");
}

//**************************************************************************************************************************************************//

/** \brief Muestra un alerta al intentar salir del programa, valida la respuesta del usuario
 *         y devuelve la eleccion.
 *
 * \return char exitChoice                                      Devuelve el valor de la respuesta (1: Si / 0: No)
 *
 */

int UI_ExitAlert(void)
{
    int exitStatus = 0;
    char exitChoice;

    system("cls");

    UI_printDivider();
    printf("ATENCION:\nEsta seguro que desea salir del programa?\n(S: Si / N: No)\n");
    UI_printDivider();
    fflush(stdin);
    scanf("%c", &exitChoice);
    printf("\n");

    while(exitChoice != 's' && exitChoice != 'S' && exitChoice != 'n' && exitChoice != 'N')
    {
        UI_printDivider();
        printf("Opcion invalida.\nIngrese una opcion correcta.\nEsta seguro que desea salir del programa?\n(S: Si / N: No)");
        UI_printDivider();
        fflush(stdin);
        scanf("%c", &exitChoice);
        printf("\n");
    }

    if (exitChoice == 's' || exitChoice == 'S')
    {
        system("cls");

        UI_printDivider();
        printf("Saliendo del programa...\n");
        UI_printDivider();

        exitStatus = 1;
    }

    system("cls");

    return exitStatus;
}


