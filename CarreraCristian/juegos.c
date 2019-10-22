#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ImputAndValidate.h"
#include "categoria.h"
#include "juegos.h"


void harcodearJuego(eJuego vec[], int tam)
{
    int i;
    eJuego lista[]=
    {
        {100,"Monopoly",500,1},
        {101,"Jenga",300,3},
        {102,"Dados",200,2},
        {103,"Uno",250,1},
        {104,"Truco",250,3},

    };

    for( i=0; i<tam; i++)
    {
        vec[i]=lista[i];
    }
}

void mostrarJuego(eJuego juego, eCategoria cat[], int tam)
{
   char nombre[21];

   obtenerNomCat(cat, tam, juego.idCategoria,nombre);

   printf("%d    %10s    %.2f    %10s\n",juego.codigo,juego.descripcion,
          juego.importe,nombre);
}

void mostrarJuegos(eJuego juego[],int tamJ, eCategoria cat[], int tamC){

    int i;
    system("cls");
    printf(" ID    DESCRIPCION     IMPORTE     CATEGORIA\n\n");

    for( i=0 ;i<tamJ; i++)
    {
        mostrarJuego(juego[i],cat,tamC);
    }
}

void obtenerNomJuego(eJuego vec[], int tam, int id, char dondeAsignar[])
{
    int i;
    for( i=0; i<tam; i++)
    {
        if(vec[i].codigo == id)
        {
            strcpy(dondeAsignar,vec[i].descripcion);
        }
    }
}
int buscarJuegoId(eJuego vec[], int tam, int id)
{
    int indice=-1;
    int i;

    for( i=0; i<tam; i++)
    {
        if(vec[i].codigo==id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}
