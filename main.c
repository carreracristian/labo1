#include <stdio.h>
#include <stdlib.h>
/*1 funcion crgar enteros
  2 mostrar
  3 ordenar
  4 calcular max
  5devolverPromedio*/
void mostrarArray(int*,int);
int main()
{

    int variable[5]={5,4,3,2,1};
   // int *puntero;
    int i;

    //puntero=&variable;
    mostrarArray(variable,5);
    //puntero=&variable[0];

    /*printf("%d\n",puntero);//variable
    printf("%d\n",puntero+0);//&variable[0]
    printf("%d\n",puntero+1);//&variable[1]
    printf("%d\n\n",puntero+2);//&variable[2]

   // printf("%d\n",variable);//variable
    printf("%d\n",*(puntero+0));//&variable[0]
    printf("%d\n",*(puntero+1));//&variable[1]
    printf("%d\n",*(puntero+2));//&variable[2]*/

    /*int valor=99;
    int* p;
    int* q;

    p=&valor;
    q=p;


    printf("%d", *q);*/

    return 0;
}
void mostrarArray(int* pArray,int tam)
{
    int i;
     for(i=0;i<5;i++)
    {
        printf("%d\n",*(pArray+i));//variable de i
    }

}
