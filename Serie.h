// Serie.h (Mismo caso que con pelicula, se hace un uso de herencia de forma correcta)
// Clase derivada que representa una serie

#ifndef SERIE_H
#define SERIE_H

#include "Video.h"

// Clase Serie que hereda públicamente de Video
class Serie : public Video {
public:
    // Constructor de la clase Serie, este llama al constructor base
    Serie(int i, string n, double d, string g, double c);

    // Método específico para mostrar series
    void mostrarSerie();

    // Método que demuestra el acceso a métodos heredados
    void mostrarDetallesSerie();

    // Mismo caso que con 'Pelicula.h'
    void mostrarDetalles() override;
    void reproducir() override;
};

// Implementación del constructor, esto demostrara la herencia correcta
inline Serie::Serie(int i, string n, double d, string g, double c)
    : Video(i, n, d, g, c) {
    // Constructor base Video()
}

// Método para mostrar los datos de la serie
inline void Serie::mostrarSerie() {
    cout << "[Serie] ";
    // Uso el método protegido heredado de la clase base
    mostrarInfoBasica();
    cout << endl;
}

// Método que demuestra el uso de herencia y acceso a métodos públicos
inline void Serie::mostrarDetallesSerie() {
    cout << "=== DETALLES DE LA SERIE ===" << endl;
    cout << "Tipo: Serie" << endl;
    
    // Accede a atributos privados a través de métodos públicos heredados
    cout << "ID: " << getId() << endl;
    cout << "Titulo: " << getNombre() << endl;
    cout << "Duracion promedio por episodio: " << getDuracion() << " minutos" << endl;
    cout << "Genero: " << getGenero() << endl;
    cout << "Calificacion promedio: " << getCalificacion() << "/5" << endl;
}

// Al tratar de correr el codigo con la implementación de polimorfismo me soltaba un error que me decia que no estaba implementando al 100% una funcioj virtual pura
// Po resto mismo implemente un metodo virtual puro para video y asi logre que corriera el cogido
inline void Serie::mostrarDetalles() {
    mostrarDetallesSerie();
}

inline void Serie::reproducir() {
    cout << "Reproduciendo tu serie: " << getNombre() << endl;
    cout << "Tu serie dura " << getDuracion() << " minutos por cada episodio y es de genero " << getGenero() << endl;
}

#endif
