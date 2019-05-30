#include <stdio.h>
#include <stdlib.h>
#include "clase19.h"
#define ARCHIVO".\\Alumnos.csv"
int main()
{

    eAlumno unAlumno;

    FILE *pArchivo;

    if((pArchivo = fopen(ARCHIVO,"w"))==NULL)
    {
        printf("El archivo no puede ser abierto");
        exit(1);
    }
    else
    {
        printf("Archivo abierto");
    }
    unAlumno.legajo=1;
    unAlumno.nota=4;
    strcpy(unAlumno.nombre,"lalala");
    fflush(stdin);
    //fwrite(unAlumno,sizeof(unAlumno),1,pArchivo);
    char texto[]="lalala;555;10";
    int largo=strlen(texto);
    fwrite(texto,sizeof(char),largo,pArchivo);
    fclose(pArchivo);

    if((pArchivo = fopen(ARCHIVO,"r"))==NULL)
    {
        printf("El archivo no puede ser abierto\n");
        exit(1);
    }
    else
    {
        char renglon[70];
        while(!feof(pArchivo))
        {
            int cantidad = fread(renglon,sizeof(char),70,pArchivo);

            printf("\nCantidad %d y texto %s",cantidad,texto);
        }
        //printf("\nArchivo abierto");
    }

    //printf("%p",pArchivo);
    return 0;
}
