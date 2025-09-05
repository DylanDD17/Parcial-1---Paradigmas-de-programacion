#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ESTUDIANTES 100 

typedef struct {
    char *nombre; 
    char *apellido; 

    //Uso de bitfields 
    unsigned int edad : 8;  // 8 bits (0-255)
    unsigned int id   : 20; // 20 bits (1 millon max)

    float *calificaciones; // ✔ Array dinamico -> tamaño exacto de num_calificaciones
    size_t num_calificaciones;
} Estudiante;

// Creacion de estudiantes
Estudiante *crearEstudiante(const char *nombre, const char *apellido,
                           unsigned char edad, unsigned int id,
                           float *calificaciones, size_t num_calificaciones) {
    // Uso de malloc para asignar memoria para la estructura 
    Estudiante *e = malloc(sizeof(Estudiante));
    if (!e) exit(EXIT_FAILURE);

    // Asignacion de memoria exacta para nombre y apellido
    e->nombre = malloc(strlen(nombre) + 1);
    e->apellido = malloc(strlen(apellido) + 1);
    if (!e->nombre || !e->apellido) exit(EXIT_FAILURE);

    strcpy(e->nombre, nombre);
    strcpy(e->apellido, apellido);

    e->edad = edad;
    e->id = id;

    // ✔ Asignacion dinámica del array de calificaciones
    e->calificaciones = malloc(num_calificaciones * sizeof(float));
    if (!e->calificaciones) exit(EXIT_FAILURE);
    memcpy(e->calificaciones, calificaciones, num_calificaciones * sizeof(float));

    e->num_calificaciones = num_calificaciones;

    return e;
}


// Liberar memoria de estudiante (free)
void liberarEstudiante(Estudiante *e) {
    if (e) {
        // Liberacion de memoria dinamica 
        free(e->nombre);
        free(e->apellido);
        free(e->calificaciones);
        free(e); // Libera la memoria de la estructura completa
    }
}


// Mostrar estudiantes
void mostrarEstudiantes(Estudiante *estudiantes[], size_t cantidad) {
    printf("\nLista de estudiantes (%zu):\n", cantidad);
    for (size_t i = 0; i < cantidad; i++) {
        if (estudiantes[i] != NULL) {
            Estudiante *e = estudiantes[i];
            printf(" - %s %s | Edad: %u | ID: %u | Calificaciones: ",
                   e->nombre, e->apellido, e->edad, e->id);
            for (size_t j = 0; j < e->num_calificaciones; j++) {
                printf("%.1f ", e->calificaciones[j]);
            }
            printf("\n");
        }
    }
}


int main() {
    Estudiante *estudiantes[MAX_ESTUDIANTES] = {NULL};
    size_t cantidad = 0;

    float calif1[] = {4.5, 3.8, 4.0};
    float calif2[] = {3.2, 4.0};

    estudiantes[cantidad++] = crearEstudiante("Dylan", "Torres", 20, 12345, calif1, 3);
    estudiantes[cantidad++] = crearEstudiante("Valentina", "Sanchez", 22, 67890, calif2, 2);

    mostrarEstudiantes(estudiantes, cantidad);

    // Compactacion de memoria: liberar el primer estudiante para optimizar espacio
    liberarEstudiante(estudiantes[0]);
    estudiantes[0] = NULL;

    printf("\nDespués de liberar el primero:\n");
    mostrarEstudiantes(estudiantes, cantidad);

    // Liberacion de memoria de todos los estudiantes restantes
    for (size_t i = 0; i < cantidad; i++) {
        liberarEstudiante(estudiantes[i]);
    }

    return 0;
}