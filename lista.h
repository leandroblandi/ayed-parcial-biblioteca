#ifndef LISTA_H_INCLUDED
#define LISTA_H_INCLUDED

#include "nodo.h"

struct Lista;

typedef struct Lista * ListaPtr;

ListaPtr crearLista();
void liberarLista(ListaPtr lista);

NodoPtr getPrimero(ListaPtr lista);
void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero);

// Insertar:
void insertarPrimero(ListaPtr lista, DatoPtr dato);
void insertarUltimo(ListaPtr lista, DatoPtr dato);
void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion);

// Eliminar:
DatoPtr eliminarPrimero(ListaPtr lista);
DatoPtr eliminarPosicion(ListaPtr lista, int posicion);

/// @brief Eliminar por
void eliminarNodo(ListaPtr l, NodoPtr nodo);

// Obtener:
NodoPtr obtenerPrimero(ListaPtr lista);
int obtenerTamanio(ListaPtr lista);

void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr));
void ordenar_por_seleccion(ListaPtr lista, int (*cmp)(void *, void *));

#endif // LISTA_H_INCLUDED
