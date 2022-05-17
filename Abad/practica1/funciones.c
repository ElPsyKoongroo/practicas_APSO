#include "funciones.h"

int suma(int array[])
{
    int suma = 0;
    for (int i = 0; i < 5; i++)
    {
        suma += array[i];
    }
    return suma;
}

double cubica(int array[])
{
    int max = 0;
    for (int i = 0; i < 5; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return cbrt(max);
}