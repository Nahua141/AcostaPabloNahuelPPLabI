#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tipo.h"
int cargarDescripTipo(char descripcion[], int idTipo, eTipo tipos[], int tamT)
{
	int isOk = 0;

	for(int i = 0; i < tamT; i++)
	{
		if(tipos[i].id == idTipo)
		{
			strcpy(descripcion, tipos[i].descripcion);
			isOk = 1;
			break;
		}
	}

	return isOk;
}
int mostrarTipos(eTipo tipos[], int tamT)
{
	int isOk = 0;
	if(tipos != 0)
	{
		isOk = 1;
		printf("*** Tipos ***\n");
		printf("  ID     Descripcion\n\n");

		for(int i = 0; i < tamT; i++)
		{
			printf("%d   %10s \n", tipos[i].id, tipos[i].descripcion);
		}
	}
	return isOk;
}
