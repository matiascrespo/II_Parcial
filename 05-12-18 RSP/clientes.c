#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "clientes.h"
#include "string.h"
#include "utn.h"



eClientes* clientes_new()
{
    eClientes* nuevoCliente;

    nuevoCliente = malloc(sizeof(eClientes));

    if(nuevoCliente == NULL)
    {
        printf("No hay mas lugar para cargar clientes");
    }

    else
    {
        strcpy(nuevoCliente->nombre, "");
        nuevoCliente->sexo = 'z';
        nuevoCliente->numeroTelefono = 0;
        nuevoCliente->id = 0;
        nuevoCliente->importe= 0;
    }

    return nuevoCliente;
}


eClientes* clientes_newParametros(char* idSrt,char* nombreStr,char sexoSrt, char* importeSrt, char* numeroTelefonoSrt)
{
    eClientes *aux;

    aux = clientes_new();

    if(aux != NULL)
    {
        aux->id = atoi(idSrt);
        strcpy(aux->nombre,nombreStr);
        aux->sexo= sexoSrt;
        aux->importe = atof(importeSrt);
        aux->numeroTelefono = atoi(numeroTelefonoSrt);
    }

    return aux;
}


// SET GET CLIENTES

//ID

int clientes_setId(eClientes* this,int id)
{
    int todoOk = 0;
    if(this!= NULL && id>0) // CONDICION PARA SETEAR
    {
        this->id = id;
        todoOk = 1;
    }


    return todoOk;
}

int clientes_getId(eClientes* this,int* id)
{
    int todoOk = 0;
    if(this!= NULL && id != NULL) // CONDICION PARA OBTENER
    {
        *id = this->id;
        todoOk = 1;
    }

    return todoOk;
}


// NOMBRE

int clientes_setNombre(eClientes* this, char* nombre)
{
    int todoOk = 0;
    if(this!= NULL && strlen(nombre)>0)
    {
        strcpy(this->nombre, nombre);
        todoOk = 1;
    }

    return todoOk;
}


int clientes_getNombre(eClientes* this,char* nombre)
{
    int todoOk = 0;
    if(this!= NULL && nombre != NULL)
    {
        strcpy(nombre,this->nombre);
        todoOk = 1;
    }
    return todoOk;
}


//SEXO

int clientes_setSexo(eClientes* this,char sexo)
{
    int todoOk = 0;
    if(this!= NULL )
    {
        this->sexo = 'z';
        todoOk = 1;
    }

    return todoOk;
}


int clientes_getSexo(eClientes* this,char* sexo)
{
    int todoOk = 0;
    if(this!= NULL && sexo != NULL)
    {
        *sexo = this->sexo;
        todoOk = 1;
    }
    return todoOk;
}

//NUMERO TELEFONO


int clientes_setNumeroTelefono(eClientes* this,int numeroTelefono)
{
    int todoOk = 0;
    if(this!= NULL && numeroTelefono>0) // CONDICION PARA SETEAR
    {
        this->numeroTelefono = numeroTelefono;
        todoOk = 1;
    }


    return todoOk;
}

int clientes_getNumeroTelefono(eClientes* this,int* numeroTelefono)
{
    int todoOk = 0;
    if(this!= NULL && numeroTelefono != NULL) // CONDICION PARA OBTENER
    {
        *numeroTelefono = this->numeroTelefono;
        todoOk = 1;
    }

    return todoOk;
}

// IMPORTE


int clientes_setImporte(eClientes* this,float importe)
{
    int todoOk = 0;
    if(this != NULL && importe>0)
    {
        this->importe = importe;
        todoOk = 1;
    }

    return todoOk;
}
int clientes_getImporte(eClientes* this,float* importe)
{
    int todoOk = 0;
    if(this != NULL && importe != NULL)
    {
        *importe = this->importe;
    }

    return todoOk;
}

// GET SET ABONO






