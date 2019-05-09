#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "proveedores.h"

void hardcodearProveedores(eProveedor listaProveedores[], int tam)
{
    int id[3] = {01, 02, 03};
    char descripcion[3][50] = {"Coca-Cola","Bagley","Arcor"};
    char localidad[3][50] = {"Avellaneda","Bahia Blanca","Rio Negro"};
    char cuit[3][50] = {"444", "555", "666"};
    char duenio[3][50] = {"Sr.Coca","Don Bagley","Sra. Arcor"};

    int i;
    for(i=0;i<3;i++)
    {
        listaProveedores[i].id = id[i];
        strcpy(listaProveedores[i].descripcion,descripcion[i]);
        strcpy(listaProveedores[i].localidad, localidad[i]);
        strcpy(listaProveedores[i].duenio, duenio[i]);
        strcpy(listaProveedores[i].cuit, cuit[i]);
        listaProveedores[i].estado = OCUPADO;
    }
}

void mostrarProveedores(eProveedor unProveedor)
{
    printf("%15s %15s %15s %10s %10d\n", unProveedor.duenio, unProveedor.descripcion, unProveedor.localidad, unProveedor.cuit, unProveedor.id);
}

void mostrarArrayProveedores(eProveedor listado[], int cant)
{
    printf("\n\n          Duenio    Descripcion       Localidad       Cuit         ID\n");
    printf("     *****************************************************************\n");
    hardcodearProveedores(listado, cant);
    int i;
    for(i=0; i<cant; i++)
    {
        mostrarProveedores(listado[i]);
    }
    printf("\n");
}


