#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void mostrarVector(int datos[10],int tamanio);
void mostrarPalabra(char datos[][10],int tamanio);
void cargarVector(int datos[],int tamanio);
void ordenarVector(int datos[],int tamanio);
int main()
{
    char usuario[][10]={"pedro","juan","maria","diego","cristian"};
    int nota[10]={8,5,2,10,3};
    int i;
    int j;

    mostrarVector(nota,5);
    mostrarPalabra(usuario,5);
    cargarVector(nota,5);
    ordenarVector(nota,5);
    /*for(i=0;i<5;i++)
    {
         printf("\nalumno: %s nota: %d \n",usuario[i],nota[i]);
    }
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
             if(strcmp(usuario[i],usuario[j])==1)
            {
                int aux=nota[i];
                nota[i]=nota[j];
                nota[j]=aux;

                char auxString[10];
                strcpy(auxString,usuario[i]);
                strcpy(usuario[i],usuario[j]);
                strcpy(usuario[j],auxString);

            }*/
           // printf("%d => %d\n",nota[i],nota[j]);
            //mal if(usuario[i]<usuario[j])
            /*int resultado;
            resultado=strcmp("\nHola","Hola");
            printf("\n Iguales :%d",resultado);
            resultado=strcmp("\nHola","Hola");
            printf("\n Primera :%d",resultado);
            resultado=strcmp("\nHola","Hola");
            printf("\n Segunda :%d",resultado);
            resultado=strcmp("\nA","a");
            printf("\n la A: %d",resultado);
            resultado=strcmp("\na","b");
            printf("\n la a-b: %d",resultado);
            resultado=strcmp("\nb","a");
            printf("\n la b-a: %d",resultado);


            resultado=strcmp(usuario[i],usuario[j]);



        }
    }*/
    //ordenamiento en forma ascendente o descendente
    /*ordenamiento por nota
    for(i=0;i<5;i++)
    {
        for(j=0;j<4;j++)
        {
            printf("%d => %d\n",nota[i],nota[j]);
            if(nota[i]<nota[j])
            {
                int aux=nota[i];
                nota[i]=nota[j];
                nota[j]=aux;

                char auxString[10];
                strcpy(auxString,usuario[i]);
                strcpy(usuario[i],usuario[j]);
                strcpy(usuario[j],auxString);

            }
        }
    }*/
    /*for(i=0;i<5;i++)
    {
         printf("\nIngrese usuario #%d: ",i+1);
         gets(usuario[i]);
        // printf("\nIngrese nota #%d: ",i+1);
        // scanf("%d",&nota[i]);
    }
    for(i=0;i<5;i++)
    {
        printf("\nAlumno: %s.",usuario[i]);
    }*/
   /* inicializacion de arrays en paralelo
    for(i=0;i<5;i++)
    {
         strcpy(usuario[i],"");
        // nota[i]=0;
        //usuario[i][0]=" ";
    }

    for(i=0;i<5;i++)
    {
         printf("Ingrese usuario # %d:",i+1);
         scanf("%s",usuario[i]);
         //gets(usuario[i]);
         printf("\nIngrese nota # %d:",i+1);
         scanf("%d",&nota[i]);
    }*/
   // strcpy(usuario[0],"hola");
   // printf("test %s \n",usuario[0]);
    //printf("test %s \n",usuario[1]);



    /*printf("Ingrese usuario: ");
    scanf("%s",usuario[0]);
    printf("Ingrese usuario: ");
    scanf("%s",usuario[1]);
    int tamanio=strlen(usuario[8]);
    printf("Tamaño: %d \n",tamanio);

    printf("Hello %s\n",usuario[0]);
    printf("Hello %s\n",usuario[1]);
    printf("Hello %s\n",usuario[2]);
    return 0;*/
}
void mostrarVector(int datos[10],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        printf("Nota :%d \n",datos[i]);
    }
}
void mostrarPalabra(char datos[][10],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        printf("Usuario :%s \n",datos[i]);
    }
}
void cargarVector(int datos[],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        datos[i]=-1;
    }
}
void ordenarvector(int datos[],int tamanio)
{
    int i;
    for(i=0;i<tamanio;i++)
    {
        printf("Usuario :%s \n",datos[i]);
    }
}
