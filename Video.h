// Video.h (Modifique el codigo para implementar modificadores de acceso)
// Clase base que representa un video (puede ser película o serie)

#ifndef VIDEO_H
#define VIDEO_H

#include <iostream>
#include <string>
using namespace std;

// Clase general para los videos
class Video {
private:
    // Atributos privados, solo seran accesibles desde la misma clase
    int id;                 // Identificador único del video
    string nombre;          // Nombre del video
    double duracion;        // Duración en minutos
    string genero;          // Género del video (acción, drama, etc.)
    double calificacion;    // Calificación promedio (1 a 5)

protected:
    // Métodos protegidos que solo seran accesibles desde clases derivadas
    void mostrarInfoBasica();

public:
    // Métodos públicos, seran accesibles desde cualquier lugar
    
    // Constructor
    Video(int i, string n, double d, string g, double c);

    // Incluyo métodos getter para acceder a atributos privados
    int getId();
    string getNombre();
    double getDuracion();
    string getGenero();
    double getCalificacion();

    // De igual manera incluire métodos setter para modificar atributos privados
    void setId(int i);
    void setNombre(string n);
    void setDuracion(double d);
    void setGenero(string g);
    void setCalificacion(double c);

    // Método para mostrar la información general del video
    void mostrarInfo();

    // Implemento polimorfismo con el metodo virual visto en clase
    virtual void mostrarDetalles() = 0;
    virtual void reproducir() = 0;

    virtual void pausar () {
        cout << "Pausanod el video: " << nombre << endl;
    }

    // Intento implementar la sobrecarga haciendo multiples versiones de mi metodo "buscar"
    void buscar(string titulo);
    void buscar(int idVideo);
    void buscar(string genero, double calificacionMin);

    virtual ~Video() {} // Destructor virtual
};

// Implemento el constructor
inline Video::Video(int i, string n, double d, string g, double c) {
    id = i;
    nombre = n;
    duracion = d;
    genero = g;
    calificacion = c;
}

// Implemento los metodos getter
inline int Video::getId() {
    return id;
}

inline string Video::getNombre() {
    return nombre;
}

inline double Video::getDuracion() {
    return duracion;
}

inline string Video::getGenero() {
    return genero;
}

inline double Video::getCalificacion() {
    return calificacion;
}

// Implemento los metodos setters
inline void Video::setId(int i) {
    id = i;
}

inline void Video::setNombre(string n) {
    nombre = n;
}

inline void Video::setDuracion(double d) {
    duracion = d;
}

inline void Video::setGenero(string g) {
    genero = g;
}

inline void Video::setCalificacion(double c) {
    calificacion = c;
}

// Método protegido para que solo accesible por clases derivadas
inline void Video::mostrarInfoBasica() {
    cout << "ID: " << id 
         << ", Nombre: " << nombre 
         << ", Duracion: " << duracion << " minutos"
         << ", Genero: " << genero 
         << ", Calificacion: " << calificacion << "/5";
}

// Implementación del método público mostrarInfo
inline void Video::mostrarInfo() {
    mostrarInfoBasica();
    cout << endl;
}

// Implemento los metodos de sobrecarga
inline void Video::buscar(string titulo) {
    cout << "Buscando videos por el titulo dado: " << titulo << endl;
    if (nombre == titulo) {
        cout << "Video encontrado " << endl;
        mostrarInfoBasica();
        cout << endl;
    } else {
        cout << "El video no se encontro" << endl;
    } 
}

inline void Video::buscar(int idVideo) {
    cout << "Buscando videos por ID: " << idVideo << endl;
    if (id == idVideo) {
        cout << "Video encontrado " << endl;
        mostrarInfoBasica();
        cout << endl;
    } else {
        cout << "El video no se encontro " << endl;
    }
}

inline void Video::buscar(string generoVideo, double calificacionMin) {
    cout << "Buscando videos por genero (" << generoVideo << ") y calificación minima (" << calificacionMin << ")" << endl;
    if (genero == generoVideo && calificacion >= calificacionMin) {
        cout << "Video encontrado" << endl;
        mostrarInfoBasica();
        cout << endl;
    } else {
        cout << "El video no se encontro " << endl;
    }
}

#endif
