#include <stdlib.h>
#include <stdio.h>
#include "MathLab.h"

#define TRUE 1
#define FALSE 0


//================================================================================================================================================//
//                                                          VALIDACION DE NUMEROS                                                                 //
//================================================================================================================================================//

/** \brief Solicita una cadena de texto para determinar si es un numero o no.
 *
 * \param  char str[]                               Cadena de texto a evaluar
 * \return                                          Devuelve TRUE: Es un numero / FALSE: No es un numero
 *
 */

int math_isNumber(char str[])
{
    int i;
    int dotCounter = 0;

    for(i = 0; str[i] != '\0'; i++)
    {
        if(str[i] >= '0' && str[i] <= '9')
        {
            continue;
        }
        else
        {
            if(str[i] == '+' || str[i] == '-')
            {
                if(i == 0)
                {
                    continue;
                }
                else
                {
                    return FALSE;
                }
            }
            else
            {
                if(str[i] == '.')
                {
                    dotCounter++;

                    if(dotCounter <= 1)
                    {
                        continue;
                    }
                    else
                    {
                        return FALSE;
                    }
                }
                else
                {
                    return FALSE;
                }
            }
        }
    }

    return TRUE;
}

//**************************************************************************************************************************************************//

/** \brief Determina si un numero es fraccionario
 *
 * \param   float number            Solicita el numero
 * \return  int isFractional        Devuelve TRUE: Si el numero es fraccionario / FALSE: Si el numero no es fraccionario
 *
 */

int math_numberIsFractional(float number)
{
    int isFractional;

    if(number == (int)number)
    {
        isFractional = FALSE;
    }
    else
    {
        isFractional = TRUE;
    }

    return isFractional;
}


//================================================================================================================================================//
//                                                            OPERACIONES MATEMATICAS                                                             //
//================================================================================================================================================//

/** \brief Guarda el resultado de las operaciones basicas matematicas entre dos numeros.
 *
 * \param   float firstNumber                               Solicita el primer operando
 * \param   float secondNumber                              Solicita el segundo operando
 * \param   char op                                         Solicita el operador matematico
 * \return  float result                                    Devuelve el resultado
 *
 */

float math_getBasicOperationsResult(float firstNumber, float secondNumber, char op)
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

//**************************************************************************************************************************************************//

/** \brief Calcula el factorial del numero. Imprime un mensaje de error si el factorial no puede calcular
 *
 * \param   float number                                        Solicita el numero para calcular el factorial
 * \return  double result                                       Devuelve el resultado del factorial del numero
 *
 */

double math_getFactorialResult(float number)
{
    double result = 1;
    int i;

    if(math_numberIsFractional(number) == 1)
    {
        printf("ERROR: No se puede calcular el factorial de un numero fraccionario. \n");
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
