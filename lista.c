#include <stdio.h>
#include <stdlib.h>

#include "lista.h"

struct Lista {
    NodoPtr primero;
};

ListaPtr crearLista() {
    ListaPtr lista = (ListaPtr) malloc(sizeof(struct Lista));
    lista->primero = NULL;

    return lista;
}

NodoPtr getPrimero(ListaPtr lista) {
    return lista->primero;
}

void setPrimero(ListaPtr lista, NodoPtr nuevoPrimero) {
    lista->primero = nuevoPrimero;
}

void insertarPrimero(ListaPtr lista, DatoPtr dato) {
    NodoPtr nuevoNodo = crearNodo(dato, lista->primero);
    lista->primero = nuevoNodo;
}

void insertarUltimo(ListaPtr lista, DatoPtr dato) {
    NodoPtr nuevoNodo = crearNodo(dato, NULL);


    if(lista->primero == NULL) {
        lista->primero = nuevoNodo;
    } else {
        NodoPtr actual = lista->primero;
        while(getSiguiente(actual)!=NULL) {
            actual = getSiguiente(actual);
        }
        setSiguiente(actual, nuevoNodo);
    }
}

void insertarPosicion(ListaPtr lista, DatoPtr dato, int posicion) {
    int tam = obtenerTamanio(lista);
    if(posicion > tam+1) {
        printf("No existe esa posicion\n");
    }
    else if(posicion < 0) {
        printf("No existe esa posicion\n");
    }
    else if(posicion == 0) {
        insertarPrimero(lista, dato);
    }
    else if(posicion == tam) {
        insertarUltimo(lista, dato);
    }
    else if(posicion > 0 && posicion < tam){
        NodoPtr actual = lista->primero;
        for(int i=0; i<posicion-1; i++){
            actual = getSiguiente(actual);
        }
        setSiguiente(actual, crearNodo(dato, getSiguiente(actual)));
    }
}

DatoPtr eliminarPrimero(ListaPtr lista) {
    DatoPtr dato = NULL;
    NodoPtr actual = lista->primero;

    if(actual != NULL) {
        dato = getDato(actual);
        NodoPtr actual = lista->primero;
        lista->primero = getSiguiente(actual);
        liberarNodo(actual);
    }

    return dato;
}


DatoPtr eliminarPosicion(ListaPtr lista, int pos) {
    NodoPtr actual = lista->primero;
    NodoPtr anterior = NULL;
    DatoPtr dato = NULL;
    int tam = obtenerTamanio(lista);
    int i=0;

    if(actual == NULL){
        printf("Lista vacia\n");
    }
    else if (pos < 0 || pos >= tam) {
        printf("Posicion fuera de rango\n");
    }
    else if (pos == 0){
        dato = eliminarPrimero(lista);
    }
    else if (pos > 0 || pos < tam) {
        while(i != pos) {
            anterior = actual;
            actual = getSiguiente(actual);
            i++;
        }
        dato = getDato(actual);
        setSiguiente(anterior, getSiguiente(actual));
        liberarNodo(actual);
    }
    return dato;
}

void eliminarNodo(ListaPtr l, NodoPtr nodo) {
    if (l == NULL || nodo == NULL) {
        return;
    }

    if (getPrimero(l) == nodo) {
        NodoPtr nuevoPrimero = getSiguiente(nodo);
        setPrimero(l, nuevoPrimero);
        free(nodo);
        return;
    }

    NodoPtr nodoAnterior = getPrimero(l);
    while (nodoAnterior != NULL && getSiguiente(nodoAnterior) != nodo) {
        nodoAnterior = getSiguiente(nodoAnterior);
    }

    if (nodoAnterior != NULL) {
        NodoPtr nodoSiguiente = getSiguiente(nodo);
        setSiguiente(nodoAnterior, nodoSiguiente);
        free(nodo);
    }
}

NodoPtr obtenerPrimero(ListaPtr lista) {
    return lista->primero;
}

int obtenerTamanio(ListaPtr lista) {
    int tam = 0 ;
    NodoPtr actual = lista->primero;
    while (actual != NULL) {
        tam = tam + 1;
        actual = getSiguiente(actual);
    }

    return tam;
}



void mostrarListaGenerica(ListaPtr lista, void(*mostrar)(DatoPtr)){
    printf("\n<LISTA> TAM:%d \n", obtenerTamanio(lista));
    NodoPtr actual = lista->primero;

    while (actual!=NULL){

        mostrar(getDato(actual));
        actual = getSiguiente(actual);
    }
    printf("\n\n");
};

void ordenar_por_seleccion(ListaPtr lista, int (*cmp)(void *, void *)) {
    if (lista == NULL || obtenerTamanio(lista) == 0 || cmp == NULL) {
        return;
    }

    NodoPtr nodoActual = lista->primero;
    NodoPtr nodoMinimo, nodoIterador;

    while (nodoActual != NULL) {
        nodoMinimo = nodoActual;
        nodoIterador = getSiguiente(nodoActual);

        while (nodoIterador != NULL) {
            if (cmp(getDato(nodoIterador), getDato(nodoMinimo)) < 0) {
                nodoMinimo = nodoIterador;
            }
            nodoIterador = getSiguiente(nodoIterador);
        }

        if (nodoMinimo != nodoActual) {
            DatoPtr datoAux = getDato(nodoActual);
            setDato(nodoActual, getDato(nodoMinimo));
            setDato(nodoMinimo, datoAux);
        }

        nodoActual = getSiguiente(nodoActual);
    }
}



void liberarLista(ListaPtr lista) {
    NodoPtr actual = lista->primero;
    NodoPtr aux;

    while (actual!=NULL) {
        aux = actual;
        actual = getSiguiente(actual);
        free(aux);
    };
}
