#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"
#include "fload.h"

int initEmployees(eEmployee list[],int len)
{
    int error=-1;

    for(int i=0;i<len;i++)
    {
        list[i].isEmpty=1;
        error=0;
    }

    return error;
}

int addEmployee(eEmployee list[],int len,int id,char name[],char lastname[],float salary,int sector)
{
    int error=-1;

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            list[i].id=id;
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastname);
            list[i].salary=salary;
            list[i].sector=sector;
            list[i].isEmpty=0;

            error=0;

            break;
        }
    }
    return error;
}

int findEmployeeById(eEmployee list[],int len,int id)
{
    int index=-1;

    for(int i=0;i<len;i++)
    {
        if(list[i].id==id)
        {
            index=i;
        }
    }
    return index;
}

int removeEmployee(eEmployee list[],int len,int id)
{
    int index=-1;

    for(int i=0;i<len;i++)
    {
        if(list[i].id==id)
        {
            index=id;
        }
    }

    return index;
}

int sortEmployees(eEmployee list[],int len,int order)
{
    eEmployee aux;

    if(order==0)
    {
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len-1;j++)
            {
                if(list[j].sector>list[j+1].sector)
                {
                    aux=list[j];
                    list[j]=list[j+1];
                    list[j+1]=aux;
                }
            }
        }
    }
    else
    {
        for(int i=0;i<len;i++)
        {
            for(int j=0;j<len-1;j++)
            {
                if(list[j].sector<list[j+1].sector)
                {
                    aux=list[j];
                    list[j]=list[j+1];
                    list[j+1]=aux;
                }
            }
        }
    }
}

int printEmployees(eEmployee list[],int len)
{
    printf(" Id\t\tNombre\t\t    Apellido\tSector\tSalario\n");

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("\n%4d %20s %20s %6d    %.2f",list[i].id,list[i].name,list[i].lastName,list[i].sector,list[i].salary);
        }
    }

    printf("\n");
}
