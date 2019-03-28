/*
Se ingresan numeros enteros (hasta que el usuario quiera).
Los numeros deben estar comprendidos entre -500 y 500.
Determinar:
a) Cuantos son pares.
b) Cuantos son positivos.
c) Cuantos son negativos.
d) Cuantas veces se ingreso "0".
e) Promedio de numeros positivos.
f) Numero maximo y numero minimo (en que posicion se ingresaron esos numeros).
g) Suma de negativos.
h) Diferencia entre negativos y positivos.
i) Cuantos numeros estan entre -239 y 5.
*/

#include<stdio.h>
#include<stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {

	int contador;
	int numero;
	char continuar;
	int numeroPar;
	int numeroPositivo;
	int acumuladorPositivo;
	int numeroNegativo;
	int acumuladorNegativo;
	int numerosCero;
	float promedioPositivos;
	int numMax;
	int ubicacionMaximo;
	int numMinimo;
	int ubicacionMinimo;
	int contador2;
	int diferencia;
	
	contador=0;
	continuar ='s';
	numeroPar=0;
	acumuladorPositivo=0;
	acumuladorNegativo;
	numerosCero=0;
	numMax=0;
	ubicacionMaximo=1;
	numMinimo=0;
	ubicacionMinimo=1;
	contador2=0;
	diferencia=0;
	
	while(continuar != 'n')
	{
		printf("Ingrese un numero entero entre -500 y 500: ");	
		scanf("%i",&numero);
	
		while(numero<-500 && numero>501)
		{
			printf("ERROR!!");
			printf("Ingrese un numero entero entre -500 y 500: ");	
			scanf("%i",&numero);
			
		}
		if(numero%2==0)
		{
			numeroPar++;
		}
		if(numero>0)
		{
			numeroPositivo++;
			acumuladorPositivo=numeroPositivo+numero;
		}
			else
			{
				if(numero<0)
				{
					numeroNegativo++;
					acumuladorNegativo=numeroNegativo+numero;
				}
					else
					{
						numerosCero++;
					}
			}
		if(contador==0)
		{
			numMax=numero;
			ubicacionMaximo=contador;
			numMinimo=numero;
			ubicacionMinimo=contador;
		}
		else
		{
			if(numero>numMax)
			{
				numMax=numero;
				ubicacionMaximo=contador;
			}
			if(numero<numMinimo)
			{
				numMinimo=numero;
				ubicacionMinimo=contador;
			}
		if(numero>-239 && numero<6)
			{
				contador2++;
			}
		}
			printf("Desea continuar?: ");
			scanf(" %c",&continuar);
		contador++;
	}
	promedioPositivos=(float)acumuladorPositivo/numeroPositivo;
	diferencia=acumuladorPositivo-acumuladorNegativo;
	
	printf("a) Cuantos son pares: %d", numeroPar);
	printf("\nb) Cuantos son positivos: %d", numeroPositivo);
	printf("\nc) Cuantos son negativos: %d", numeroNegativo);
	printf("\nd) Cuantas veces se ingreso 0: %d", numerosCero);
	printf("\ne) Promedio de numeros positivos: %.3f", promedioPositivos);
	printf("\nf) Numero maximo y posicion: %d - %d. Numero minimo y posicion: %d - %d", numMax,ubicacionMaximo,numMinimo,ubicacionMinimo);
	printf("\ng) Suma de negativos: %d", acumuladorNegativo);
	printf("\nh) Diferencia entre negativos y positivos: %d", diferencia);
	printf("\ni) Cuantos numeros estan entre -239 y 5: %d", contador2);
	
	return 0;
}
