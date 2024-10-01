#ifndef NODO_H_INCLUDED
#define NODO_H_INCLUDED

struct Nodo;

typedef struct Nodo * NodoPtr;
typedef void * DatoPtr;


DatoPtr getDato(NodoPtr nodo);
NodoPtr getSiguiente(NodoPtr nodo);

void setDato(NodoPtr nodo, DatoPtr nuevoDato);
void setSiguiente(NodoPtr nodo, NodoPtr nuevoSiguiente);

NodoPtr crearNodo(DatoPtr dato, NodoPtr siguiente);


void liberarNodo(NodoPtr nodo);

#endif // NODO_H_INCLUDED
