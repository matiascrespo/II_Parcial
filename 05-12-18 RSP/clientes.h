#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED

typedef struct
{
    int id;
    char nombre[51];
    char sexo;
    int numeroTelefono;
    float importe;
}eClientes;


typedef struct
{
    int id;
    int tipo;
    int idCLiente;
    float importeFinal;
}eAbono;

eClientes* clientes_new();
eClientes* clientes_newParametros(char* idSrt,char* nombreStr,char sexoSrt, char* importeSrt, char* numeroTelefonoSrt);
//void employee_delete();


//CLIENTES

int clientes_setId(eClientes* this,int id);
int clientes_getId(eClientes* this,int* id);

int clientes_setNombre(eClientes* this,char* nombre);
int clientes_getNombre(eClientes* this,char* nombre);

int clientes_setSexo(eClientes* this,char sexo);
int clientes_getSexo(eClientes* this,char* sexo);

int clientes_setNumeroTelefono(eClientes* this,int numeroTelefono);
int clientes_getNumeroTelefono(eClientes* this,int* numeroTelefono);

int clientes_setImporte(eClientes* this,float importe);
int clientes_getImporte(eClientes* this,float* importe);


//ABONO
int abono_setId(eAbono* this,int id);
int abono_getId(eAbono* this,int* id);

int abono_setTipo(eAbono* this,int tipo);
int abono_getTipo(eAbono* this,int* tipo);

int abono_setIdCliente(eAbono* this,int idCliente);
int abono_getIdCliente(eAbono* this,int* idCliente);

int abono_setImporteFinal(eAbono* this,float ImporteFinal);
int abono_getImporteFinal(eAbono* this,float* ImporteFinal);


#endif // CLIENTES_H_INCLUDED
