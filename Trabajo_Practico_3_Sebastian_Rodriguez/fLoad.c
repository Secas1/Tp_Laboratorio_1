#include <stdio.h>
#include <stdlib.h>
#include "fLoad.h"

/** \brief
 *
 * \param OptMenu char*
 * \return int
 *
 */
int menu(char* OptMenu)
{
    int option=-1;

    printf("%s",OptMenu);
    fflush(stdin);
    scanf("%d",&option);

    return option;
}

/** \brief
 *
 * \param message[] char
 * \return int
 *
 */
int intLoad(char message[])
{
    int i;

    printf("Ingresar %s",message);
    scanf("%d",&i);

    return i;
}

/** \brief
 *
 * \param message[] char
 * \return float
 *
 */
float floatLoad(char message[])
{
    float f;

    printf("Ingresar %s",message);
    scanf("%f",&f);

    return f;
}

/** \brief
 *
 * \param message[] char
 * \return char
 *
 */
char charLoad(char message[])
{
    char c;

    printf("Ingresar %s",message);
    scanf("%c",&c);

    return c;
}

/** \brief
 *
 * \param message[] char
 * \param string[] char
 * \param len int
 * \return void
 *
 */
void stringLoad(char message[],char string[],int len)
{
    fflush(stdin);
    printf("Ingresar %s",message);
    gets(string);
    stringValidation(message,string,len);
}

/** \brief
 *
 * \param errorMessage[] char
 * \param string[] char
 * \param len int
 * \return void
 *
 */
void stringValidation(char errorMessage[],char string[],int len)
{
    while(strlen(string)>=len)
    {
        printf("Reingresar %s",errorMessage);
        fflush(stdin);
        gets(string);
    }
}

/** \brief
 *
 * \param location[] char
 * \return void
 *
 */
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
