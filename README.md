## Sistema Solar
Simulacion de sistema solar representado en OpenGL. 

El proyecto no contiene texturas ni iluminacion. 
Se limita a representar archivos obj como objetos en memoria para posteriormente crear caras con las funciones de openGL y definir su posicion y movimiento.

El objeto es una ovoide para todos los planetas ya que solamente se necesita una referencia a la forma. 

### Contenido del proyecto.

**Lector de archivos obj.**
    Restringue los archivos obj a tener los vertices, normales a los vertices y caras trianguladas.
    Para cada cara se requiere tener el formato <vertice>/<vacio>/<textura>
    Para poder transformar cualquier archivo obj en uno funcional para el programa se recomienda usar blender y seguir las siguientes instrucciones. 
        * Importar el archivo obj al proyecto de blender (si es que ya se cuenta con un objeto obj).
        * Acomodar el centro del objeto con el origen (al momento de exportar y transportar los vertices sera mas facil de controlar).
        * Exportar el proyecto a un archivo obj. 
        * Dentro de la seccion de Geometria seleccionar solamente las casillas de escribir normales y triangular caras.
   
   Nota: Si requieres reducir el numero de caras de un objeto puedes hacerlo tambien en blender antes de exportarlo.
        * Selecciona el objeto completo.
        * Selecciona el apartado de propiedades de modificadores/agregar modificador/Decimate.
        * Indica el valor de caras conforme al original en una escala de 0 hasta 1.
        * Cuando un porcentaje de este total te parezca conveniente sigue los pasos anteriores para exportarlo, agregando la casilla de aplicar modificadores para mantener el ratio de caras que indicaste previamente.
				
**Archivos obj.**

El proyecto utilizo el mismo archivo obj para todos los planetas y astros, ubicado en la carpeta de objetos.
Cualquier archivo obj que se quiera agregar al proyecto se recomienda ubicarlo en dicha carpeta.
	
**Clases.**

Los objetos a representar son triangulos en un plano tridimensional por lo que se necesita simular todo aquello que conforma un objeto en tres dimensiones.
	* Vertices
	* Aristas
	* Caras.
	
Estos archivos son el pilar para representar un objeto, en nuestro caso necesitamos obtener la informacion de cada objeto y guardarla en estructuras de datos.
La clase Objeto es la encargada de obtener la informacion y guardarla en colecciones.
La clase Planeta utiliza las colecciones del objeto para transportar, rotar y colocar cada vertice del objeto en la vista del plano tridimensional.
	

