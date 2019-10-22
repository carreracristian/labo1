#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ImputAndValidate.h"
#include "cliente.h"

void harcodearLocalidad(eLocalidad loc[], int tamaL)
{
    int i;
    eLocalidad lista[]=
    {
        {100,"Zarate"},
        {101,"Quilmes"},
        {102,"CABA"},
        {103,"Olivos"},
        {104,"Avellaneda"},

    };


    for( i=0; i<tamaL; i++)
    {
        loc[i]=lista[i];
    }
}
void mostrarLocalidad(eLocalidad loc)
{
   printf("%d    %10s \n",loc.id,loc.nombre);
}

void mostrarLocalidades(eLocalidad loc[],int tamaL){

    int i;
    system("cls");
    printf(" ID    DESCRIPCION \n\n");

    for( i=0 ;i<tamaL; i++)
    {
        mostrarLocalidad(loc[i]);
    }
}
void obtenerNomLocalidad(int id,eLocalidad vec[], int tam,  char desc[])
{
    int i;
    for( i=0; i<tam; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(desc,vec[i].nombre);
        }
    }
}
int harcodearClientes(eCliente vec[], int tam, int cant)
{
    int cont=0;
    int i;
    eCliente clientes[]=
    {
        {1000,"juan","perez",'m',"15111","ayacucho 2214",100,0},
        {1001,"lucia","gomez",'f',"15222","villate 234",101,0},
        {1002,"pedro","correa",'m',"15333","snta fe 4899",102,0},
        {1003,"ana","solis",'f',"15444","feliu 454",103,0},
        {1004,"luciana","rodriguez",'f',"15555","jb justo 1234",102,0},
        {1005,"roberto","sanchez",'m',"15666","asuncion 467",101,0}

    };

   if(cant<= tam && cant<=10)
   {
       for( i=0; i<tam; i++)
        {
        vec[i]=clientes[i];
        cont++;
        }
   }

    return cont;
}
void inicializarClientes(eCliente vec[], int tam)
{
    int i;
    for( i=0; i<tam; i++)
    {
        vec[i].isEmpty=1;
    }
}

int buscarLibreCliente(eCliente vec[],int tam)
{
    int indice=-1;
    int i;

    for( i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==1)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void mostrarCliente(eCliente vec, eLocalidad localidad[],int tamaL)
{
    char nomLocalidad[50];

    obtenerNomLocalidad(vec.idLocalidad,localidad,tamaL,nomLocalidad);
    printf(" %2d  %10s  %10s         %c    %10s      %10s   %10s\n",vec.id,vec.nombre,vec.apellido,
           vec.sexo,vec.telefono,vec.domicilio,nomLocalidad);
}

void mostrarClientes(eCliente vec[], int tam,eLocalidad loc[],int tamaL)
{
    int cont=0;
    int i;

    system("cls");
    printf(" ID    NOMBRE       APELLIDO      SEXO      TELEFONO     DOMICILIO    LOCALIDAD\n\n");

    for( i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0)
        {
            mostrarCliente(vec[i],loc,tamaL);
            cont++;
        }
    }

    if(cont==0)
    {
        printf("\nNo hay clientes en el sistema\n\n");
    }
}

int altaCliente(eCliente vec[], int tam,int id,eLocalidad loc[],int tamaL)
{
    int todoOk=0;
    int indice;

    system("cls");
    printf("  *** MENU ALTA CLIENTE ***  \n\n");

    indice=buscarLibreCliente(vec,tam);

    if(indice==-1)
    {
        printf("\nNo hay espacio disponible\n\n");
    }
    else
    {
        vec[indice].id=id;
        getStringAlpha(51,"Ingrese nombre: ",vec[indice].nombre);
        getStringAlpha(51,"Ingrese apellido: ",vec[indice].apellido);
        getSexo(&vec[indice].sexo,"Ingrese sexo f/m: ");
        pedirTelefono(vec[indice].telefono,21,"Ingrese telefono: ");
        getStringAlphaNum(51, "Ingrese domicilio con numero: ",vec[indice].domicilio);
        mostrarLocalidades(loc,tamaL);
        getIntRange(vec[indice].idLocalidad,100,999,"Ingrese id de la localidad: ");
        vec[indice].isEmpty=0;
        todoOk=1;
        printf("\nAlta realizada con exito\n\n");
    }

    return todoOk;
}

int buscarClienteId(eCliente vec[], int tam, int id)
{
    int indice=-1;
     int i;

    for( i=0; i<tam; i++)
    {
        if(vec[i].isEmpty==0 && vec[i].id==id)
        {
            indice=i;
            break;
        }
    }

    return indice;
}

void bajaCliente(eCliente vec[], int tam, eLocalidad loc[],int tamaL)
{
    int confirma;
    int indice;
    int id;

    mostrarClientes(vec,tam,loc,tamaL);

    getIntRange(&id,1000,9999,"Ingrese id del cliente: ");

    indice=buscarClienteId(vec,tam,id);

    while(indice==-1)
    {
        getIntRange(&id,1000,9999,"Ingrese id de cliente valido: ");

        indice=buscarClienteId(vec,tam,id);
    }
    if(indice !=-1)
    {
        confirma=confimarSalir("\n\nDar de baja cliente? s/n: ");

        if(confirma==1)
        {
            vec[indice].isEmpty=1;
            printf("\nOperacion realizada\n\n");
        }
        else
        {
            printf("\nOperacion cancelada\n\n");
        }
    }

}

void ordenarCliente(eCliente vec[], int tam)
{
    eCliente aux;
     int i;
     int j;

    for( i=0; i<tam-1; i++)
    {
        for( j=i+1; j<tam; j++)
        {
            if(strcmpi(vec[i].apellido,vec[j].apellido)>0)
            {
                aux=vec[i];
                vec[i]=vec[j];
                vec[j]=aux;
            }
            else
            {
                if(strcmpi(vec[i].apellido,vec[j].apellido)==0 && strcmpi(vec[i].nombre,vec[j].nombre)>0)
                {
                    aux=vec[i];
                    vec[i]=vec[j];
                    vec[j]=aux;
                }
            }
        }
    }
}

int menuModificacion()
{
    int opcion;

    system("cls");
    printf("  ***  MENU DE MODIFICACION ***   \n\n");
    printf("1. Nombre\n");
    printf("2. Domicilio\n");
    printf("3. Telefono\n");
    printf("4. Salir\n\n");
    printf("Ingrese opcion: ");
    scanf("%d",&opcion);

    return opcion;
}

void modificarCliente(eCliente vec[], int tam,eLocalidad loc[],int tamaL)
{
    int indice;
    int atras;
    int id;

    mostrarClientes(vec,tam,loc,tamaL);

    getIntRange(&id,1000,9999,"Ingrese id del cliente: ");

    indice=buscarClienteId(vec,tam,id);

    while(indice==-1)
    {
        getIntRange(&id,1000,9999,"Ingrese id de cliente valido: ");

        indice=buscarClienteId(vec,tam,id);
    }
    if(indice !=-1)
    {
        do
        {
            switch(menuModificacion())
            {
            case 1:
                getStringAlpha(51,"Ingrese nombre: ",vec[indice].nombre);
                break;

            case 2:
                getStringAlphaNum(51, "Ingrese domicilio con numero: ",vec[indice].domicilio);
                break;

            case 3:
                pedirTelefono(vec[indice].telefono,21,"Ingrese telefono: ");
                break;

            case 4:
                atras=confimarSalir("Volver al menu de opciones? s/n: ");
                break;
            }

        }
        while(atras != 1);
    }
}

void obtenerNomCliente(eCliente vec[], int tam, int id, char dondeAsigar[])
{
    int i;
    for( i=0; i<tam; i++)
    {
        if(vec[i].id == id)
        {
            strcpy(dondeAsigar,vec[i].apellido);
            strcat(dondeAsigar,", ");
            strcat(dondeAsigar,vec[i].nombre);
        }
    }
}
