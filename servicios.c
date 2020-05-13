#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "servicios.h"
int mostrarServicios(eServicios servicio[], int tamS)
{
    int isOk = 0;
	if(servicio != 0)
	{
		isOk = 1;
		printf("*** Servicios ***\n");
		printf("  ID     Descripcion\n\n");

		for(int i = 0; i < tamS; i++)
		{
			printf("%d   %10s \n", servicio[i].id, servicio[i].descripcion);
		}
	}
	return isOk;
}
int cargarDescServicios(char descripcion[], int idServicios, eServicios servicios[], int tamS)
{
    int isOk = 0;

	for(int i = 0; i < tamS; i++)
	{
		if(servicios[i].id == idServicios)
		{
			strcpy(descripcion, servicios[i].descripcion);
			isOk = 1;
			break;
		}
	}

	return isOk;
}
