// main.cpp
// Programa principal para probar las clases Pelicula y Serie

#include <iostream>
#include "Pelicula.h"
#include "Serie.h"

using namespace std;

// Me falta crear la interfaz para que el usuario pueda interactuar con el programa, ya se metiendo peliclas, series o videos
// Limitare la creacrion del maximo de videos que se puedan crear para evitar saturar el programa
const int MAX_VIDEOS = 20;

// Primero creare un constructor vacio para que se puedan almacenar los videos que el usuario desee agregar
class SistemaVideos {
    private:
   Video* videos[MAX_VIDEOS ];// Se usa el * porque apunta a objetos de tipo Video
   int totalVideos; 

    public:
    SistemaVideos() { // Este es el constructor
        totalVideos = 0;
    }

    ~SistemaVideos() { // Se libera la memoria
        for (int i = 0; i < totalVideos; i++) {
            delete videos[i];
        }
    }


// Ahora si se crea la interfaz (me base en el proyecto que realize el anterior semestre)
void mostrarMenu() {
    cout << "===== Bienvenido al modelo de streaming ===== " << endl;
    cout << "Elije la opcion a la que quieras ingresar " << endl;
    cout << "1. Ver videos que se encuentran disponibles " <<endl;
    cout << "2. Ver una pelicula " << endl; 
    cout << "3. Ver una serie " << endl; 
    cout << "5. Buscar un video por su titulo " << endl;
    cout << "6. Buscar un video por su ID " << endl;
    cout << "7. Buscar por genero y calificacion " << endl;
    cout << "8. Reproducir un video " << endl;
    cout << "9. Agregar una pelicula " << endl;
    cout << "10. Agregar una serie" << endl;
    cout << "0. Salir del modelo " << endl;
    cout << " Hay un total de: " << totalVideos<< " videos" << " y puedes tener un maximo de " << MAX_VIDEOS << " videos " << endl;
    cout << " Selecciona una opcion: ";

}

void mostrarVideosDisp() {
    if (totalVideos == 0) {
        cout << "No hay videos disponibles, agrega algunos para lograr visualizarnos por aqui " << endl;
        return;
    }

    cout << " Videos disponibles " << endl;
    for (int i = 0; i < totalVideos; i++) {
        cout << " Video numero " << i + 1 << endl;
        videos[i] -> mostrarDetalles();
        cout << endl;
    }
}

// Esta fucion me costo porque no lograba separar bien  las peliculas de las series
void mostrarPelis() {
    cout << "Peliculas disponibles " << endl;
    bool encontrado = false;
    for (int i = 0; i < totalVideos; i++) {
        cout << "Mostrando video " << i+1 << ":" << endl; // Por ahora se muestran todos juntos y por la falta de tiempo no creo conseguir eso
        videos[i]->mostrarDetalles();
        encontrado = true;
        cout << endl;
    }
    if (!encontrado) {
        cout << "Aun no tienes nada guardado, prueba con agregar unas en la seccion 9 " << endl;
    }
}

void mostrarSeries() {
    cout << "Series disponibles " << endl;
    bool encontrado = false;
    for (int i = 0; i < totalVideos; i++) {
        cout << "Mostrando video " << i+1 << ":" << endl;
        videos[i]->mostrarDetalles();
        encontrado = true;
        cout << endl;
    }
    if (!encontrado) {
        cout << "Aun no tienes nada guardado, prueba con agregar unas en la seccion 10 " << endl;
    }
}

void buscarPorLabel() {
    if (totalVideos == 0) {
        cout << " No hay videos para buscar " << endl;
        return;
    }

    string titulo;
    cout << "Ingrese el titulo del video: ";
    cin.ignore(); // No me aparecia el mensaje en la terminal asi que recurri a la IA para solucionar el problema y encontre que se debe a que al utilizar los "getlines" y presionar "enter", la consola lee el enter como una linea vacia e ignora lo que estaba abajo de el.
                  // Lo que hace el cin.ignore es limpiar el buffer antes de mi getline para que se pueda leer lo que esta por abajo de el
    getline(cin, titulo);

    bool encontrado = false;
    for (int i=0; i<totalVideos; i++) {
        if (videos[i]->getNombre() == titulo) {
            cout << "Se encontro el video:" <<endl;
            videos[i]->mostrarDetalles();
            encontrado = true;
            break;
        }
    }
    
    if (!encontrado) {
        cout << " No se encontro el video: " << titulo << endl;
    }
}

void buscarPorID() {
    if (totalVideos == 0) {
        cout << "No hay videos para buscar" << endl;
        return;
    }

    int id;
    cout << "Ingresa el ID del video: ";
    cin >> id;

    bool encontrado = false;
    for (int i=0; i < totalVideos; i++) {
        if (videos[i]->getId() == id) {
            cout << "Se encontro el video" << endl;
            videos[i]->mostrarDetalles();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro el video con el ID: " << id << endl;
    }
}

void buscarPorGenCal() {
    if (totalVideos == 0) {
        cout << "No hay videos para poder buscar " << endl;
        return;
    }

    string genero;
    double calif;

    cout << "Ingresa el genero: ";
    cin.ignore();
    getline(cin, genero);
    cout << "Ingresa la calificación (1-5): ";
    cin >> calif;

    cout << "Se encontraron los siguientes videos: " << endl;
    bool encontrado = false;
    for (int i=0; i < totalVideos; i++) {
        if (videos[i]->getGenero() == genero && videos[i]->getCalificacion() >= calif) {
            videos[i]->mostrarDetalles();
            encontrado = true;
            cout << endl;
        }
    }
    
    if (!encontrado) {
        cout << "No se encontraron videos con esas caracteristicas " << endl;
    }
}

void reproducirVideo() {
    if (totalVideos == 0) {
        cout << "No hay videos para buscar" << endl;
        return;
    }

    int id;
    cout << "Ingresa el ID del video que deseas reproducir: ";
    cin >> id;

    bool encontrado = false;
    for (int i = 0; i<totalVideos; i++) {
        if (videos[i]->getId() == id) {
            cout << "Reproduciendo.." << endl;
            videos[i]->reproducir();
            encontrado = true;
            break;
        }
    }

    if (!encontrado) {
        cout << "No se encontro ningun video, verifica el ID y vuelvelo a intentar" << endl;
    }
}

// Creare una funcion para revisar si el ID ya existe, mas que nada para evitar los duplicados y que el codigo falle
bool existeId(int id) {
    for (int i=0; i<totalVideos; i++) {
        if (videos[i]->getId() == id) {
            return true;
        }
    }

    return false;
}

void agregarPelicula() {
    if (totalVideos >= MAX_VIDEOS) {
        cout << "No se pueden agregar mas videos, el limite se alcanzo" << endl;
        return;
    }

    int id;
    string nombre, genero;
    double duracion, calificacion;

    cout << "Agregar una nueva pelicula " << endl;
    cout << "Inserta el ID: ";
    cin >> id;

    if (existeId(id)) {
        cout << "Ya existe un video con ese ID, intenta con otro" << endl;
        return;
    }

    cin.ignore();
    cout << "Nombre de la pelicula: ";
    getline(cin, nombre);
    cout << "Duracion (en minutos): ";
    cin >> duracion;
    cin.ignore();
    cout << "Genero: ";
    getline(cin, genero);
    cout << "Calificacion (1-5): ";
    cin >> calificacion;

    videos[totalVideos] = new Pelicula(id, nombre, duracion, genero, calificacion);
    totalVideos++;
    cout << "Tu pelicula fue agregada con exito" << endl;
}

void agregarSerie() {
    if (totalVideos >= MAX_VIDEOS) {
        cout << "No se pueden agregar mas videos, el limite se alcanzo" << endl;
        return;
    }

    int id;
    string nombre, genero;
    double duracion, calificacion;

    cout << "Agregar una nueva serie " << endl;
    cout << "ID: ";
    cin >> id;
    
    if (existeId(id)) {
        cout << "Ya existe un video con ese ID, intenta con otro" << endl;
        return;
    }

    cin.ignore();
    cout << "Nombre de la serie: ";
    getline(cin, nombre);
    cout << "Duracion por episodio (en minutos): ";
    cin >> duracion;
    cin.ignore();
    cout << "Genero: ";
    getline(cin, genero);
    cout << "Calificacion (1-5): ";
    cin >> calificacion;

    videos[totalVideos] = new Serie(id, nombre, duracion, genero, calificacion);
    totalVideos++;
    cout << "Tu serie fue agregada con exito" << endl;
}

void ejecutar() {
    int opcion;

    do {
        mostrarMenu();
        cin >> opcion;

        // Haciendo uso del switch case puedo manejar todas las opciones del menu, esto lo vi en un video (tambien me ayude de mi anterior proyecto)
        switch (opcion) {
            case 1:
            mostrarVideosDisp();
            break;
            case 2:
            mostrarPelis();
            break;
            case 3:
            mostrarSeries();
            break;
            case 5:
            buscarPorLabel();
            break;
            case 6:
            buscarPorID();
            break;
            case 7:
            buscarPorGenCal();
            break;
            case 8:
            reproducirVideo();
            break;
            case 9:
            agregarPelicula();
            break;
            case 10:
            agregarSerie();
            break;
            case 0:
            cout << "Gracias por utlizar el modelo de streaming, vuelve pronto!" << endl;
            break;
            default:
            cout << "Esa opcion no es valida, intetalo de nuevo por favor" << endl;
        }

        // Implementare una "pausa" para que el usuario pueda leer antes de volver al menu, esto tambien ayuda a que no se tenga que llamar al codigo cada vez que se termine una interacción
        if (opcion !=0) {
            cout << "Presiona enter para contiuar";
            cin.ignore();
            cin.get(); // Debido a que implemente la "pausa" hago uso del "cin.get()". Este es el que me ayuda a esperar hasta que el usuario le de al enter para continaur
        }
    } while (opcion != 0);
}
    
};

int main() {
    SistemaVideos sistema;
    sistema.ejecutar();
    return 0;
}
