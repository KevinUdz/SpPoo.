// main.cpp
// Programa principal para probar las clases Pelicula y Serie

#include <iostream>
#include "Pelicula.h"
#include "Serie.h"

int main() {
    // Creare los punteros a la clase base apuntando a los objetos derivados
    Video * videos[2];

    videos[0] = new Pelicula(1, "Inception", 148, "Accion", 4.8); // Guardo las direcciones de estos objetos para que puedan 'videos' pueda apuntar a una pelicula y el otro a una serie
    videos[1] = new Serie(2, "Stranger Things", 50, "Misterio", 4.7);

    for (int i = 0; i < 2; ++i) {  // implemento un ciclo for para llamarlos
        cout << "\nCargando video " << i + 1<< ":\n";
        videos[i]->mostrarDetalles();  // Aqui estaria llamando a 'mostrarDetalles' haciendo uso del puntero '->' que tambien se vio en clase

    }

    // Para evitar errores se libera la memoria
    for (int i = 0; i < 2; i++) {
        delete videos[i];
    }

    return 0;
}
