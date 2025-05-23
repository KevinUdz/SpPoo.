// main.cpp
// Programa principal para probar las clases Pelicula y Serie

#include <iostream>
#include "Pelicula.h"
#include "Serie.h"

int main() {
    // Se crea una película con sus datos
    Pelicula peli1(1, "Inception", 148, "Accion", 4.8);

    // Se crea una serie con sus datos
    Serie serie1(2, "Stranger Things", 50, "Misterio", 4.7);

    // Se muestra la información de la película
    cout << " Informacion de la Pelicula " << endl;
    peli1.mostrarPelicula();

    // Se muestra la información de la serie
    cout << "\n Informacion de la Serie " << endl;
    serie1.mostrarSerie();

    return 0;
}