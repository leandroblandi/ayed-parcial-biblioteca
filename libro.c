#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "libro.h"


struct  Libro{
    char titulo[100];
    int anio_publicacion;
    char genero[50];

} ;

LibroPtr crear_libro(const char* titulo, int anio_publicacion, const char* genero) {
    LibroPtr nuevo_libro = (LibroPtr) malloc(sizeof(struct Libro));

    if (nuevo_libro == NULL) {
        printf("Error al asignar memoria para el libro\n");
        return NULL;
    }
    strcpy(nuevo_libro->titulo, titulo);
    nuevo_libro->anio_publicacion = anio_publicacion;
    strcpy(nuevo_libro->genero, genero);


    return nuevo_libro;
}

void mostrar_libro_fn(void * l) {
    if (l == NULL) {
        return;
    }

    mostrar_libro((LibroPtr) l);
}

void mostrar_libro(LibroPtr libro) {
    if (libro != NULL) {
        printf("\nLibro: %s\n", libro->titulo);
        printf("Año de publicación: %d\n", libro->anio_publicacion);
        printf("Género: %s\n", libro->genero);

    }
}

int comparar_anio_publicacion_fn(void * d1, void * d2) {
    LibroPtr l1 = (LibroPtr) d1;
    LibroPtr l2 = (LibroPtr) d2;

    if (l1->anio_publicacion > l2->anio_publicacion) {
        return 1;
    }

    else if (l1->anio_publicacion < l2->anio_publicacion) {
        return -1;
    }
    return 0;
}

void destruir_libro(LibroPtr libro) {
    if (libro != NULL) {
        free(libro);
    }
}
