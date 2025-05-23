// Pelicula.h (Se hace una correcion para usar la herencia de forma correcta)
// Clase derivada que representa una película

#ifndef PELICULA_H
#define PELICULA_H

#include "Video.h"

// Se llama a la clase Película que hereda públicamente de Video
class Pelicula : public Video {
public:
    // Implemento el Constructor de la clase Película que llama al constructor base
    Pelicula(int i, string n, double d, string g, double c);

    // Método específico para mostrar películas
    void mostrarPelicula();

    // Método que demuestra acceso a métodos heredados
    void mostrarDetallesPelicula();
};

// Se implementa un constructor que demuestra la herencia correcta
inline Pelicula::Pelicula(int i, string n, double d, string g, double c)
    : Video(i, n, d, g, c) {
    // Constructor base Video() 
    // Aquí se podrían inicializar atributos específicos de Pelicula
}

// Método para mostrar los datos de la película
inline void Pelicula::mostrarPelicula() {
    cout << "[Pelicula] ";
    // Uso el método protegido heredado de la clase base
    mostrarInfoBasica();
    cout << endl;
}

// Método que demuestra el uso de herencia y acceso a métodos públicos
inline void Pelicula::mostrarDetallesPelicula() {
    cout << " DETALLES DE LA PELICULA " << endl;
    cout << "Tipo: Pelicula" << endl;
    
    // Accede a atributos privados a través de métodos públicos heredados
    cout << "ID: " << getId() << endl;
    cout << "Titulo: " << getNombre() << endl;
    cout << "Duracion: " << getDuracion() << " minutos" << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "Calificacion: " << getCalificacion() << "/5" << endl;
    
}

#endif