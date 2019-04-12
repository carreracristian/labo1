#include <stdio.h>
#include <stdlib.h>
#define TAM 5

void mostrarAlumnos(char[][50],char [][50],int [],int [],int);
void ordenarAlumnos(char[][50],char [][50],int [],int [],int);
int main()
{
    char nombre[TAM][50]={"Juan","Robert","Pedro","Diedo","Mario"};
    char apellido[TAM][50]={"Perez","Rojas","Picapiedras","Maradona","Balotelli"};
    int edad[TAM]={21,23,45,37,95};
    int nota[TAM]={2,3,5,7,9};


   mostrarAlumnos(nombre,apellido,edad,nota, TAM);
    return 0;
}
void ordenarAlumnos(char nombre[][50],char apellido[][50],int edad[],int nota[],int tam)
{
    char auxCadena[50];
    int auxEntero;
    int i;
    int j;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(nombre[i],nombre[j])>0)
            {
                strcpy(auxCadena,nombre[i]);
                strcpy(nombre[i],nombre[j]);
                strcpy(nombre[j],auxCadena);

                strcpy(auxCadena,apellido[i]);
                strcpy(apellido[i],apellido[j]);
                strcpy(apellido[j],auxCadena);

                //auxEntero=
            }
        }
    }
}
void mostrarAlumnos(char nombre[][50],char apellido[][50],int edad[],int nota[],int tam)
{
    int i;

     printf("Nombre-\tApellido-\tEdad-\tNota\n");
   for(i=0;i<TAM;i++)
   {
       printf("%s\t%s\t%d\t%d\n",nombre[i],apellido[i],edad[i],nota[i]);
   }
}
