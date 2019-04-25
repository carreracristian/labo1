#ifndef PRODUCTO_H_INCLUDED
#define PRODUCTO_H_INCLUDED

typedef struct
{
    char nombre[50];//Nombre del producto
    char codigoBarra[50];
    char fechaVencimiento[50];
    char proveedor[50];
    int estado;
    float precio;


}eProducto;

eProducto pedirProducto();

void mostrarProducto(eProducto);
void cargarArray(int TAM, eProducto listado[]);
void mostarArray(int TAM, eProducto listado[]);
void construisArray(eProducto[], int TAM);
#endif // PRODUCTO_H_INCLUDED
