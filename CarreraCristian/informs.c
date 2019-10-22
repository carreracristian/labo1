#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ImputAndValidate.h"
#include "categoria.h"
#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"
#include "informs.h"

int menuInformes()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE INFORMES ***   \n\n");
    printf("1. Mostrar juegos de categoria mesa\n");
    printf("2. Mostrar alquileres efectuados por algun cliente\n");
    printf("3. Mostrar total de todos los importes pagados por el cliente seleccionado\n");
    printf("4. Listar clientes que no alquilaron juegos\n");
    printf("5. Listar juegos que no han sido alquilados\n");
    printf("6. Mostrar total de importes pagados por juego\n");
    printf("7. Mostrar total de importes pagados por categoria\n");
    printf("8. Mostrar total de alquileres por juego\n");
    printf("9. Atras\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void mostrarAlquilerPorCliente(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,
                               eCategoria cat[],int tamC, eJuego juegos[],int tamJ,eLocalidad loc[],int tamaL)
{

    int idCliente;
    int esta;
    int flag=0;
    int i;

    mostrarClientes(cliente,tamC,loc,tamAl);
    getIntRange(&idCliente,1000,9999,"Ingrese id de cliente: ");

    esta=buscarClienteId(cliente,tamC,idCliente);

    while(esta==-1)
    {
        getIntRange(&idCliente,1000,9999,"Ingrese id de cliente valido: ");

        esta=buscarClienteId(cliente,tamC,idCliente);

    }
    if(esta != -1)
    {
        system("cls");

        printf("  ID         JUEGO               CLIENTE               FECHA_ALQUILER\n\n");

        for( i=0; i<tamAl; i++)
        {
            if(alq[i].idCliente == idCliente && alq[i].isEmpty == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);
                flag=1;
            }
        }
        if(flag==0)
        {
            printf("\n\nEl cliente no tiene un alquiler.");
        }

    }

}


void mostrarImporteCliente(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,
                           eCategoria cat[],int tamC, eJuego juegos[],int tamJ,eLocalidad loc[],int tamaL)
{

    int idCliente;
    int esta;
    float total=0;
    int i;
    int j;

    mostrarClientes(cliente,tamC,loc,tamaL);
    getIntRange(&idCliente,1000,9999,"Ingrese id de cliente: ");

    esta=buscarClienteId(cliente,tamC,idCliente);

    while(esta==-1)
    {
        getIntRange(&idCliente,1000,9999,"Ingrese id de cliente valido: ");

        esta=buscarClienteId(cliente,tamC,idCliente);

    }
    if(esta != -1)
    {
        system("cls");


        mostrarJuegos(juegos,tamJ,cat,tamC);
        printf("\n\n");

        for( i=0; i<tamAl; i++)
        {
            if(alq[i].idCliente == idCliente && alq[i].isEmpty == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);

                for( j=0; j<tamJ; j++)
                {
                    if(juegos[j].codigo == alq[i].idJuego)
                    {
                        total+=(float)juegos[j].importe;
                    }
                }
            }
        }

        printf("\n\nImporte total del cliente %.2f",total);
    }

}

void mostrarJuegosMesa(eJuego juego[], int tamJ,eCategoria cat[], int tamC)
{
    char cate[21];
     int i;
     int j;

    system("cls");
    printf(" ID    DESCRIPCION     IMPORTE     CATEGORIA\n\n");

    for( i=0; i<tamJ; i++)
    {
        for( j=0; j<tamC; j++)
        {
            if(juego[i].idCategoria == cat[j].id)
            {
                obtenerNomCat(cat,tamC,juego[i].idCategoria,cate);

                if(strcmpi(cate,"mesa")==0)
                {

                    mostrarJuego(juego[i],cat,tamC);
                }
            }
        }
    }

}
int mostrarAlquileresClientes(int idCliente,eAlquiler alq[],int tamAl)
{
    int alquiler=0;
     int i;

    for( i=0; i<tamAl; i++)
    {
        if(alq[i].isEmpty==0 && alq[i].idCliente == idCliente)
        {
            alquiler=1;
        }
    }

    return alquiler;
}
void clientesSinAlquilar(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,eLocalidad loc[],int tamaL)
{
     int flag=0;
      int i;

    system("cls");
    printf("Clientes sin alquileres:\n\n");

    for( i=0; i<tam; i++)
    {
        if(mostrarAlquileresClientes(cliente[i].id,alq,tamAl)==0)
        {
            mostrarCliente(cliente[i],loc,tamaL);
            flag++;
        }

    }

    if(flag==0)
    {
        printf("\nNo hay clientes sin alquileres");
    }

}
int mostrarJuegosAlquilados(int idJuego,eAlquiler alq[],int tam)
{
    int alquiler=0;
    int i;

    for( i=0; i<tam; i++)
    {
        if(alq[i].isEmpty==0 && alq[i].idJuego == idJuego)
        {
            alquiler=1;
        }
    }

    return alquiler;
}
void juegosSinAlquilar(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,
                           eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{
    int cont=0;
    int i;

    system("cls");
    printf("Juegos sin alquilar:\n\n");

    for( i=0; i<tamJ; i++)
    {
        if(mostrarJuegosAlquilados(juegos[i].codigo,alq,tamAl)==0)
        {
            mostrarJuego(juegos[i],cat,tamC);
            cont++;
        }

    }

    if(cont == 0)
    {
        printf("\nNo hay juegos sin alquilar");
    }
}
void mostrarImporteJuego(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,
                           eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{

    int idJuego;
    int esta;
    float total=0;
    int i;
    int j;

    mostrarJuegos(juegos,tamJ,cat,tamC);

    getIntRange(&idJuego,100,999,"Ingrese id del juego: ");

    esta=buscarJuegoId(juegos,tamJ,idJuego);

    while(esta==-1)
    {
        getIntRange(&idJuego,100,999,"Ingrese id de juego valido: ");

        esta=buscarJuegoId(juegos,tamJ,idJuego);

    }
    if(esta != -1)
    {
        system("cls");


        mostrarJuegos(juegos,tamJ,cat,tamC);
        printf("\n\n");

        for( i=0; i<tamAl; i++)
        {
            if(alq[i].idJuego == idJuego && alq[i].isEmpty == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);

                for( j=0; j<tamJ; j++)
                {
                    if(juegos[j].codigo == alq[i].idJuego)
                    {
                        total+=(float)juegos[j].importe;
                    }
                }
            }
        }

        printf("\n\nImporte total del juego %.2f",total);
    }

}
void mostrarImporteCategoria(eCliente cliente[],int tam, eAlquiler alq[],int tamAl,
                           eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{

    int idCategoria;
    int esta;
    float total=0;
    int i;
    int j;

    //mostrarClientes(cliente,tamC);
    mostrarCategorias(cat,tamC);
    getIntRange(&idCategoria,1,5,"Ingrese id de categoria: ");

    esta=buscarCategoriaId(cat,tamC,idCategoria);

    while(esta==-1)
    {
        getIntRange(&idCategoria,0,6,"Ingrese id de categoria valido: ");

        esta=buscarCategoriaId(cat,tamC,idCategoria);

    }
    if(esta != -1)
    {
        system("cls");


        mostrarJuegos(juegos,tamJ,cat,tamC);
        printf("\n\n");

        for( i=0; i<tamJ; i++)
        {
            if(juegos[i].idCategoria == idCategoria)
            //if(alq[i]. == idCliente && alq[i].isEmpty == 0)
            {
                mostrarAlquiler(alq[i],juegos,tamJ,cliente,tamC);

                for( j=0; j<tamJ; j++)
                {
                    if(juegos[j].codigo == alq[i].idJuego)
                    {
                        total+=(float)juegos[j].importe;
                    }
                }
            }
        }

        printf("\n\nImporte total de la categoria %.2f",total);
    }

}
void cantidadDeAlquileresPorJuegos(eAlquiler alq[],int tamAl,eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{
    int cantidad = 0;
    int idJuego;
    int esta;
    float total=0;
    int i;

    mostrarJuegos(juegos,tamJ,cat,tamC);

    getIntRange(&idJuego,100,999,"Ingrese id del juego: ");

    esta=buscarJuegoId(juegos,tamJ,idJuego);

    while(esta==-1)
    {
        getIntRange(&idJuego,100,999,"Ingrese id de juego valido: ");

        esta=buscarJuegoId(juegos,tamJ,idJuego);

    }
    if(esta != -1)
    {
        system("cls");


        mostrarJuegos(juegos,tamJ,cat,tamC);
        printf("\n\n");

        for( i=0; i<tamAl; i++)
        {
            if(alq[i].idJuego == idJuego && alq[i].isEmpty == 0)
            {
                cantidad++;
            }
        }

        printf("\n\Alquileres totales del juego %d",cantidad);
    }
}
/*void mostrarAlquileresDeTodosJuegos( eCliente cliente[],int tam, eAlquiler alq[],int tamAl,
                           eCategoria cat[],int tamC, eJuego juegos[],int tamJ)
{
    for(int i=0; i < tamAl; i++)
    {
        for(int j=0; j < tamJ; j++)

        if( alq[i].idJuego == juegos[j].codigo && alq[i].isEmpty == 0)
        {
            mostrarAlquileres(alq,tamAl,juegos,tamJ,cliente,tamC);
        }
    }
    printf("\n\n");
}*/
