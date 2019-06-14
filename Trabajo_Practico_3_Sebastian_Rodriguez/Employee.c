#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "LinkedList.h"
#include "Controller.h"

/** \brief
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
    Employee* pEmployee;

    pEmployee=(Employee*)malloc(sizeof(Employee));

    if(pEmployee!=NULL)
    {
        return pEmployee;
    }

    printf("\nError al crear puntero <Employee>\n");
}

/** \brief
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    Employee* pEmployee;

    pEmployee=employee_new();

    employee_setId(pEmployee,atoi(idStr));
    employee_setNombre(pEmployee,nombreStr);
    employee_setHorasTrabajadas(pEmployee,atoi(horasTrabajadasStr));
    employee_setSueldo(pEmployee,atoi(sueldoStr));

    return pEmployee;
}

int employee_sort_nombre(Employee* pEmployeeFirst,Employee* pEmployeeSecond)
{
    int returnAux;

    if(pEmployeeFirst!=NULL&&pEmployeeSecond!=NULL)
    {
        returnAux=strcmp(pEmployeeFirst->nombre,pEmployeeSecond->nombre);
    }

    return returnAux;
}

/** \brief
 *
 * \param pEmployeeFirst Employee*
 * \param pEmployeeSecond Employee*
 * \return int
 *
 */
int employee_sort_horasTrabajadas(Employee* pEmployeeFirst,Employee* pEmployeeSecond)
{
    int horasTrabajadas1,horasTrabajadas2,returnAux;

    if(pEmployeeFirst !=NULL && pEmployeeSecond !=NULL)
    {
        employee_getHorasTrabajadas(pEmployeeFirst,&horasTrabajadas1);
        employee_getHorasTrabajadas(pEmployeeSecond,&horasTrabajadas2);

        if(horasTrabajadas1 < horasTrabajadas2)
        {
            returnAux = -1 ;
        }
        else if(horasTrabajadas1 == horasTrabajadas2)
        {
            returnAux = 0;
        }
        else if(horasTrabajadas1 > horasTrabajadas2)
        {
            returnAux = 1 ;
        }
    }

    return returnAux;
}

/** \brief
 *
 * \param pEmployeeFirst Employee*
 * \param pEmployeeSecond Employee*
 * \return int
 *
 */
int employee_sort_id(Employee* pEmployeeFirst,Employee* pEmployeeSecond)
{
    int id1,id2,returnAux;

    if(pEmployeeFirst !=NULL && pEmployeeSecond !=NULL)
    {
        employee_getId(pEmployeeFirst,&id1);
        employee_getId(pEmployeeSecond,&id2);

        if(id1 < id2)
        {
            returnAux = -1 ;
        }
        else if(id1 == id2)
        {
            returnAux = 0;
        }
        else if(id1 > id2)
        {
            returnAux = 1 ;
        }
    }

    return returnAux;
}

/** \brief
 *
 * \param pEmployeeFirst Employee*
 * \param pEmployeeSecond Employee*
 * \return int
 *
 */
int employee_sort_sueldo(Employee* pEmployeeFirst,Employee* pEmployeeSecond)
{
    int sueldo1,sueldo2,returnAux;

    if(pEmployeeFirst !=NULL && pEmployeeSecond !=NULL)
    {
        employee_getSueldo(pEmployeeFirst,&sueldo1);
        employee_getSueldo(pEmployeeSecond,&sueldo2);

        if(sueldo1 < sueldo2)
        {
            returnAux = -1 ;
        }
        else if(sueldo1 == sueldo2)
        {
            returnAux = 0;
        }
        else if(sueldo1 > sueldo2)
        {
            returnAux = 1 ;
        }
    }

    return returnAux;
}

/** \brief
 *
 * \param this Employee*
 * \param id int
 * \return int
 *
 */
int employee_setId(Employee* this,int id)
{
    if(this!=NULL)
    {
        this->id=id;
    }
}
/** \brief
 *
 * \param this Employee*
 * \param id int*
 * \return int
 *
 */
int employee_getId(Employee* this,int* id)
{
    if(this!=NULL)
    {
        *id=this->id;
    }
}

/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
    if(this!=NULL)
    {
        strcpy(this->nombre,nombre);
    }
}
/** \brief
 *
 * \param this Employee*
 * \param nombre char*
 * \return int
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
    if(this!=NULL)
    {
        strcpy(nombre,this->nombre);
    }
}

/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return int
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    if(this!=NULL)
    {
        this->horasTrabajadas=horasTrabajadas;
    }
}
/** \brief
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return int
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    if(this!=NULL)
    {
        *horasTrabajadas=this->horasTrabajadas;
    }
}

/** \brief
 *
 * \param this Employee*
 * \param sueldo int
 * \return int
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
    if(this!=NULL)
    {
        this->sueldo=sueldo;
    }
}

/** \brief
 *
 * \param this Employee*
 * \param sueldo int*
 * \return int
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
    *sueldo=this->sueldo;
}



