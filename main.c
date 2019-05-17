#include <stdio.h>
#include <stdlib.h>

/** \brief Permite cargar un caracter
 *\param char* El char a cargar
 *\return int [0]-> Si no se pudo cargar el cacarter
              [1]-> Si se pudo cargar el cacarter
 *
 */
//Pedir al usuario ingresar un caracter ynguardarlo con puntero.
int getCaracter(char*);
void mostrarLetra(char*);

int main()
{

    char datoChar;

    int estado;
    estado=getCaracter(&datoChar);

    if(estado==1)
    {
        printf("Caracter cargado con exito\n");
        mostrarLetra(&datoChar);
    }
    else
    {
        printf("El caracter no fue guardado\n");
    }

   /* printf("Ingrese un caracter: ");
    fflush(stdin);
    scanf("%c",&datoChar);*/
   // mostrarLetra(NULL);
    printf("El caracter es: %c",datoChar);
    return 0;
}
int getCaracter(char* punteroChar)
{
    int cargo=0;
    if(punteroChar!=NULL)
    {
        printf("Ingrese un caracter: ");
        fflush(stdin);
        scanf("%c",punteroChar);

        cargo=1;
    }
    return cargo;
}
void mostrarLetra(char* punteroChar)
{
    if(punteroChar!=NULL)
    {
        printf("%c",*punteroChar);
    }

}
