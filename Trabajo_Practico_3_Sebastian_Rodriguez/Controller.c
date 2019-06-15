#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    if(pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"r");

        if(pFile!=NULL)
        {
            parser_EmployeeFromText(pFile,pArrayListEmployee);
        }
        else
        {
            printf("\n Error al abrir el archivo desde texto.\n");
        }
    }
    else
    {
        printf("\nError al cargar puntero para lectura en texto\n");
    }

    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;

    if(pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"rb");

        if(pFile!=NULL)
        {
            parser_EmployeeFromBinary(pFile,pArrayListEmployee);
        }
        else
        {
            printf("\nError al abrir el archivo desde binario.\n");
        }
    }
    else
    {
        printf("\nError al cargar puntero para lectura en binario\n");
    }

    return 1;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    char id[15],nombre[128],horasTrabajadas[15],sueldo[15];

    if(pArrayListEmployee!=NULL)
    {

        itoa(ll_len(pArrayListEmployee)+1,id,10);

        stringLoad("Nombre: ",nombre,128);
        stringLoad("Horas trabajadas: ",horasTrabajadas,15);
        stringLoad("Suledo: ",sueldo,15);

        ll_add(pArrayListEmployee,employee_newParametros(id,nombre,horasTrabajadas,sueldo));
        printf("\nCarga completada\n");
    }
    else
    {
        printf("\nError al cargar\n");
    }

    return 1;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int id,confirm;
    Employee* pEmployee;

    if(pArrayListEmployee!=NULL)
    {
        id=intLoad("ID de empleado a modificar: ");

        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee=ll_get(pArrayListEmployee,i);

            if(pEmployee->id==id)
            {
                printf("\n%d %s %d %d\n",id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);

                switch(menu("\n1.Nombre\n2.Horas trabajadas\n3.Sueldo\nOpcion: "))
                {
                    case 1:
                    stringLoad("Nuevo nombre: ",pEmployee->nombre,128);
                    break;
                    case 2:
                    employee_setHorasTrabajadas(pEmployee,intLoad("Nueva cantidad de horas trabajadas :"));
                    break;
                    case 3:
                    employee_setSueldo(pEmployee,intLoad("Nuevo sueldo: "));
                    break;
                    default:
                    printf("\nOpcion invalida.\n");
                    break;
                }
            }
        }
    }
    return 1;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int id,confirm;
    Employee* pEmployee;
    if(pArrayListEmployee!=NULL)
    {
        id=intLoad("ID de empleado a eliminar: ");

        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee=ll_get(pArrayListEmployee,i);

            if(pEmployee->id==id)
            {
                printf("\n%d %s %d %d\n",id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);

                if((menu("\nSeguro de eliminar?\n1.Si\n2.No\nOpcion: "))==1)
                {
                    ll_remove(pArrayListEmployee,ll_indexOf(pArrayListEmployee,pEmployee));
                    printf("\nEliminacion completada\n");
                }
            }
        }

    }
    return 1;
}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{

    Employee* pEmployee;

    if(pArrayListEmployee!=NULL)
    {
        for(int i=0;i<ll_len(pArrayListEmployee);i++)
        {
            pEmployee=ll_get(pArrayListEmployee,i);

            printf("%10d%20s%10d%10d\n",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
        }
    }

    return 1;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    if(pArrayListEmployee!=NULL)
    {
        switch(menu("\n1.Ordenar por id\n2.Ordenar por nobmre\n3.Ordenar por horas trabajadas\n4.Ordenar por sueldo\nOpcion: "))
        {
            case 1:
                if((menu("\n1.Ordenamiento ascendente\n2.Ordenamiento descendente\nOpcion: "))==1)
                {
                    printf("\nEstoy ejecutandome :D\n");
                    ll_sort(pArrayListEmployee,employee_sort_id,1);
                    printf("\nEstoy cerrandome :D\n");
                    system("pause");
                }
                else
                {
                    ll_sort(pArrayListEmployee,employee_sort_id,0);
                }
            break;
            case 2:
                if((menu("\n1.Ordenamiento ascendente\n2.Ordenamiento descendente\nOpcion: "))==1)
                {
                    ll_sort(pArrayListEmployee,employee_sort_nombre,1);
                }
                else
                {
                    ll_sort(pArrayListEmployee,employee_sort_nombre,0);
                }
            break;
            case 3:
                if((menu("\n1.Ordenamiento ascendente\n2.Ordenamiento descendente\nOpcion: "))==1)
                {
                    ll_sort(pArrayListEmployee,employee_sort_horasTrabajadas,1);
                }
                else
                {
                    ll_sort(pArrayListEmployee,employee_sort_horasTrabajadas,0);
                }
            break;
            case 4:
                if((menu("\n1.Ordenamiento ascendente\n2.Ordenamiento descendente\nOpcion: "))==1)
                {
                    ll_sort(pArrayListEmployee,employee_sort_sueldo,1);
                }
                else
                {
                    ll_sort(pArrayListEmployee,employee_sort_sueldo,0);
                }
            break;
        }

        controller_ListEmployee(pArrayListEmployee);
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* pEmployee;

    if(pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"w");

        if(pFile!=NULL)
        {
                fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
            for(int i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmployee=ll_get(pArrayListEmployee,i);

                fprintf(pFile,"%d,%s,%d,%d\n",pEmployee->id,pEmployee->nombre,pEmployee->horasTrabajadas,pEmployee->sueldo);
            }

            printf("\nArchivop guardado correctamente (Modo texto)\n");
            fclose(pFile);
        }
    }
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    FILE* pFile;
    Employee* pEmployee;

    if(pArrayListEmployee!=NULL)
    {
        pFile=fopen(path,"wb");

        if(pFile!=NULL)
        {
            for(int i=0;i<ll_len(pArrayListEmployee);i++)
            {
                pEmployee=ll_get(pArrayListEmployee,i);
                fwrite(pEmployee,sizeof(Employee),1,pFile);
            }
            printf("\nArchivo guardado correctamente(Modo texto)\n");
        }
    }
    return 1;
}

