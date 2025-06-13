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

    // Aun no me queda del todo claro la sobreescritura pero la trato de implementar para lograr el polimorofismo
    void mostrarDetalles() override;
    void reproducir() override;

};

// Se implementa un constructor que demuestra la herencia correcta
inline Pelicula::Pelicula(int i, string n, double d, string g, double c)
    : Video(i, n, d, g, c) {
    // Constructor base Video() 
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
    cout << "=== DETALLES DE LA PELICULA ===" << endl;
    cout << "Tipo: Pelicula" << endl;
    
    // Accede a atributos privados a través de métodos públicos heredados
    cout << "ID: " << getId() << endl;
    cout << "Titulo: " << getNombre() << endl;
    cout << "Duracion: " << getDuracion() << " minutos" << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "Calificacion: " << getCalificacion() << "/5" << endl;
    
}

// Mismo caso que con 'serie' con la diferencia de que ahora fue en 'pelicula'
inline void Pelicula::mostrarDetalles() {
    mostrarDetallesPelicula();
}

inline void Pelicula::reproducir() {
    cout << "Reproduciendo tu pelicula: " << getNombre() << endl;
    cout << "La pelicula tiene una duracion de " << getDuracion() << " minutos y es de genero " << getGenero() << endl;
}

#endif
