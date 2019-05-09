#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LIBRE 0
#define OCUPADO 1
#define BORRADO -1

typedef struct
{
    int id;
    char descripcion[50];
    char localidad[50];
    char cuit[50];
    char duenio[50];
    int estado;

} eProveedor;

void hardcodearProveedores(eProveedor [], int );
void mostrarProveedores(eProveedor);
void mostrarArrayProveedores(eProveedor [], int );

