#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "tipo.h"
#include "color.h"
#include "servicios.h"


#define LAN 5
#define LTIP 5


int menu();
int main()
{
    char seguir= 's';
    char confirma;
    int proximoId=1000;
    eMascota listaMascotas[LAN];

    eTipo tipos[LTIP];

    do
    {
        switch(menu())
        {
        case 1:
           if(altaMascota(proximoId, listaMascotas, LAN))
            {
                proximoId++;
            }
            break;
        case 2:
            modificarMascota(listaMascotas,LAN, tipos, LTIP);
            break;
        case 3:
            printf("3-Baja mascota");
            break;
        case 4:
            printf("4-Listar mascota");
            break;
        case 5:
            printf("5-Listar tipos");
            break;
        case 6:
            printf("6-Listar colores");
            break;
        case 7:
            printf("7-Listar servicios");
            break;
        case 8:
            printf("8-Alta trabajo");
            break;
        case 9:
            printf("9-Listar trabajos");
            break;
        case 10:
            printf("10-Confirma salida?: ");
            fflush(stdin);
            scanf("%c", &confirma);
            if(confirma== 's')
            {
                seguir='n';
            }
            break;
        }
        system("pause");
    }
    while(seguir=='s');

    return 0;
}
int menu()
{
    int opcion;
    system("cls");
    printf("*****Gestion de veterinaria*****\n\n");
    printf("1-Alta mascota\n");
    printf("2-Modificar mascota\n");
    printf("3-Baja empleado\n");
    printf("4-Listar mascota\n");
    printf("5-Listar tipo\n");
    printf("6-Listar color\n");
    printf("7-Listar servicios\n");
    printf("8-Alta trabajo\n");
    printf("9-Listar trabajos\n");
    printf("10-Salir\n");
    printf("Ingrese opcion: ");
    fflush(stdin);
    scanf("%d", &opcion);

    return opcion;
}
