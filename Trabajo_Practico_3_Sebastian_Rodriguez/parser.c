#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{

    char idStr[50],nombreStr[128],horasTrabajadasStr[50],sueldoStr[50];
    int r;

    r=fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]",idStr,nombreStr,horasTrabajadasStr,sueldoStr);

    do
    {
        r=fscanf(pFile,"%[^,] , %[^,] , %[^,] , %[^\n]",idStr,nombreStr,horasTrabajadasStr,sueldoStr);
        if(r==4)
        {
            ll_add(pArrayListEmployee,employee_newParametros(idStr,nombreStr,horasTrabajadasStr,sueldoStr));
        }

    }while(!feof(pFile));

    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
void parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int r;
    Employee* pEmployee;
    pEmployee=(Employee*)malloc(sizeof(Employee));
    do
    {
        r=fread(pEmployee,sizeof(Employee),1,pFile);

        if(r==4)
        {
            ll_add(pArrayListEmployee,pEmployee);
        }

    }while(!feof(pFile));

    return 1;
}
