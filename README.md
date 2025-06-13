# Contexto.
Este sistema modela un servicio de streaming de video que maneja dos tipos principales de contenido: películas y series. Cada video tiene atributos comunes como un identificador único, nombre, duración, género y una calificación promedio basada en la valoración de los usuarios.

# Funcionalidad.
La clase base Video define atributos y métodos comunes para todo contenido de video. Pelicula y Serie heredan de Video; Pelicula representa películas individuales, mientras que Serie maneja colecciones de episodios con detalles como título, temporada y calificación. La herencia evita duplicación y facilita extensiones, y la composición entre Serie y Episodio modela la relación de múltiples episodios por serie. Este diseño permite mostrar videos con sus calificaciones, filtrar por tipo y consultar episodios con sus detalles.

# Casos que podrian ocasionar el fallo.

## 1. **Problemas con datos de entrada**

**IDs inválidos**: Si paso un ID negativo o cero, el sistema no sabría como identificar el video correctamente. 

**Nombres vacíos**: Un string vacío haría que al mostrar información se vea raro o cause errores

**Duración negativa**: No tiene sentido que una película dure -120 minutos, esto rompería la lógica

**Calificaciones fuera de rango**: El sistema maneja calificaciones de 1-5, si paso 10 o -2 se rompe

## 2. **Errores de compilación**

**Headers mal incluidos**: Si olvido incluir las librerías necesarias como "iostream" o "string"

**Dependencias circulares**: Si Video.h incluye Serie.h y Serie.h incluye Video.h, el compilador se podria confundir.

**Problemas con using namespace std**: Si no lo pongo, tendría que escribir std::cout en vez de cout en todos lados. (esto se explico en clase, es mas que nada para hacerlo mas 'sencillo'

## 3. **Problemas lógicos del programa**

**IDs duplicados**: Si creo dos videos con el mismo ID, no podría distinguirlos

**Strings con caracteres raros**: Nombres con acentos o símbolos especiales podrían causar problemas de encoding.

## 4. **Errores de memoria (si se llega a ampliar el codigo)**

**Memory leaks**: Si usáramos punteros y no liberáramos la memoria con delete.

**Punteros nulos**: Intentar acceder a un objeto que apunta a NULL haría que el programa crashee.

**Cosas que cambie en el codigo**: En el anterior envio intente implementar una opcion para que la pelicula, serie o video se pudieran pausar (asi como se hace en la vida real), no logre implementarlo de manera correcta asi que decidi quitarlo por completo del codigo. 
Tenia peliculas y series ya predeterminadas en el codigo, lo que hacian era que al llamar a consola pues se desplegaban automaticamente mostrandose como si fuesen opciones a elegir. Al revisarlo con el profe, se me encargo hacer una interfaz para poder interactuar con ella asi que tambien decidi borrar lo que se tenia de forma predeterminada para que fuese una interfaz vacia.
Pelicula, serie y video se quedaron tal cual estaban antes, el unico que cambio fue mi main al realizar la interfaz (me costo bastante por que habian cosas que no me compilaban pero se logro)
Se cambio el UML ya que el anterior era el del primer avance

# Uml.
https://lucid.app/lucidchart/66d5ddbf-68be-4ac6-911d-f268b98e2b79/edit?viewport_loc=38%2C-77%2C3307%2C1486%2C0_0&invitationId=inv_838c344d-ef14-404b-b521-ebb9d4e50600

