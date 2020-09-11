#include <stdlib.h>
#include <stdio.h>
#include "MathFunctions.h"
#include "Interface.h"


/** \brief Solicita un numero al usuario.
 *
 * \return float number         Devuelve el numero
 *
 */

float GetNumber(void)
{
    float number;

    printf("Ingrese un numero: ");
    scanf("%f", &number);

    return number;
}




/** \brief Guarda el resultado de las operaciones basicas matematicas.
 *
 * \param   float firstNumber     Solicita el primer operando
 * \param   float secondNumber    Solicita el segundo operando
 * \param   char op               Solicita el operador matematico
 * \return  float result          Devuelve el resultado
 *
 */

float BasicOperations(float firstNumber, float secondNumber, char op)
{
    float result;

    if(op == '+')
    {
        result = firstNumber + secondNumber;
    }
    else if (op == '-')
    {
        result = firstNumber - secondNumber;
    }
    else if (op == '*')
    {
        result = firstNumber * secondNumber;
    }
    else
    {
        result = firstNumber / secondNumber;
    }

    return result;
}




/** \brief Calcula el factorial del numero
 *
 * \param   float number          Solicita el numero
 * \return  double result         Devuelve el resultado
 *
 */

double Factorial(float number)
{
    double result;
    result = 1;

    int i;

    if(numberIsFractional(number) == 1)
    {
        /* Evita que la computadora intente resolver la
        operacion de un numero fraccionario */
    }
    else if(number > 0)
    {
        for(i = 1; i <= number; i++)
        {
            result *= i;
        }
    }

    return result;
}




/** \brief Determina si un numero es fraccionario
 *
 * \param   float number            Solicita el numero
 * \return  int isFractional        Devuelve si el numero es fraccional o no (1: Si / 0: No)
 *
 */

int numberIsFractional(float number)
{
    int isFractional;

    if(number == (int)number)
    {
        isFractional = 0;
    }
    else
    {
        isFractional = 1;
    }

    return isFractional;
}




/** \brief Muestra los resultados de las operaciones matematicas.
 *
 * \param   float firstNumber               Solicita el primer operando
 * \param   float secondNumber              Solicita el segundo operando
 * \param   float resultSum                 Solicita el resultado de la suma
 * \param   float resultSubs                Solicita el resultado de la resta
 * \param   float resultProd                Solicita el resultado del producto
 * \param   float resultDiv                 Solicita el resultado de la division
 * \param   float resultFactFirstNum        Solicita el resultado del factorial del primero numero
 * \param   float resultFactSecondNum       Solicita el resultado del factorial del segundo numero
 *
 */

void ShowResults(float firstNumber, float secondNumber, float resultSum, float resultSubs, float resultProd,
                 float resultDiv, float resultFactFirstNum, float resultFactSecondNum)
{
    system ("cls");

    // RESULTADOS SUMA - RESTA - PRODUCTO
    printf("_____________________________________________________________________________\n\n");
    printf("*** Resultados *** \n\n");
    printf("a) El resultado de %f + %f es: %f \n", firstNumber, secondNumber, resultSum);
    printf("b) El resultado de %f - %f es: %f \n", firstNumber, secondNumber, resultSubs);
    printf("c) El resultado de %f * %f es: %f \n", firstNumber, secondNumber, resultProd);

    // RESULTADO DIVISION
    if(secondNumber == 0)
    {
        printf("d) ERROR: No es posible dividir por cero. \n");
    }
    else
    {
        printf("d) El resultado de %f / %f es: %f \n", firstNumber, secondNumber, resultDiv);
    }

    // RESULTADOS FACTORIAL
    if(firstNumber < 0)
    {
        printf("e) ERROR: No es posible calcular el factorial de un numero negativo. \n");
    }
    else if(numberIsFractional(firstNumber) == 1)
    {
        printf("e) ERROR: Solo es posible calcular el factorial de numeros enteros. \n");
    }
    else
    {
        printf("e) El factorial de %.0f es: %.0f \n", firstNumber, resultFactFirstNum);
    }

    if(secondNumber < 0)
    {
        printf("   ERROR: No es posible calcular el factorial de un numero negativo. \n\n");
    }
    else if(numberIsFractional(secondNumber) == 1)
    {
        printf("   ERROR: Solo es posible calcular el factorial de numeros enteros. \n\n");
    }
    else
    {
        printf("   El factorial de %.0f es: %.0f \n\n", secondNumber, resultFactSecondNum);
    }
}

