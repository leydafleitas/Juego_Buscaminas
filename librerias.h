#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Definimos algunas constantes
#define MAX_LONGITUD_NOMBRE 50
#define MAX_LONGITUD_CONTRASENA 50
#define MAX_USUARIOS 100

// Definimos una estructura que representa a un usuario
typedef struct {
    char nombre_usuario[MAX_LONGITUD_NOMBRE];
    char contrasena[MAX_LONGITUD_CONTRASENA];
    int partidas_jugadas;
    int partidas_ganadas;
    int partidas_perdidas;
    int puntaje_total;
} Usuario;

typedef struct {
    int coordenadax;
    int coordenaday;
} Tupla; //Creamos la estructura Tupla, para guardar las coordenadas que necesitamos en forma (x,y)
