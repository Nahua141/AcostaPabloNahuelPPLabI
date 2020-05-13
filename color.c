#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "color.h"
int mostrarColores(eColor color[], int tamC)
{
 	int isOk = 0;
	if(color != 0)
	{
		isOk = 1;
		printf("*** Colores ***\n");
		printf("  ID     Descripcion\n\n");

		for(int i = 0; i < tamC; i++)
		{
			printf("%d   %10s \n", color[i].id, color[i].descripcion);
		}
	}
	return isOk;
}
int cargarDescColor(char descripcion[], int idColor, eColor colores[], int tamC)
{
       int isOk = 0;

	for(int i = 0; i < tamC; i++)
	{
		if(colores[i].id == idColor)
		{
			strcpy(descripcion, colores[i].descripcion);
			isOk = 1;
			break;
		}
	}

	return isOk;
}
