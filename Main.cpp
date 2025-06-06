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
        cout << "\n=== VIDEO " << i + 1 << " ===" << endl;
        
        // Este sera el comportamiento específico de cada clase
        videos[i]->mostrarDetalles();
        cout << endl;
        
        // Cada clase tendra su propia implementación
        videos[i]->reproducir();
        cout << endl;
        
        videos[i]->pausar();
        cout << endl;
    }

    // Implemento sobrecarga con mismo metodo pero diferentes parametros
    cout << "\n--- Buscando por titulo ---" << endl;
    videos[0]->buscar("Inception");
    
    cout << "\n--- Buscando por ID ---" << endl;
    videos[1]->buscar(2);
    
    cout << "\n--- Buscando por genero y calificacion ---" << endl;
    videos[0]->buscar("Accion", 4.5);

    // Para evitar errores se libera la memoria
    for (int i = 0; i < 2; i++) {
        delete videos[i];
    }

    return 0;
}
