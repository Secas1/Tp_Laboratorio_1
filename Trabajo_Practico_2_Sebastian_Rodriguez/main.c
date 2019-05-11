#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fload.h"
#include "employee.h"
#define EMPLOYEE 5


int main()
{
    eEmployee eEmployees[EMPLOYEE];

    int out=0;
    int access=0;

    int auxId,auxSector;
    float auxSalary;
    char auxName[51];
    char auxLastName[51];

    int auxIdEliminar;
    char auxConEliminar;
    int auxIndex;

    int auxIdMod;
    int auxIndexMod;

    int option;

    float total=0;
    float promedio=0;
    int cont=0;
    int contSupera=0;


    initEmployees(eEmployees,EMPLOYEE);

    do
    {
        switch(printMenu("\n1.Alta\n2.Modificar\n3.Baja\n4.Informar\n"))
        {
            case 1:
            auxId=intLoad("id: ");
            stringLoad("nombre: ",auxName,51);
            stringLoad("apellido: ",auxLastName,51);
            auxSector=intLoad("sector: ");
            auxSalary=floatLoad("salario: ");

            addEmployee(eEmployees,EMPLOYEE,auxId,auxName,auxLastName,auxSalary,auxSector);
            access++;
            break;

            case 2:
            if(access>0)
            {
                auxIdMod=intLoad("id de empleado a modificar: ");
                auxIndexMod=findEmployeeById(eEmployees,EMPLOYEE,auxIdMod);

                switch(printMenu("\n1.Nombre\n2.Apellido\n3.Salario\n4.Sector\n"))
                {
                    case 1:
                    stringLoad("nuevo nombre: ",auxName,51);
                    strcpy(eEmployees[auxIndexMod].name,auxName);
                    break;

                    case 2:
                    stringLoad("nuevo apellido: ",auxLastName,51);
                    strcpy(eEmployees[auxIndexMod].lastName,auxLastName);
                    break;

                    case 3:
                    auxSalary=floatLoad("nuevo salario: ");
                    eEmployees[auxIndexMod].salary=auxSalary;
                    break;

                    case 4:
                    auxSector=intLoad("nuevo sector: ");
                    eEmployees[auxIdMod].sector=auxSector;
                    break;
                }
            }
            else
            {
                printf("\nPrimero ingresar un empleado\n");
            }
            break;

            case 3:
            if(access>0)
            {
                printEmployees(eEmployees,EMPLOYEE);
                auxIdEliminar=intLoad("id de empleado a eliminar: ");

                auxIndex=findEmployeeById(eEmployees,EMPLOYEE,auxIdEliminar);

                printf("\n%d %s %s %d %.2f",eEmployees[auxIndex].id,eEmployees[auxIndex].name,eEmployees[auxIndex].lastName,eEmployees[auxIndex].sector,eEmployees[auxIndex].salary);

                auxConEliminar=charLoad("\nEliminar? s/n\n");
                if(auxConEliminar=='s')
                {
                    eEmployees[auxIndex].isEmpty=1;
                }
            }
            else
            {
                printf("\nPrimero ingresar un empleado\n");
            }
            break;

            case 4:
            if(access>0)
            {
                option=printMenu("\n1.Ordenados\n2.Total y promedios\n");

                if(option==1)
                {
                    option=printMenu("\n1.Ascendente\n2.Descendente\n");

                    sortEmployees(eEmployees,EMPLOYEE,option);
                    printEmployees(eEmployees,EMPLOYEE);
                }
                else
                {

                    for(int i=0;i<EMPLOYEE;i++)
                    {
                        if(eEmployees[i].isEmpty==0)
                        {
                            total=total+eEmployees[i].salary;
                            cont++;
                        }
                    }

                    promedio=total/cont;

                    for(int i=0;i<EMPLOYEE;i++)
                    {
                        if(eEmployees[i].isEmpty==0&&eEmployees[i].salary>promedio)
                        {
                            contSupera++;
                        }
                    }

                    printf("\nTotal: %.2f",total);
                    printf("\nPromedio: %.2f",promedio);
                    printf("\nCant.Empleado que superan el promedio: %d\n",contSupera);
                }
            }
            else
            {
                printf("\nPrimero ingresar un empleado\n");
            }
            break;
        }

        system("pause");
        system("cls");
    }while(out==0);
}


