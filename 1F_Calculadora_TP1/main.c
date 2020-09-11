/********************************************************************
*
* Programa: Calculadora TP1*
*
<<<<<<< HEAD
* Version: 1.3.0 - 10 de septiembre de 2020
=======
* Version: 1.2 del 10 septiembre de 2020
>>>>>>> c4b2bdcfdb4bd9b8dadeb23a7b47399dde3c2157
* Autor: Christian Fernandez
*
*********************************************************************/

#include <stdlib.h>
#include <stdio.h>
#include "MathFunctions.h"
#include "Interface.h"


int main()
{

    float firstNumber;
    firstNumber = 0;
    float secondNumber;
    secondNumber = 0;
    int menuChoice;
    int exitStatus;
    float resultSum;
    float resultSubs;
    float resultProd;
    float resultDiv;
    double resultFactFirstNum;
    double resultFactSecondNum;

    int firstNumLoaded;
    firstNumLoaded = 0;
    int secNumLoaded;
    secNumLoaded = 0;

    PrintHeader();

    do
    {

        menuChoice = PrintMenu(firstNumber, secondNumber);

        switch(menuChoice)
        {
        case 1:
            PrintMessage("1er Operando");
            firstNumber = GetNumber();
            firstNumLoaded = 1;
            system("cls");
            break;

        case 2:
            PrintMessage("2do Operando");
            secondNumber = GetNumber();
            secNumLoaded = 1;
            system("cls");
            break;

        case 3:
            if(firstNumLoaded == 0 || secNumLoaded == 0)
            {
                system("cls");
                PrintMessage("Necesitas ingresar los dos operandos primero.");
            }
            else
            {
                resultSum = BasicOperations(firstNumber, secondNumber, '+');
                resultSubs = BasicOperations(firstNumber, secondNumber, '-');
                resultProd = BasicOperations(firstNumber, secondNumber, '*');
                resultDiv = BasicOperations(firstNumber, secondNumber, '/');
                resultFactFirstNum = Factorial(firstNumber);
                resultFactSecondNum = Factorial(secondNumber);
                system("cls");
                PrintMessage("Resultados Obtenidos");
            }
            break;

        case 4:
            if(firstNumLoaded == 0 || secNumLoaded == 0)
            {
                system("cls");
                PrintMessage("Necesitas ingresar los dos operandos primero.");
            }
            else
            {
                ShowResults(firstNumber, secondNumber, resultSum, resultSubs, resultProd, resultDiv, resultFactFirstNum, resultFactSecondNum);
            }
            break;

        case 5:
            exitStatus = ExitAlert();
            break;

        default:
            system("cls");
            PrintMessage("Opcion invalida. Ingrese una opcion correcta.");
        }

    } while (exitStatus != 1);

    return 0;
}






