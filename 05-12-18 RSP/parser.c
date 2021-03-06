#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "string.h"
#include "clientes.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile, LinkedList* pArrayListEmployee)
{
    eClientes *pElement;
    int r;

    system("cls");



    //  Para 4:

//    char var1[30], var2[30], var3[30],var4[30];
//
//        r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);
//
//    while(!feof(pFile))
//    {
//        r = fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4);

//        printf("-----1");
//    system("pause");




//Para 3
    char var1[51], var2[51], var3[51],var4[51];
    char var5;

    r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);




    while(!feof(pFile))
    {
         printf("----1");
        r = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^\n]\n",var1,var2,var3,var4,var5);

        if(r==5)
        {
            pElement = clientes_new();

            r = clientes_setId(pElement,atoi(var1));
            if(r== 1)
            {

                r = clientes_setNumeroTelefono(pElement,atoi(var2));
                if(r==1)
                {

                    r= clientes_setImporte(pElement,atoi(var3));
                    if(r==1)
                    {

                        r = clientes_setNombre(pElement,var4);
                        {
                            if(r==1)
                            {
                                r = clientes_setSexo(pElement,var5);
                            }
                        }
                    }
                }
            }
        }

        if(r == 1)
        {
            ll_add(pArrayListEmployee,pElement);
        }
    }




    fclose(pFile);
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile, LinkedList* pArrayListEmployee)
{
    Employee* pElement;
    int r;



    while(!feof(pFile))
    {
        pElement = employee_new();
        r = fread(pElement,sizeof(Employee),1,pFile);

        if(r == 1 && pElement != NULL)
        {
//            auxEmpleado->id = pElement->id;
//            strcpy(auxEmpleado->nombre,pElement->nombre);
//            auxEmpleado->horasTrabajadas = pElement->horasTrabajadas;
//            auxEmpleado->sueldo = auxEmpleado->sueldo;

            ll_add(pArrayListEmployee,pElement);
        }
    }

    fclose(pFile);
    return 1;
}
