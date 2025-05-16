# Contexto.
Este sistema modela un servicio de streaming de video que maneja dos tipos principales de contenido: películas y series. Cada video tiene atributos comunes como un identificador único, nombre, duración, género y una calificación promedio basada en la valoración de los usuarios.

# Funcionalidad.
La clase base Video define atributos y métodos comunes para todo contenido de video. Pelicula y Serie heredan de Video; Pelicula representa películas individuales, mientras que Serie maneja colecciones de episodios con detalles como título, temporada y calificación. La herencia evita duplicación y facilita extensiones, y la composición entre Serie y Episodio modela la relación de múltiples episodios por serie. Este diseño permite mostrar videos con sus calificaciones, filtrar por tipo y consultar episodios con sus detalles.

# Uml.
https://www.canva.com/design/DAGnlpEu3BE/LfTRT_pYAHJW4puXz9zFqw/edit?utm_content=DAGnlpEu3BE&utm_campaign=designshare&utm_medium=link2&utm_source=sharebutton
