#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1


typedef struct
{
    int estado;
    float salario;
    char nombre[10];
    char apellido[10];
    char id[100];
    char sector[10];
}eEmployee;


eEmployee pedirProducto();

void mostrarEmpleado(eEmployee);

void ordenarPorApellido(eEmployee[], int);

void ordenarPorSector(eEmployee[], int);

void mostrarSalario(eEmployee[], int);

int crearId(eEmployee[], int );

void cargarArray(eEmployee[], int);

void mostrarArray(eEmployee[], int);

void construirArray(eEmployee[], int);

int insertarEmpleado(eEmployee [], int );

int dameLugarLibre(eEmployee[],int);

int existeEmployee(eEmployee,eEmployee[]);

int borrarEmpleado(eEmployee[], int);

int editarEmpleado(eEmployee [], int );

