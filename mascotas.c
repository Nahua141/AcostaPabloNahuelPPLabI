#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mascotas.h"
#include "tipo.h"
#include "dataWarehouse"

int buscarLibre(eMascota listarMascota[], int tamM)
{
    if(listarMascota!= 0)
    {
        for(int i=0; i<tamM; i++)
        {
            listarMascota[i].isEmptyMascota=1;
        }
        return 0;

    }
    else
    {
        return -1;
    }
}
int altaMascota(int idx, eMascota listarMascota[], int tamM, eTipo tipos[], int tamT)
{
    int todoOk = 0;
    int indice = buscarLibre(listarMascota, tamM);
    eMascota auxMascota;
    system("cls");

    printf("*****Estamos en alta de mascota*****\n\n");

    if(indice == -1)
    {
        printf("Sistema completo\n\n");
    }
    else
    {
        auxMascota.id=idx;

        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(auxMascota.nombre);

        printf("Ingrese tipo: ");
        fflush(stdin);
        gets(auxMascota.tipo);

        printf("Ingrese raza: ");
        fflush(stdin);
        gets(auxMascota.raza);

        printf("Ingrese edad: ");
        scanf("%d", &auxMascota.edad);

        printf("Ingrese peso: ");
        scanf("%d",&auxMascota.peso);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &auxMascota.sexo);

        printf("Ingrese color: ");
        fflush(stdin);
        gets(auxMascota.color);
/*
        printf("Ingrese fecha ingreso: ");
        scanf("%d/%d/%d", &auxMascota.fechaIngreso.dia, &auxMascota.fechaIngreso.mes, &auxMascota.fechaIngreso.anio);
*/
        auxMascota.isEmptyMascota=0;

        listarMascota[indice]=auxMascota;
        todoOk = 1;

    }
    return todoOk;
}
void mostrarMascota(eMascota mascota, int tamM, eTipo listaT[], int tamT)
{
	char descripTipo[20];

	cargarDescripTipo(descripTipo, mascota.idTipo, listaT, tamT);
	printf("%d    %10s      %10s     %10s      %d     %.2f     %c    %d\n\n", mascota.id, mascota.nombre, descripTipo, mascota.raza, mascota.edad, mascota.peso, mascota.sexo, mascota.idDuenio);
}
int buscarMascota(int id, eMascota vec[], int tamM)
{
    int indice=-1;

    for(int i=0; i<tamM; i++)
    {
        if(vec[i].id == id && vec[i].isEmptyMascota == 0)
        {
            indice=i;
            break;
        }
    }
    return indice;
}
int cargarDescripcionMascota(char descripcion[], int id, eMascota mascota[], int tamM)
{
    int todoOk = 0;

    for(int i=0; i<tamM; i++)
    {
        if(mascota[i].id == id)
        {
            strcpy(descripcion, mascota[i].descripcion);
            todoOk = 1;
        }
    }
    return todoOk;
}
void modificarMascota(eMascota mascota[], int tamM)
{
    int id;
    int indice;
    char confirma;
    char nuevaMascota;
    system("cls");
    printf("*****Modificar mascota*****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice=buscarMascota(id, mascota, tamM);

    if(indice == -1)
    {

        printf("No hay registro de una mascota con el id: %d", id);
    }
    else
    {
        mostrarMascota(mascota[indice], mascota, tamSec);

        printf("\nModifica mascota?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma== 's')
        {
            printf("Ingrese nueva mascota: ");
            fflush(stdin);
            gets(nuevaMascota);
            mascota[indice].descripcion= nuevaMascota;
            printf("Se ha actualizado la mascota con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}
void bajaMascota(eMascota mascota[], int tamM)
{
    int id;
    int indice;
    char confirma;
    system("cls");
    printf("*****Baja mascota*****\n\n");
    printf("Ingrese id: ");
    scanf("%d", &id);

    indice=buscarMascota(id, mascota, tamM);

    if(indice == -1)
    {

        printf("No hay registro de una mascota con el id: %d", id);
    }
    else
    {
        mostrarMascota(mascota[indice], tamM);

        printf("\nConfirma baja de la mascota?: ");
        fflush(stdin);
        scanf("%c", &confirma);

        if(confirma== 's')
        {
            mascota[indice].isEmpty=1;
            printf("Se ha realizado la baja con exito\n\n");
        }
        else
        {
            printf("Se ha cancelado la operacion\n\n");
        }
    }
}
void mostrarMascotas(eMascota mascota[], int tamM)
{
    int flag=0;

    printf("*****Listado de mascotas*****\n");
    printf(" Id       Nombre     Tipo    Raza     Edad     Peso    Sexo     Color       Fecha ingreso\n\n");
    for(int i=0; i<tamM; i++)
    {
        if(mascota[i].isEmptyMascota==0)
        {
            mostrarMascota(mascota[i], mascota, tamM);
            flag = 1;
        }
    }
    if(flag==0)
    {
        printf("No hay mascotas que listar\n");
    }
}
void inicializarMascotas(eMascota mascota[], int tamM)
{
    for(int i=0; i<tamM; i++)
    {
        mascota[i].isEmptyMascota=1;
    }
}
