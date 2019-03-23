#include <stdio.h>
#include <stdlib.h>
int pedirNumero(void);
int main()
{
    int elNumeroIngresado;
    elNumeroIngresado=pedirNumero();
    printf("El numero ingresado fue:%d", elNumeroIngresado);


}
int pedirNumero(void)
{
    int miNumero;
    printf("Ingrese numero: ");
    scanf("%d",&miNumero);

    while(miNumero<0 || miNumero>10)
    {
        printf("Reingrese el numero: ");
        scanf("%d", &miNumero);
    }
}
