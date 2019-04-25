#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"
int insertProducto(eProducto elProducto, eProducto listado[])
{
    int indice;
    indice = dameLugarLibre(listado);
    if(indice!=-1)
    {
        listado(indice).estado=-1;
    }
    return indice;
}
int borrarProducto(eProducto elProducto, eProducto listado[])
{
    int indice;
    indice=existeProducto(elProducto, listado);
    if(indice!=-1)
    {
        listado(indice).estado=-1;
    }
    return indice;
}
void construisArray(eProducto listado[], int TAM)
{
    int i;
    for(i=0;i<TAM;i++)
    {
        listado[i].estado=0;
        strcpy(listado[i].nombre,"nn");
        strcpy(listado[i].codigoBarra,"");
        strcpy(listado[i].fechaVencimiento,"");
        listado[i].precio=0;
    }
}
void mostarArray(int TAM, eProducto listado[])
{
    int i;
    for(i=0;i<TAM;i++)
    {
        mostrarProducto(listado[i]);
    }
}
void cargarArray(int TAM, eProducto listado[])
{
    int i;
    for(i=0;i<TAM;i++)
    {
        listado[i]=pedirProducto();
    }
}
eProducto pedirProducto()
{
    eProducto retorno;

    printf("Ingrese nombre del producto: ");
    fflush(stdin);
    gets(retorno.nombre);

    printf("Ingrese codigo de barra del producto: ");
    fflush(stdin);
    gets(retorno.codigoBarra);

    printf("Ingrese fecha de vencimiento del producto: ");
    fflush(stdin);
    gets(retorno.fechaVencimiento);

    printf("Ingrese proveedor del producto: ");
    fflush(stdin);
    gets(retorno.proveedor);

    printf("Ingrese precio del producto: ");
    fflush(stdin);
    scanf("%f",&retorno.precio);





    return retorno;
}
void mostrarProducto(eProducto productoAMostrar)
{

    printf("\nEl nombre es: %s",productoAMostrar.nombre);
    printf("\nEl codigo de barra es: %s",productoAMostrar.codigoBarra);
    printf("\nLa fecha es: %s",productoAMostrar.fechaVencimiento);
    printf("\nEl proveedor es: %s",productoAMostrar.proveedor);
    printf("\nLa fecha es: %.2f",productoAMostrar.precio);
}
