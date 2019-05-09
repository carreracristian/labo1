#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "biblioteca.h"


eEmployee pedirEmpleado()
{
    eEmployee retornarEmpleado;

    printf("Ingrese nombre: ");
    fflush(stdin);
    gets(retornarEmpleado.nombre);

    printf("Ingrese apellido: ");
    fflush(stdin);
    gets(retornarEmpleado.apellido);

    printf("Ingrese sector: ");
    fflush(stdin);
    gets(retornarEmpleado.sector);

    printf("Ingrese salario: ");
    scanf("%f", &retornarEmpleado.salario);

    retornarEmpleado.estado = OCUPADO;

    return retornarEmpleado;
}


void mostrarEmpleado(eEmployee unEmpleado)//,eEmployee listado[],int cant)
{
    //ordenarPorApellido();

    printf("%s %10s %10s %10s %10.2f %10d\n\n", unEmpleado.nombre, unEmpleado.apellido, unEmpleado.id, unEmpleado.sector, unEmpleado.salario, unEmpleado.estado);
}


void cargarArray(eEmployee listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        listado[i]= pedirEmpleado();
//        listado[i]=crearId();
    }
}


void mostrarArray(eEmployee listado[], int cant)
{
    printf("Nombre\t\tApellido\tID\tSector\t\tSalario\t\tEstado\n");

    int i;
    for(i=0; i<cant; i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            mostrarEmpleado(listado[i]);
        }


    }
}


void construirArray(eEmployee listado[], int cant)
{
    int i;
    for(i=0; i<cant; i++)
    {
        listado[i].estado= LIBRE;
        listado[i].salario= 0;
        strcpy(listado[i].nombre, "");
        strcpy(listado[i].apellido, "");
        strcpy(listado[i].id, "");
        strcpy(listado[i].sector, "");
    }
}


int insertarEmpleado(eEmployee listado[], int tam)
{
    int indice;
    indice= dameLugarLibre(listado, tam);
    if(indice != -1)
    {
        listado[indice]= pedirEmpleado();
    }
    return indice;
}


int dameLugarLibre(eEmployee listado[], int tam)
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


int borrarEmpleado(eEmployee lista[], int tam)
{


   int i;
   char codigo[50];
   int loEncontro = 0;

   printf("Ingrese el ID del empleado: ");
   fflush(stdin);
   gets(codigo);

   for(i=0; i<tam; i++)
   {
       if(strcmp(lista[i].id, codigo)==0)
       {
          lista[i].estado = LIBRE;
            loEncontro = 1;
           break;
       }

   }

   if(loEncontro==0)
   {
      printf("ID inexistente!!");
   }

    return 0;
}


int editarEmpleado(eEmployee lista[], int tam)
{
   int i;
   char codigo[50];
   int loEncontro = 0;
   int opc;

   printf("Ingrese el ID del empleado: ");
   fflush(stdin);
   gets(codigo);

   for(i=0; i<tam; i++)
   {
       if(strcmp(lista[i].id, codigo)==0)
       {
    do
    {
        printf("1.Modificar nombre.\n2.Modificar apellido\n3.Modificar salario\n4.Modificar sector\n5.Salir.\nElija opcion: ");
        scanf("%d", &opc);

        switch(opc)
        {
            case 1:
               printf("Ingrese el nuevo nombre: ");
           scanf("%s",&lista[i].nombre);
            break;
            case 2:
                printf("Ingrese el nuevo apellido: ");
           scanf("%s",&lista[i].apellido);
                break;
            case 3:
                printf("Ingrese el nuevo salario: ");
           scanf("%f", &lista[i].salario);
                break;

            case 4:
                printf("Ingrese el nuevo sector: ");
           scanf("%s", &lista[i].sector);
                break;
        }
    }while(opc!=5);

            loEncontro = 1;
           break;
       }

   }

   if(loEncontro==0)
   {
      printf("ID inexistente!!");
   }

   return 0;
}
void ordenarPorApellido(eEmployee listado[], int tam)
{
    int i,j;
    eEmployee aux;

    for(i=0;i<tam;i++)
    {
        for(j=0;j<tam-1;j++)
        {
            if(strcmp(listado[i].apellido,listado[j].apellido)==-1)
            {
                aux=listado[i];
                listado[i]=listado[j];
                listado[j]=aux;
            }
        }
    }
}
void ordenarPorSector(eEmployee listado[], int tam)
{
    int i,j;
    eEmployee aux;

    for(i=0;i<tam;i++)
    {
        for(j=0;j<tam-1;j++)
        {
            if(strcmp(listado[i].sector,listado[j].sector)==-1)
            {
                aux=listado[i];
                listado[i]=listado[j];
                listado[j]=aux;
            }
        }
    }
}
void mostrarSalario(eEmployee listado[], int tam)
{
    int i;
    float sumaSalario=0;
    float promedio=0;
    int contadorDeSalarios=0;
    int salariosMayores=0;

    for(i=0;i<tam;i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            sumaSalario=sumaSalario+listado[i].salario;
            contadorDeSalarios++;
        }
    }
    promedio=(sumaSalario)/(contadorDeSalarios);

    for(i=0;i<tam;i++)
    {
        if(listado[i].estado==OCUPADO && listado[i].salario>promedio)
        {
            salariosMayores++;
        }
    }
    printf("\nLa suma de los salarios es: %.2f",sumaSalario);
    printf("\nEl salario promedio es: %.2f",promedio);
    printf("\nLos empleados con sueldo mayor al promedio son: %d\n\n",salariosMayores);

}
int crearId(eEmployee listado[], int tam)
{
    int i;
    int retornarId;

    retornarId=0;

    for(i=0;i<tam;i++)
    {
        if(listado[i].estado==OCUPADO)
        {
            if(listado[i].id>retornarId)
            {
                retornarId=listado[i].id;
            }
        }
    }
    return (retornarId+1);
}
