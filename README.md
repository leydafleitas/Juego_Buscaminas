Buscaminas
Buscaminas es un juego en el que dos jugadores compiten para revelar la matriz sin encontrar una mina. El jugador que revele la matriz completa será el ganador. Este juego es ideal para poner a prueba tu lógica y razonamiento.

Ejemplo del Funcionamiento
Menú Principal

Al iniciar el juego, el usuario verá las siguientes opciones:

1) Registrar nuevo usuario: Si es la primera vez que el usuario juega, debe registrarse. Al seleccionar esta opción, el usuario debe ingresar su nombre y crear una contraseña. Si es el primer usuario en registrarse, debe registrar primero a la computadora. Puede verificar si es el primer usuario introduciendo la opción 4 para ver los usuarios registrados.

2) Iniciar sesión: Si un usuario ya registrado quiere volver a jugar, debe seleccionar esta opción e ingresar su nombre y contraseña para validarse. Una vez validados los datos, el usuario verá cinco funciones adicionales:

2.1. Visualizar la configuración del tablero: Esta opción muestra la configuración por defecto de las filas, columnas y minas del tablero.

2.2. Ajustes del tablero y el número de minas: Permite al usuario personalizar el tamaño del tablero y la cantidad de minas antes de iniciar la partida.

2.3. Ver estadísticas de los jugadores actuales: Muestra las estadísticas del usuario.

2.4. Iniciar una nueva partida de Buscaminas: Aquí comienza el juego entre el usuario y la computadora. El tablero muestra las últimas coordenadas ingresadas por el usuario. El jugador debe elegir dónde disparar. Una vez elegidas las coordenadas, hay dos opciones:

a. Revelar la coordenada seleccionada:
- Si el jugador revela una coordenada que no contiene mina y tampoco tiene minas alrededor, se revela dicha coordenada y las adyacentes.
- Si el jugador revela una coordenada con minas adyacentes, se muestran las minas adyacentes.
- Si el jugador revela una coordenada que contiene una mina, la computadora gana.

b. Colocar una bandera:
- El jugador puede colocar una bandera si deduce que hay una mina en la coordenada elegida.

Luego, es el turno de la computadora, que realiza el tiro de forma aleatoria:

a. Si la computadora revela una coordenada sin mina y sin minas alrededor, se revela dicha coordenada y las adyacentes.
b. Si la computadora revela una coordenada con minas adyacentes, se muestran las minas adyacentes.
c. Si la computadora revela una coordenada que contiene una mina, el usuario gana.
d. Para colocar una bandera, la computadora verifica las coordenadas adyacentes al objetivo seleccionado. Si las coordenadas adyacentes reveladas contienen minas, se coloca una bandera (B) en la posición seleccionada.

Después de que uno de los jugadores haya perdido, se revela la matriz mostrando la ubicación de las minas.

2.5.Volver al menú principal

3)Guardar y salir: Guarda todos los datos y cierra el programa.

4)Ver usuarios registrados: Muestra todos los usuarios registrados junto con sus estadísticas.

(Si desea ver estos pasos con imágenes, vaya a la parte de Funcionamiento del documento Buscaminas)

Las opciones más destacables

Registro de Usuario: Los jugadores pueden registrarse con un nombre y una contraseña para empezar a jugar.

Autenticación de Usuario: Los usuarios registrados pueden iniciar sesión ingresando su nombre y contraseña para acceder al juego.

Visualización de los Puntajes de Cada Usuario: Los jugadores pueden ver las estadísticas y puntajes de todos los usuarios registrados.

Disparo de la Computadora Utilizando una Lógica: La computadora realiza disparos y coloca banderas basándose en un algoritmo lógico, mejorando la experiencia de juego.

Revelación de Celdas Adyacentes: Al revelar una celda que no contiene mina, se revelan automáticamente todas las celdas adyacentes.

Ejecución del Proyecto Buscaminas

Requisitos Previos

1)Entorno de Desarrollo Integrado (IDE): Utiliza cualquier IDE que soporte C (por ejemplo, Code::Blocks, Visual Studio, CLion, etc.) o un editor de texto con soporte para compilación (por ejemplo, Visual Studio Code, Sublime Text, etc.).

2)Compilador de C: Asegúrate de tener un compilador de C instalado. Los más comunes son GCC y Clang.

Pasos para Ejecutar el Proyecto

Descargar el Código del Proyecto: Asegúrate de tener todos los archivos del proyecto Buscaminas en una carpeta.

Abrir el Proyecto en tu IDE:

Abre tu IDE.
Crea un nuevo proyecto o abre un proyecto existente.
Añade todos los archivos .c y .h del proyecto a tu proyecto en el IDE.
Configurar el Proyecto:

Configura las opciones del compilador y del enlazador según sea necesario en las configuraciones del proyecto.
Compilar y Ejecutar el Proyecto:

Utiliza las opciones del menú del IDE para compilar el proyecto (generalmente Build o Compile).
Ejecuta el proyecto (generalmente Run o Execute).

Tecnologías Utilizadas

1.Lenguaje de Programación C: Elegido por su eficiencia y control de bajo nivel.
2.IDE/Editor de Texto: CodeBlocks
3.Compilador de C: El código fue compilado usando GCC, pero cualquier compilador de C, como Clang, puede ser utilizado.

Autores
Leyda Fleitas
Braian Romero
