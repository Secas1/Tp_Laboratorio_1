#include <stdio.h>
#include <stdlib.h>
#include "Operaciones.h"

/*calculadora*/

int main()
{
    int x;
    int x2;
    int c=0;

    int a=0;
    int b=0;

    do
    {
        printf("\n\n***** MENU *****");
        printf("\n1.Ingresar 1er Operando (A=%d)",a);
        printf("\n2.Ingresar 2do Operando (b=%d)",b);
        printf("\n3.Suma \n");
        printf("4.Resta \n");
        printf("5.Division \n");
        printf("6.Multiplicacion \n");
        printf("7.Factorial\n");
        printf("0.Salir");
        printf("\nOpcion: ");
        scanf("%d",&x);

        switch(x)
        {
            case 0:
            c=1;
            break;

            case 1:
            printf("Ingresar Primero Operando: ");
            scanf("%d",&a);
            break;

            case 2:
            printf("Ingresar Segundo Operando: ");
            scanf("%d",&b);
            break;

            case 3:
            x=Suma(a,b);
            printf("El resultado de %d + %d es: %d\n",a,b,x);
            break;

            case 4:
            x=Resta(a,b);
            printf("El resultado de %d - %d es: %d\n",a,b,x);
            break;

            case 5:
            if(b!=0)
            {
                x=Division(a,b);
                printf("El resultado de %d / %d es: %d\n",a,b,x);
            }
            else
            {
                printf("No es posible dividir por 0.\n");
            }
            break;

            case 6:
            x=Multiplicacion(a,b);
            printf("El resultado de %d * %d es: %d\n",a,b,x);

            case 7:
            x=Factorial(a);
            x2=Factorial(b);
            printf("El factorial de A es: %d y el factorial de B es: %d\n",x,x2);
            break;
        }
    system("pause");
    system("cls");
    }while(c==0);

    return 0;
}


