#ifndef SERVICIOS_H_INCLUDED
#define SERVICIOS_H_INCLUDED
typedef struct
{
    int id;
    char descripcion[20];
}eServicios;


#endif // SERVICIOS_H_INCLUDED
int mostrarServicios(eServicios servicio[], int tamS);
int cargarDescServicios(char descripcion[], int idServicios, eServicios servicios[], int tamS);
