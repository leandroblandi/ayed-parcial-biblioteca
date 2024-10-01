#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "funciones.h"
#include "autor.h"

struct Autor {
    char nombre[100];
    char nacionalidad[50];
    int anio_nacimiento;
};

AutorPtr crear_autor(const char* nombre, const char* nacionalidad, int anio_nacimiento) {
    AutorPtr nuevo_autor = ( AutorPtr )malloc(sizeof(struct Autor));

    if (nuevo_autor == NULL) {
        printf("Error al asignar memoria para el autor\n");
        return NULL;
    }

    strcpy(nuevo_autor->nombre, nombre);
    strcpy(nuevo_autor->nacionalidad, nacionalidad);
    nuevo_autor->anio_nacimiento = anio_nacimiento;

    return nuevo_autor;
}

void mostrar_autor_fn(void * a) {
    if (a == NULL) {
        return;
    }

    mostrar_autor((AutorPtr) a);
}

void mostrar_autor(AutorPtr autor) {
    if (autor != NULL) {
        printf("\nAutor: %s\n", autor->nombre);
        printf("Nacionalidad: %s\n", autor->nacionalidad);
        printf("Año de nacimiento: %d\n", autor->anio_nacimiento);
    }
}

bool tiene_200_anios_o_mas(void *a) {
    AutorPtr autor = (AutorPtr) a;
    return (obtener_anio_actual() - autor->anio_nacimiento) > 200;
}

void destruir_autor(AutorPtr  autor) {
    if (autor != NULL) {
        free(autor);
    }
}
