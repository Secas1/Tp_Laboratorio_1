#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "ArrayEmployees.h"

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}typedef Employee;

int menu (Employee* list,int len);
int initEmployees(Employee* list,int len);
int addEmployee(Employee* list,int len,int id,char name[],char lastname[],float salary,int sector);
int findEmplyeeById(Employee* list,int len,int id);
int removeEmployee(Employee* list,int len,int id);
int sortEmployee(Employee* list,int len, int order);
int printEmployees(Employee* list,int length);

int main()
{
    int t=10;
    Employee Employees[t];

    initEmployees(&Employees,t);
    menu(&Employees,t);
}


int menu (Employee* list,int len)
{
    int x=0;
    int y;

    do
    {
        printf("\n####MENU PRINCIPAL####");
        printf("\n1.Alta");
        printf("\n2.Modificar");
        printf("\n3.Baja");
        printf("\n4.Informar");
        printf("\n5.Salir\n");
        scanf("%d",&y);

        switch(y)
        {
            case 1:
            employeeData(&list,len,51,51);
            break;

            case 4:
            /*printf("\n%d",list[0].id);
            printf("\t%s",list[0].name);
            printf("\t%s",list[0].lastName);
            printf("\t%f",list[0].salary);
            printf("\t%d",list[0].sector);
            printf("\t%d",list[0].isEmpty);*/
            //printEmployees(list,len);
            break;
        }

        system("pause");
        system("cls");
    }while(x==0);
}

int employeeData(Employee* list,int len,int lenName,int lenLastName)
{
    int auxId;
    char auxName[100];
    char auxLastName[100];
    float auxSalary;
    int auxSector;

    int out;

    printf("\nId: ");
    scanf("%d",&auxId);

    do
    {
        for(int i=0;i<len;i++)
        {
            if(list[i].isEmpty==0&&list[i].id==auxId)
            {
                printf("\nPlease re-enter the ID: ");
                scanf("%d",&auxId);
            }
            else
            {
                out=1;
            }
        }
    }while(out==0);

    out=0;
    fflush(stdin);
    printf("\nName: ");
    gets(auxName);

    do
    {
        if(strlen(auxName)>lenName)
        {
            printf("Please re-enter the Name: ");
            gets(auxName);
        }
        else
        {
            out=1;
        }
    }while(out==0);

    out=0;
    fflush(stdin);
    printf("\nLast Name: ");
    gets(auxLastName);

    do
    {
        if(strlen(auxName)>lenName)
        {
            printf("Please re-enter the Last Name: ");
            gets(auxName);
        }
        else
        {
            out=1;
        }
    }while(out==0);

    printf("\nSalary: ");
    fflush(stdin);
    scanf("%d",&auxSalary);

    printf("\nSector: ");
    fflush(stdin);
    scanf("%d",&auxSector);

    addEmployee(list,len,auxId,auxName,auxLastName,auxSalary,auxSector);

    printEmployees(list,len);
}

int initEmployees(Employee* list,int len)
{
    for(int i=0;i<len;i++)
    {
        list[i].isEmpty=1;
    }
}

int addEmployee(Employee* list,int len,int id,char name[],char lastName[],float salary,int sector)
{

    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==1)
        {
            list[i].id=id;
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastName);
            list[i].salary=salary;
            list[i].sector=sector;
            list[i].isEmpty=0;
            break;
        }
    }

    /*list->id=id;
    strcpy(list->name,name);
    strcpy(list->lastName,lastName);
    list->salary=salary;
    list->sector=sector;
    list->isEmpty=0;*/
}

int findEmplyeeById(Employee* list,int len,int id)
{
    int position;

    for(int i=0;i<len;i++)
    {
        if(list[i].id==id)
        {
            position=i;
            break;
        }
    }

    return position;
}

int removeEmployee(Employee* list,int len,int id)
{
    for(int i=0;i<len;i++)
    {
        if(list[i].id==id)
        {
            list[i].isEmpty=1;
            break;
        }
    }
}

int sortEmployee(Employee* list,int len, int order)
{

}

int printEmployees(Employee* list,int len)
{
    for(int i=0;i<len;i++)
    {
        if(list[i].isEmpty==0)
        {
            printf("\n%d",list[i].id);
            printf("\t%s",list[i].name);
            printf("\t%s",list[i].lastName);
            printf("\t%f",list[i].salary);
            printf("\t%d\n",list[i].sector);
        }
    }
}

