#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"
#define clear() printf("\033[H\033[J")




int Suma(int x,int y)
{
    int a;

    a=x+y;

    return a;
}

int Resta(int x,int y)
{
    int a;

    a=x-y;

    return a;
}

int Division(int x,int y)
{
    int a;

    a=x/y;

    return a;
}

int Multiplicacion(int x,int y)
{
    int a;

    a=x*y;

    return a;
}

int Factorial(int x)
{
    int a=1;
    int b;

    for(x;x>0;x--)
    {
        a=a*x;
    }

    return a;
}
