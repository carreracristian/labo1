#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Producto.h"
#define TAM 2

int main()
{
    /*eProducto produc1;

    produc1=pedirProducto();

    mostrarProducto(produc1);*/
    eProducto productos[TAM];

    //cargarArray(TAM, productos);
    construirArray(TAM, productos);
    mostarArray(TAM, productos);




    return 0;
}
