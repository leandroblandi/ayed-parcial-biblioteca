#ifndef BIBLIOTECA_H_INCLUDED
#define BIBLIOTECA_H_INCLUDED

#include "lista.h"
#include "libro.h"

struct  Biblioteca;
typedef struct Biblioteca * BibliotecaPtr;

BibliotecaPtr crear_biblioteca(const char* nombre, const char* direccion);
void destruir_biblioteca(BibliotecaPtr biblioteca);

void mostrar_biblioteca(BibliotecaPtr biblioteca);
void agregar_libro(BibliotecaPtr b, LibroPtr l);
void agregar_autor(BibliotecaPtr b, AutorPtr a);
void ordenar_biblioteca_anio_publicacion(BibliotecaPtr b);
void eliminar_autores_segun_criterio(ListaPtr l, bool(flag)(void*));

ListaPtr get_autores(BibliotecaPtr b);

#endif // BIBLIOTECA_H_INCLUDED
