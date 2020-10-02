#ifndef DATALAB_H_
#define DATALAB_H_

// *** ENTRADA DE DATOS *** //

// NUMERICOS
int data_getValidatedInt(int*, char*, int, int);
int data_getValidatedFloat(float*, char*, float, float);

// CARACTERES
int data_getValidatedChar(char*, char*, char, char);

// ARRAYS
int data_getValidatedAlphaString(char[], char*, int);
void data_getRelatedArrays(int[], float[], char[][21], int);




// *** SALIDA DE DATOS *** //

// ARRAYS
void data_showIntArray(int[], int);
void data_showFloatArray(float[], int);

// FALTA MOSTRAR ARRAY DE STRINGS ********************************************************

void data_showRelatedArrays(int[], float[], char[][21], int);




// *** ORDENAMIENTO DE DATOS *** //

// ARRAYS
int data_orderingIntArrayLtoH(int*, int);
int data_orderingIntArrayHtoL(int*, int);
int data_orderingFloatArrayLtoH(float*, int);
int data_orderingFloatArrayHtoL(float*, int);
void data_orderingRelatedArraysNumLtoH(int[], float[], char[][21], int);
void data_orderingRelatedArraysNumHtoL(int[], float[], char[][21], int);
void data_upperStringInitials(char[]);

// FALTA ORDENAR ARRAYS DE STRINGS ********************************************************

#endif // DATALAB_H_
