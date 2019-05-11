#include <stdio.h>
#include <stdlib.h>
#include "fLoad.h"

int printMenu(char options[])
{
    int x=-1;

    printf("%s",options);
    fflush(stdin);
    scanf("%d",&x);

    return x;
}

int intLoad(char message[])
{
    int i;

    printf("\nIngresar %s",message);
    scanf("%d",&i);

    return i;
}

float floatLoad(char message[])
{
    float f;

    printf("\nIngresar %s",message);
    scanf("%f",&f);

    return f;
}

char charLoad(char message[])
{
    char c;

    fflush(stdin);
    printf("\n %s",message);
    scanf("%c",&c);

    return c;
}

void stringLoad(char message[],char string[],int len)
{
    fflush(stdin);
    printf("\nIngresar %s",message);
    gets(string);
    stringValidation(message,string,len);
}

void stringValidation(char errorMessage[],char string[],int len)
{
    while(strlen(string)>=len)
    {
        printf("\nReingresar %s",errorMessage);
        fflush(stdin);
        gets(string);
    }
}

void stringFix(char location[])
{
    int i=0;

    strlwr(location);

    location[0]=toupper(location[0]);

    while(location[i]!='\0')
    {
        if(isspace(location[i]))
        {
            location[i+1]=toupper(location[i+1]);
        }
        i++;
    }
}
