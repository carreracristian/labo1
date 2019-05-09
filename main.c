#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 10
#include "productos.h"

/*
1. TODOS LOS PRODUCTOS CON SU PROVEEDOR.
2. POR CADA PROVEEDOR, SUS PRODUCTOS.
3. POR CADA PROVEEDOR, LA CANTIDAD DE PRODUCTOS.
4. EL PRECIO PROMEDIO DE LOS PRODUCTOS DE CADA PROVEEDOR.
5. EL/LOS PROVEEDORES/ES QUE PROVEE MAS PRODUCTOS.
*/

int main()
{

    int opcion;

    eProducto unProducto;
    eProducto listadoProductos[T];
    eProveedor listadoProveedores[T];
    construirArray(listadoProductos,T);
    inicializarProductos(listadoProductos,T);

    do
    {
        printf("1.ALTA\n2.BAJA\n3.MODIFICAR\n4.MOSTAR.\n5.SALIR.\nElija opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
               insertarProducto(listadoProductos, T);
            break;
            case 2:
                borrarProducto(listadoProductos,T);
                break;
            case 3:
                editarProducto(listadoProductos, T);
                break;

            case 4:
                //mostrarArray(listadoProductos,T);
                mostrarArrayProductosConProveedor(listadoProductos,listadoProveedores,4,4);
                break;
        }
    }while(opcion!=5);







    return 0;
}
