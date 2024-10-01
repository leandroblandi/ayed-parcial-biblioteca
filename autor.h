#ifndef AUTOR_H_INCLUDED
#define AUTOR_H_INCLUDED

#include <stdbool.h>

struct Autor;
typedef struct Autor * AutorPtr;

AutorPtr crear_autor(const char* nombre, const char* nacionalidad, int anio_nacimiento);
void destruir_autor(AutorPtr autor);

void mostrar_autor_fn(void * a);
void mostrar_autor(AutorPtr autor);

bool tiene_200_anios_o_mas(void *a);
int obtener_anio_actual();

#endif // AUTOR_H_INCLUDED
