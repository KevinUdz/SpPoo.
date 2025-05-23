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

# Uml.
https://www.canva.com/design/DAGnlpEu3BE/LfTRT_pYAHJW4puXz9zFqw/edit?utm_content=DAGnlpEu3BE&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton
