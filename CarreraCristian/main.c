#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ImputAndValidate.h"
#include "categoria.h"
#include "juegos.h"
#include "cliente.h"
#include "alquileres.h"
#include "informs.h"

#define TAMC 10
#define TAMJ 10
#define TAMCAT 10
#define TAMA 10
#define TAML 10

int menuOpciones();

int main()
{
    int salir;
    int atrasInf;
    int idCliente=1000;
    int idAlquier=10000;
    eLocalidad localidad[TAML];
    eJuego juegos[TAMJ];
    eCategoria cat[TAMCAT];
    eCliente clientes[TAMC];
    eAlquiler alquiler[TAMA];

    inicializarClientes(clientes,TAMC);
    inicializarAlquiler(alquiler,TAMA);

    harcodearCategoria(cat,TAMCAT);
    harcodearJuego(juegos,TAMJ);
    idCliente=idCliente+harcodearClientes(clientes,TAMC,6);
    idAlquier=idAlquier+harcodearAlquileres(alquiler,TAMA,6);


    do
    {
        switch(menuOpciones())
        {
        case 1:
            if(altaCliente(clientes,TAMC,idCliente,localidad,TAML))
            {
                idCliente++;
            }
            break;

        case 2:
            modificarCliente(clientes,TAMC,localidad,TAML);
            break;

        case 3:
            bajaCliente(clientes,TAMC,localidad,TAML);
            break;

        case 4:
            ordenarCliente(clientes,TAMC);
            mostrarClientes(clientes,TAMC,localidad,TAML);
            break;

        case 5:
            if(altaAlquiler(alquiler,TAMA,juegos,TAMJ,clientes,TAMC,cat,TAMCAT,localidad,TAML, idAlquier))
            {
                idAlquier++;
            }
            break;

        case 6:
            mostrarAlquileres(alquiler,TAMA,juegos,TAMJ,clientes,TAMC);
            break;

        case 7:
            do
            {
                switch(menuInformes())
                {
                case 1 :
                    mostrarJuegosMesa(juegos,TAMJ,cat,TAMCAT);
                    break;

                case 2 :
                    mostrarAlquilerPorCliente(clientes,TAMC,alquiler,TAMA,cat,TAMCAT,juegos,TAMJ,localidad,TAML);
                    break;

                case 3 :
                    mostrarImporteCliente(clientes,TAMC,alquiler,TAMA,cat,TAMCAT,juegos,TAMJ,localidad,TAML);
                    break;

                case 4 :
                    clientesSinAlquilar(clientes,TAMC,alquiler,TAMA,localidad,TAML);
                    break;

                case 5 :
                    juegosSinAlquilar(clientes,TAMC,alquiler,TAMA,cat,TAMCAT,juegos,TAMJ);
                    break;

                case 6 :
                    mostrarImporteJuego(clientes,TAMC,alquiler,TAMA,cat,TAMCAT,juegos,TAMJ);
                    break;

                case 7 :

                    mostrarImporteCategoria(clientes,TAMC,alquiler,TAMA,cat,TAMCAT,juegos,TAMJ);
                    break;

                case 8 :
                    cantidadDeAlquileresPorJuegos(alquiler,TAMA,cat,TAMCAT,juegos,TAMJ);
                    break;

                case 9 :
                    atrasInf=confimarSalir("\nVolver atras? s/n: ");
                    break;

                }
                printf("\n\n");
                system("pause");

            }while(atrasInf !=1);
        break;

        case 8:
            mostrarLocalidades(localidad,TAML);
            //mostrarJuegos(juegos,TAMJ,cat,TAMCAT);
            break;
        case 9:
            salir=confimarSalir("\nDesea salir? s/n: ");
            break;

        default:
            printf("Ingrese opcion correcta\n");
        }

        printf("\n\n");
        system("pause");

    }
    while(salir != 1);

    return 0;
}

int menuOpciones()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE OPCIONES ***   \n\n");
    printf("1. Alta cliente\n");
    printf("2. Modificar cliente\n");
    printf("3. Baja cliente\n");
    printf("4. Listar clientes\n");
    printf("5. Alta alquileres\n");
    printf("6. Listar alquileres\n");
    printf("7. Informes\n");
    printf("8. Mostrar localidades\n");
    printf("9. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}
