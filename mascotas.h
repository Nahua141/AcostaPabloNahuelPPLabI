#ifndef MASCOTAS_H_INCLUDED
#define MASCOTAS_H_INCLUDED
typedef struct
{
    char nombre[31];
    char tipo[31];
    char raza[31];
    int edad;
    float peso;
    char sexo;
    char color[20];
    int id;
    char descripcion[20];
    int isEmptyMascota;

} eMascota;
typedef struct
{
    int dia;
    int mes;
    int anio;
} eFecha;

#endif // MASCOTAS_H_INCLUDED
int buscarLibre(eMascota listarMascota[], int tamM);
int altaMascota(int idx, eMascota listarMascota[], int tamM);
void mostrarMascota(eMascota mascota, int tamM, eTipo listaT[], int tamT);
int buscarMascota(int id, eMascota vec[], int tamM);
int cargarDescripcionMascota(char descripcion[], int id, eMascota mascota[], int tamM);
void modificarMascota(eMascota mascota[], int tamM);
void bajaMascota(eMascota mascota[], int tamM);
void mostrarMascotas(eMascota mascota[], int tamM);
void inicializarMascotas(eMascota mascota[], int tamM);
