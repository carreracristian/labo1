#ifndef CLIENTES_H_INCLUDED
#define CLIENTES_H_INCLUDED
typedef struct
{
    int id;
    char nombre[51];

}eLocalidad;
typedef struct
{
    int id;
    char nombre[51];
    char apellido[51];
    char sexo;
    char telefono[21];
    char domicilio[51];
    int idLocalidad;
    int isEmpty;

}eCliente;

#endif // CLIENTES_H_INCLUDED

int harcodearClientes(eCliente vec[], int tam, int cant);
void inicializarClientes(eCliente vec[], int tam);
int buscarLibreCliente(eCliente vec[],int tam);
void mostrarCliente(eCliente vec, eLocalidad localidad[],int tamaL);
void mostrarClientes(eCliente vec[], int tam,eLocalidad loc[],int tamaL);
int buscarClienteId(eCliente vec[], int tam, int id);
int altaCliente(eCliente vec[], int tam,int id,eLocalidad loc[],int tamaL);
void bajaCliente(eCliente vec[], int tam, eLocalidad loc[],int tamaL);
void ordenarCliente(eCliente vec[], int tam);
int menuModificacion();
void modificarCliente(eCliente vec[], int tam,eLocalidad loc[],int tamaL);
void obtenerNomCliente(eCliente vec[], int tam, int id, char dondeAsigar[]);
void obtenerNomLocalidad(int id,eLocalidad vec[], int tam,  char desc[]);
void harcodearLocalidad(eLocalidad loc[], int tamaL);
void mostrarLocalidades(eLocalidad loc[], int tamaL);
void mostrarLocalidad(eLocalidad loc);
