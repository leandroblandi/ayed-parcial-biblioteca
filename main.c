#include <stdio.h>
#include <stdlib.h>

#include "biblioteca.h"


///Entregar el examen comprimido en zip o rar por campus. antes de las 19:30.


///El programa debe permitir trabajar con una Biblioteca que tiene una lista de Libros y una lista de autores. Las listas deben ser del tipo void.
///Se pide lo siguiente:
///1 - Agregar los 5 libros a la lista de libros
///2 - Agregar los 5 autores a la lista de autores
///3 - Mostrar la biblioteca con sus libros y autores, todo en un unico mostrar generico.  (hasta acá un 4)
///4 - Ordenar los libros por año de publicación. Y mostrar la biblioteca (Hasta acá un 6)
///5 - Eliminar los autores que tendrían más de 200 años utilizando una función eliminar generica sobre la lista. y Mostrar la Biblioteca. (hasta aca el 10)


int main()
{
    printf(" ------------Parcial Ayed - Octubre 2024 ------------------\n");
    BibliotecaPtr b1 = crear_biblioteca("Biblioteca Nacional Mariano Moreno", "Agüero 2502, CABA, Argentina");

    // Creacion de Libros
    LibroPtr l1 = crear_libro("Cien años de soledad", 1967, "Novela");
    LibroPtr l2 = crear_libro("1984", 1949, "Ciencia ficción");
    LibroPtr l3 = crear_libro("Don Quijote de la Mancha", 1605, "Novela");
    LibroPtr l4 = crear_libro("Orgullo y prejuicio", 1813, "Romance");
    LibroPtr l5 = crear_libro("El Señor de los Anillos", 1954, "Fantasía");

    // Creacion de Autores
    AutorPtr a1 = crear_autor("Gabriel García Márquez", "Colombiano", 1927);
    AutorPtr a2 = crear_autor("George Orwell", "Británico", 1903);
    AutorPtr a3 = crear_autor("Miguel de Cervantes", "Español", 1547);
    AutorPtr a4 = crear_autor("Jane Austen", "Británica", 1775);
    AutorPtr a5 = crear_autor("J.R.R. Tolkien", "Británico", 1892);

    // Agregamos cada libro
    agregar_libro(b1, l1);
    agregar_libro(b1, l2);
    agregar_libro(b1, l3);
    agregar_libro(b1, l4);
    agregar_libro(b1, l5);

    // Agregamos cada autor
    agregar_autor(b1, a1);
    agregar_autor(b1, a2);
    agregar_autor(b1, a3);
    agregar_autor(b1, a4);
    agregar_autor(b1, a5);

    // Mostramos la biblioteca con sus autores y libros
    mostrar_biblioteca(b1);

    // Ordenamos segun fecha de publicacion y mostramos
    printf("\n=== Ordenamiento segun fecha de publicacion ===\n");
    ordenar_biblioteca_anio_publicacion(b1);
    mostrar_biblioteca(b1);

    // Eliminamos autores con mas de 200 anios de antiguedad
    printf("\nEliminacion de autores con 200 anios o mas ===\n");
    eliminar_autores_segun_criterio(get_autores(b1), tiene_200_anios_o_mas);
    mostrar_biblioteca(b1);

    return 0;
}
