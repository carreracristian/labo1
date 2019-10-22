#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <conio.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ImputAndValidate.h"
#include "categoria.h"

void harcodearCategoria(eCategoria vec[], int tam)
{
    int i;
    eCategoria lista[]=
    {
        {1,"Mesa"},
        {2,"Azar"},
        {3,"Estrategia"},
        {4,"Salon"},
        {5,"Magia"}

    };

    for( i=0 ;i<tam; i++)
    {
        vec[i] = lista[i];
    }
}

void mostrarCategoria(eCategoria vec)
{
    printf(" %d    %10s\n",vec.id,vec.descripcion);
}

void mostrarCategorias(eCategoria vec[], int tam)
{
    int i;
    system("cls");
    printf(" ID    CATEGORIA\n\n");

    for( i=0 ;i<tam; i++)
    {
        mostrarCategoria(vec[i]);
    }
}

void obtenerNomCat(eCategoria vec[], int tam, int id, char dondeAsignar[])
{
    int i;
    for( i=0 ;i<tam; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(dondeAsignar,vec[i].descripcion);
        }
    }
}
int buscarCategoriaId(eCategoria vec[], int tam, int id)
{
    int indice=-1;
    int i;

    for( i=0; i<tam; i++)
    {
        if(vec[i].id==id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
