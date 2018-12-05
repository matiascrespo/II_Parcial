#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "abono.h"
#include "string.h"
#include "utn.h"





eAbono* abono_new()
{
    eAbono* nuevoAbono;

    nuevoAbono = malloc(sizeof(eAbono));

    if(nuevoAbono == NULL)
    {
        printf("No hay mas lugar para cargar abonos");
    }

    else
    {
        nuevoAbono->idCliente = 0;
        nuevoAbono->id = 0;
        nuevoAbono->importeFinal = 0;
        nuevoAbono->tipo = 0;
    }

    return nuevoAbono;
}


eAbono* abono_newParametros(char* idClienteStr,char* idStr,char* importeFinalStr, char* tipoStr)
{
    eAbono *aux;

    aux = abono_new();

    if(aux != NULL)
    {
        aux->idCliente = atoi(idClienteStr);
        aux->id = atoi(idStr);
        aux->importeFinal = atof(importeFinalStr);
        aux->tipo = atoi(tipoStr);
    }

    return aux;
}


// SET GET CLIENTES

//ID

int abono_setId(eAbono* this,int id)
{
    int todoOk = 0;
    if(this!= NULL && id>0) // CONDICION PARA SETEAR
    {
        this->id = id;
        todoOk = 1;
    }


    return todoOk;
}

int abono_getId(eAbono* this,int* id)
{
    int todoOk = 0;
    if(this!= NULL && id != NULL) // CONDICION PARA OBTENER
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}


// ID CLIENTE

int abono_setIdCliente(eAbono* this,int idCliente)
{
    int todoOk = 0;
    if(this!= NULL && idCliente>0) // CONDICION PARA SETEAR
    {
        this->idCliente = idCliente;
        todoOk = 1;
    }

    return todoOk;
}


int abono_getIdCliente(eAbono* this,int* idCliente)
{
    int todoOk = 0;
    if(this!= NULL && idCliente != NULL)
    {
        *idCliente = this->idCliente;
        todoOk = 1;

    }
    return todoOk;
}


//IMPORTE FINAL

int abono_setImporteFinal(eAbono* this,float importeFinal)
{
    int todoOk = 0;
    if(this!= NULL && importeFinal>0) // CONDICION PARA SETEAR
    {
        this->importeFinal = importeFinal;
        todoOk = 1;
    }

    return todoOk;
}


int abono_getImporteFinal(eAbono* this,float* importeFinal)
{
    int todoOk = 0;
    if(this!= NULL && importeFinal != NULL)
    {
        *importeFinal = this->importeFinal;
        todoOk = 1;

    }
    return todoOk;
}

//TIPO


int abono_setTipo(eAbono* this,int tipo)
{
    int todoOk = 0;
    if(this!= NULL && tipo>-1) // CONDICION PARA SETEAR
    {
        this->tipo = tipo;
        todoOk = 1;
    }


    return todoOk;
}

int abono_getTipo(eAbono* this,int* tipo)
{
    int todoOk = 0;
    if(this!= NULL && tipo != NULL) // CONDICION PARA OBTENER
    {
        *tipo = this->tipo;
        todoOk = 1;
    }

    return todoOk;
}



