#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "productos.h"

eProducto pedirProducto()
{
    eProducto productoParaRetornar;
    eProveedor listadoProveedores[3];

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(productoParaRetornar.nombre);

    mostrarArrayProveedores(listadoProveedores, 3);

    printf("Ingrese ID del proveedor: ");
    fflush(stdin);
    scanf("%d", &productoParaRetornar.idProveedor);

    printf("Ingrese codigo de barra: ");
    fflush(stdin);
    gets(productoParaRetornar.codigoDeBarra);

    printf("Ingrese fecha de vencimiento: ");
    fflush(stdin);
    gets(productoParaRetornar.fechaDeVencimiento);

    printf("Ingrese precio: ");
    scanf("%f", &productoParaRetornar.precio);

    productoParaRetornar.estado = OCUPADO;

    return productoParaRetornar;
}

void mostrarProducto(eProducto unProducto)
{
    printf("%15s %10s %10s %10f\n", unProducto.nombre, unProducto.codigoDeBarra, unProducto.fechaDeVencimiento, unProducto.precio);
}

void cargarArray(eProducto listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        listado[i]= pedirProducto();
    }
}

void mostrarArray(eProducto listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            mostrarProducto(listado[i]);
        }
    }
}

void construirArray(eProducto listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        listado[i].estado= LIBRE;
        listado[i].precio= 0;
        strcpy(listado[i].nombre, "");
        strcpy(listado[i].codigoDeBarra, "");
        strcpy(listado[i].fechaDeVencimiento, "");
    }
}

int insertarProducto(eProducto listado[], int tam)
{
    int indice;
    indice= dameLugarLibre(listado, tam);
    if(indice != -1)
    {
        listado[indice]= pedirProducto();
    }
    return indice;
}

int dameLugarLibre(eProducto listado[], int tam)
{
    int i;
    int index = -1;

    for(i=0; i<tam; i++)
    {
        if(listado[i].estado==LIBRE)
        {
            index = i;
            break;
        }
    }
    return index;
}

void mostrarArrayProductosConProveedor(eProducto listadoProductos[], eProveedor listadoProveedores[], int tamprod, int tamprov)
{
    int i, j;
    for(i=0; i<tamprod; i++)
    {
        mostrarProducto(listadoProductos[i]);

        for(j=0; j<tamprov; j++)
        {
            if(listadoProductos[i].idProveedor == listadoProveedores[j].id)
            {
                printf("%10s", listadoProveedores[j].duenio);
                printf("\n");
                break;
            }
        }
    }
}

int borrarProducto(eProducto lista[], int tam)
{
    int i;
   char codigo[50];
   int loEncontro = 0;

   printf("Ingrese el codigo de barras: ");
   fflush(stdin);
   gets(codigo);

   for(i=0; i<tam; i++)
   {
       if(strcmp(lista[i].codigoDeBarra, codigo)==0)
       {
          lista[i].estado = LIBRE;
            loEncontro = 1;
           break;
       }

   }

   if(loEncontro==0)
   {
      printf("Codigo inexistente!!");
   }

    return 0;
}

void inicializarProductos(eProducto listaProductos[],int tam)
{

    float precio[3]={50,42.95,9.52};
    char nombre[3][50]={"Agua 2Lt","Cap. Espacio","Turron"};
    char codigoDeBarra[3][13]={"77951234","77959876","70"};
    char fechaDeVencimiento[3][50]={"22/10/2020","10/05/2019","15/12/2008"};

    int i;

    for(i=0;i<3;i++)
    {
        strcpy(listaProductos[i].codigoDeBarra,codigoDeBarra[i]);
        strcpy(listaProductos[i].nombre,nombre[i]);
        strcpy(listaProductos[i].fechaDeVencimiento, fechaDeVencimiento[i]);
        listaProductos[i].precio=precio[i];
        listaProductos[i].estado = OCUPADO;
    }



}

int editarProducto(eProducto lista[], int tam)
{
   int i;
   char codigo[50];
   int loEncontro = 0;

   printf("Ingrese el codigo de barras: ");
   fflush(stdin);
   gets(codigo);

   for(i=0; i<tam; i++)
   {
       if(strcmp(lista[i].codigoDeBarra, codigo)==0)
       {
           printf("Ingrese el nuevo precio: ");
           scanf("%f", &lista[i].precio);
            loEncontro = 1;
           break;
       }

   }

   if(loEncontro==0)
   {
      printf("Codigo inexistente!!");
   }

   return 0;
}

/*
    MAIN: productos.h
    PRODUCTO.C: productos.h
    PRODUCTO.H: proveedores.h
    PROVEEDORES.C: proveedores.h
    PROVEEDORES.H: NADA.
*/

