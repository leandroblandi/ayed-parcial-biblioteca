#ifndef LIBRO_H_INCLUDED
#define LIBRO_H_INCLUDED

#include "autor.h"

struct Libro;
typedef struct Libro * LibroPtr;

LibroPtr crear_libro(const char* titulo, int anio_publicacion, const char* genero);
void destruir_libro(LibroPtr libro);

void mostrar_libro_fn(void * libro);
void mostrar_libro(LibroPtr libro);
int comparar_anio_publicacion_fn(void * d1, void * d2);

#endif // LIBRO_H_INCLUDED
