#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#include "lista.h"
#include "libro.h"
#include "autor.h"
#include "biblioteca.h"


struct  Biblioteca{
    char nombre[100];
    char direccion[150];
    ListaPtr libros;
    ListaPtr autores;
} ;

BibliotecaPtr crear_biblioteca(const char* nombre, const char* direccion) {

    BibliotecaPtr nueva_biblioteca = (BibliotecaPtr) malloc(sizeof(struct Biblioteca));

    if (nueva_biblioteca == NULL) {
        printf("Error al asignar memoria para la biblioteca\n");
        return NULL;
    }

    strcpy(nueva_biblioteca->nombre, nombre);
    strcpy(nueva_biblioteca->direccion, direccion);

    nueva_biblioteca->libros = crearLista();
    nueva_biblioteca->autores = crearLista();

    return nueva_biblioteca;
}



void mostrar_biblioteca(BibliotecaPtr biblioteca) {
    if (biblioteca != NULL) {
        printf("Biblioteca: %s\n", biblioteca->nombre);
        printf("Dirección: %s\n", biblioteca->direccion);
    }

    if (biblioteca->libros != NULL && obtenerTamanio(biblioteca->libros) > 0) {
        mostrarListaGenerica(biblioteca->libros, mostrar_libro_fn);
    }

    if (biblioteca->autores != NULL && obtenerTamanio(biblioteca->autores) > 0) {
        mostrarListaGenerica(biblioteca->autores, mostrar_autor_fn);
    }
}

void agregar_libro(BibliotecaPtr b, LibroPtr l) {
    insertarUltimo(b->libros, (DatoPtr) l);
}

void agregar_autor(BibliotecaPtr b, AutorPtr a) {
    insertarUltimo(b->autores, (DatoPtr) a);
}

void ordenar_biblioteca_anio_publicacion(BibliotecaPtr b) {
    if (b == NULL) {
        return;
    }

    ordenar_por_seleccion(b->libros, comparar_anio_publicacion_fn);
}

void eliminar_autores_segun_criterio(ListaPtr l, bool(flag)(void*)) {
    NodoPtr nodoIterador = getPrimero(l);

    while (nodoIterador != NULL) {
        NodoPtr nodoSiguiente = getSiguiente(nodoIterador);

        if (flag(getDato(nodoIterador))) {
            eliminarNodo(l, nodoIterador);
        }

        nodoIterador = nodoSiguiente;
    }
}


ListaPtr get_autores(BibliotecaPtr b) {
    return b->autores;
}

void destruir_biblioteca(BibliotecaPtr biblioteca) {
    if (biblioteca != NULL) {
        free(biblioteca);
    }
}
