#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include <utn.h>
#include "parser.h"



/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *parch;

    if((parch=fopen("data.csv","r")) == NULL)
    {
        printf("El archivo no se pudo abrir.");
    }


    parser_EmployeeFromText(parch,pArrayListEmployee);

    fclose(parch);




    return 1;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE *binario;

    if((binario = fopen(path, "rb")) != NULL)
    {
        parser_EmployeeFromBinary(binario, pArrayListEmployee);
    }

    else if((binario = fopen(path, "wb"))!= NULL)
    {
        printf("\nSe ha creado un nuevo archivo.");

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
    Employee * aux;
    int todoOk = 0;
    int idAux, horasTrabajadasAux;
    float sueldoAux;
    char nombreAux[30];

    int r;



    printf("\t\tAgregar nuevo empleado\n");
    idAux = getValidInt("Ingrese id: ","Error");
    getValidString("Ingres nombre: ","Error. ",nombreAux);
    horasTrabajadasAux = getValidInt("Ingrese horas trabajadas: ","Error.");
    sueldoAux = getFloatOnly("Ingrese sueldo: ");

    aux = employee_new();

    r = employee_setId(aux,idAux);
    if(r==1)
    {

        r = employee_setNombre(aux,nombreAux);
        {
            if(r==1)
            {
                r=employee_setHorasTrabajadas(aux,horasTrabajadasAux);
                if(r== 1)
                {
                    r=employee_setSueldo(aux,sueldoAux);
                }
            }
        }
    }

    if(r==1)
    {
        ll_add(pArrayListEmployee,aux);
        todoOk = 1;
        printf("----1");
        system("pause");

    }


    return todoOk;
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
    int todoOk = 0;
    int idAux, horasTrabajadasAux;
    float sueldoAux;
    char nombreAux[30];
    int encontrado = 0;
    Employee *auxEmpleado;



    int i;


    idAux = getValidInt("Ingrese Id del empleado a modificar: ","Error.");

    for (i=0; i<ll_len(pArrayListEmployee); i++)
    {

        auxEmpleado = (Employee*) ll_get(pArrayListEmployee,i);
        if(idAux == auxEmpleado->id)
        {
//            printf("Empleado encontrado: \n");
//            printf(" Id: %d\n Nombre: %s\n Horas: %d\n Sueldo: %.2f\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);
//            system("pause");

            encontrado = 1;
            break;
        }

    }

    if(encontrado == 1)
    {
        int opcion = 0;

        system("cls");
        printf("\t\tMenu modificar\n\n");
        printf("1. Id.\n");
        printf("2. Nombre.\n");
        printf("3. Horas trabajadas.\n");
        printf("4. Sueldo.\n");
        printf("5. Regresar menu.\n\n");

        printf("Datos en lista: \n");
        printf("Id: %d\nNombre: %s\nHoras: %d\nSueldo: %.2f\n\n",auxEmpleado->id,auxEmpleado->nombre,auxEmpleado->horasTrabajadas,auxEmpleado->sueldo);

        opcion = getValidInt("Ingrese opcion: ","Error.");
        switch(opcion)
        {
        case 1:
            idAux = getValidInt("Ingrese nuevo Id: ","Error.");
            employee_setId(auxEmpleado,idAux);
            printf("Id modificado con exito.\n");
            break;
        case 2:
            getValidString("Ingrese nuevo nombre: ","Error.",nombreAux);
            employee_setNombre(auxEmpleado,nombreAux);
            printf("Nombre modificado con exito.\n");
            break;
        case 3:
            horasTrabajadasAux = getValidInt("Ingrese nuevas horas trabajadas: ","Error.");
            employee_setHorasTrabajadas(auxEmpleado,horasTrabajadasAux);
            printf("Horas trabajadas modificadas con exito.\n");
            break;
        case 4:
            sueldoAux = getFloatOnly("Ingrese nuevo sueldo: ");
            employee_setSueldo(auxEmpleado,sueldoAux);
            printf("Sueldo modificado con exito.\n");
            break;
        case 5:
            break;
        default:
            printf("Opcion incorrecta.\n");
            break;
        }

    }



    else
    {
        printf("El Id ingresado no corresponde con ningun empleado de la base de datos\n");
    }

    return todoOk;
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
    int esta = -1;
    esta = buscarEmpleado(pArrayListEmployee);
    char opcion;


    system("cls");

    if(esta >= 0)
    {
        opcion = getValidChar("Realmente desea eliminar? (s/n): ","Error.",'s','n');
        if(opcion == 's')
        {
            ll_remove(pArrayListEmployee,esta);
            printf("Empleado ha sido eliminado. \n");
        }
        else
        {
            printf("Se ha cancelado la operacion.\n");
        }

    }

    else
    {
        printf("No se pudo eliminar. El Id no corresponde con la base de datos.\n");

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
    int todoOk = 0;
    int i;

    Employee* aux;

    printf("Id -   Nombre   - Horas - Sueldo\n");

    for(i=0; i<ll_len(pArrayListEmployee); i++)
    {
        aux = (Employee*) ll_get(pArrayListEmployee,i);

        printf("%-4d  %-15s   %-7d  %-5.2f\n",aux->id,aux->nombre,aux->horasTrabajadas,aux->sueldo);
 //       printf("%-4d  %-15s   %-7d\n",aux->id,aux->nombre,aux->horasTrabajadas);

        todoOk = 1;
    }


    return todoOk;
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
    int opcion;
    int todoOk = 0;

    printf("\tOrdenar empleados\n\n");
    printf("1. Id.\n");
    printf("2. Nombre.\n");
    printf("3. Horas.\n");
    printf("4. Sueldo.\n");
    printf("5. Regresar.\n");

    opcion = getValidInt("Ingrese opcion: ","Error.");
    switch(opcion)
    {
    case 1:
        ll_sort(pArrayListEmployee,employee_sortId,1);
        printf("Empleados ordenados por Id Ascendente\n");
        todoOk = 1;
        break;
    case 2:
        ll_sort(pArrayListEmployee,employee_sortNombre,1);
        printf("Empleados ordenados por Nombre Ascendente\n");
        todoOk = 1;
        break;
    case 3:
        ll_sort(pArrayListEmployee,employee_sortHoras,1);
        printf("Empleados ordenados por Horas Ascendente\n");
        todoOk = 1;
        break;
    case 4:
        ll_sort(pArrayListEmployee,employee_sortSueldo,1);
        printf("Empleados ordenados por Sueldo Ascendente\n");
        todoOk = 1;
        break;
    default:
        printf("Opcion incorrecta. \n");
        break;
    }


    return todoOk;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path, LinkedList* pArrayListEmployee)
{
    FILE *texto;
    Employee *auxiliarEmpleado;

    int i, cantidad;

    texto = fopen(path, "w");
    cantidad = ll_len(pArrayListEmployee);

    if(texto != NULL && pArrayListEmployee != NULL)
    {
 //       rewind(texto);
        fprintf(texto, "id,nombre,horasTrabajadas,sueldo\n");

        for(i=0; i<cantidad; i++)
        {
            auxiliarEmpleado = (Employee*)ll_get(pArrayListEmployee, i);
            fprintf(texto, "%d,%s,%d,%f\n", auxiliarEmpleado->id, auxiliarEmpleado->nombre, auxiliarEmpleado->horasTrabajadas, auxiliarEmpleado->sueldo);
        }
        printf("\nLos datos se han guardado\n");
    }
    fclose(texto);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path, LinkedList* pArrayListEmployee)
{
    FILE*binario;
    Employee *auxiliarEmpleado;

    int i, cantidad;


    binario = fopen(path, "wb");
    cantidad = ll_len(pArrayListEmployee);

    if(pArrayListEmployee != NULL && binario != NULL)
    {
        for (i=0; i<cantidad; i++)
        {
            auxiliarEmpleado = (Employee*) ll_get(pArrayListEmployee, i);
            fwrite(auxiliarEmpleado, sizeof(Employee),1, binario);
        }
    }

    fclose(binario);


    return 1;
}

int controller_filterEmployee(LinkedList* pArrayListEmployee){
    LinkedList* listaEmpleadosFiltrados;
    int retorno = -1;
    char opcion;
    do{
        system("cls");
        printf("*** Filtrar empleados ***\n");
        printf("\n1- Filtrar por nombre.\n");
        printf("\n2- Filtrar por horas trabajadas.\n");
        printf("\n3- Filtrar por sueldo.\n");
        printf("\n4- Volver al menu principal.\n");
        printf("\nElija una opcion: ");
        fflush(stdin);
        scanf("%c",&opcion);
        switch (opcion){
            case '1':
                listaEmpleadosFiltrados = ll_filter(pArrayListEmployee, employee_filterByNombre);
                if (listaEmpleadosFiltrados != NULL){
                    controller_ListEmployee(listaEmpleadosFiltrados);
                }
                system("pause");
                break;
            case '2':
                listaEmpleadosFiltrados = ll_filter(pArrayListEmployee, employee_filterByHorasTrabajadas);
                if (listaEmpleadosFiltrados != NULL){
                    controller_ListEmployee(listaEmpleadosFiltrados);
                }
                system("pause");
                break;
            case '3':
                listaEmpleadosFiltrados = ll_filter(pArrayListEmployee, employee_filterBySueldo);
                if (listaEmpleadosFiltrados != NULL){
                    controller_ListEmployee(listaEmpleadosFiltrados);
                }
                system("pause");
                break;
            default:
                break;
        }
    }while (opcion != '4');
    return retorno;
}
