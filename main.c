#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define T 100
#include "biblioteca.h"

int main()
{

    int opcion;
    int opc;

    eEmployee unEmpleado;
    eEmployee listadoEmpleados[T];
    construirArray(listadoEmpleados,T);
    mostrarArray(listadoEmpleados,T);

    do
    {
        printf("1.ALTA\n2.BAJA\n3.MODIFICAR\n4.Informar\n5.Salir\nElija opcion: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
            case 1:
               insertarEmpleado(listadoEmpleados, T);
            break;
            case 2:
                borrarEmpleado(listadoEmpleados,T);
                break;
            case 3:
                editarEmpleado(listadoEmpleados, T);
                break;

            case 4:
                printf("1.Mostrar empleados\n2.Mostrar por apellido\n3.Mostrar por sector\n4.Mostrar sueldos\n5.Salir\nElija opcion: ");
                scanf("%d", &opc);
                switch(opc)
                {
                case 1:
                    crearId(listadoEmpleados, T);
                    mostrarArray(listadoEmpleados,T);
                    break;
                case 2:
                    ordenarPorApellido(listadoEmpleados,T);
                    mostrarArray(listadoEmpleados,T);
                    break;
                case 3:
                    ordenarPorSector(listadoEmpleados,T);
                    mostrarArray(listadoEmpleados,T);
                    break;
                case 4:
                    mostrarSalario(listadoEmpleados,T);
                    break;
                }

                break;
        }
    }while(opcion!=5);

    return 0;
}
