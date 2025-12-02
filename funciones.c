#include "librerias.h"
// Definicion de las posiciones adyacentes en relacion a una celda dada
const Tupla P[8]={{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1},{1, -1}, {1, 0},{1, 1}};


// Función para registrar un nuevo usuario
void registrar_usuario(Usuario usuarios[], int *num_usuarios) {
    if (*num_usuarios >= MAX_USUARIOS) {
        printf("Se ha alcanzado el numero maximo de usuarios.\n");
        return;
    }

    Usuario nuevo_usuario;
    printf("Ingrese nombre de usuario: ");
    scanf("%s", nuevo_usuario.nombre_usuario);
    printf("Ingrese su clave: ");
    scanf("%s", nuevo_usuario.contrasena);
    nuevo_usuario.partidas_jugadas = 0;
    nuevo_usuario.partidas_ganadas = 0;
    nuevo_usuario.partidas_perdidas = 0;
    nuevo_usuario.puntaje_total = 0;

    usuarios[*num_usuarios] = nuevo_usuario;
    (*num_usuarios)++;
    printf("Usuario registrado exitosamente.\n");
    printf("\n");
}

// Función para autenticar un usuario existente
int autenticar_usuario(Usuario usuarios[], int num_usuarios) {
    char nombre_usuario[MAX_LONGITUD_NOMBRE];
    char contrasena[MAX_LONGITUD_CONTRASENA];

    printf("Ingrese nombre de usuario: ");
    scanf("%s", nombre_usuario);
    printf("Ingrese su clave: ");
    scanf("%s", contrasena);

    for (int i = 0; i < num_usuarios; i++) {
        if (strcmp(usuarios[i].nombre_usuario, nombre_usuario) == 0 &&
            strcmp(usuarios[i].contrasena, contrasena) == 0) {
            printf("Autenticacion exitosa.\n");
            printf("\n");
            return i;  // Devuelve el índice del usuario autenticado
        }
    }
    printf("Autenticacion fallida.\n");
    printf("\n");
    return -1;  // Fallo en la autenticación
}


// Función para actualizar las estadísticas de un usuario
void actualizar_estadisticas_usuario(Usuario *usuario, int partidas_jugadas, int partidas_ganadas, int partidas_perdidas, int puntaje) {
    usuario->partidas_jugadas += partidas_jugadas;
    usuario->partidas_ganadas += partidas_ganadas;
    usuario->partidas_perdidas += partidas_perdidas;
    usuario->puntaje_total += puntaje;
}

//Función para guardar usuarios en un archivo CSV:
void guardar_usuarios_a_archivo_csv(Usuario usuarios[], int num_usuarios) {
    FILE *archivo = fopen("usuarios.csv", "w");
    if (!archivo) {
        printf("Error al abrir el archivo para escribir.\n");
        return;
    }
    fprintf(archivo, "nombre_usuario,contrasena,partidas_jugadas,partidas_ganadas,partidas_perdidas,puntaje_total\n");
    for (int i = 0; i < num_usuarios; i++) {
        fprintf(archivo, "%s,%s,%d,%d,%d,%d\n",
                usuarios[i].nombre_usuario,
                usuarios[i].contrasena,
                usuarios[i].partidas_jugadas,
                usuarios[i].partidas_ganadas,
                usuarios[i].partidas_perdidas,
                usuarios[i].puntaje_total);
    }
    fclose(archivo);

}

//Función para cargar usuarios desde un archivo CSV:
void cargar_usuarios_de_archivo_csv(Usuario usuarios[], int *num_usuarios) {
    FILE *archivo = fopen("usuarios.csv", "r");
    if (!archivo) {
        //printf("Error al abrir el archivo para leer.\n");
        return;
    }
    char linea[256];
    fgets(linea, sizeof(linea), archivo);  // Leer la cabecera
    while (fgets(linea, sizeof(linea), archivo)) {
        Usuario nuevo_usuario;
        sscanf(linea, "%49[^,],%49[^,],%d,%d,%d,%d",
               nuevo_usuario.nombre_usuario,
               nuevo_usuario.contrasena,
               &nuevo_usuario.partidas_jugadas,
               &nuevo_usuario.partidas_ganadas,
               &nuevo_usuario.partidas_perdidas,
               &nuevo_usuario.puntaje_total);
        usuarios[*num_usuarios] = nuevo_usuario;
        (*num_usuarios)++;
    }
    fclose(archivo);

}

// Función para imprimir los datos de los usuarios para depuración
void imprimir_usuarios(Usuario usuarios[], int num_usuarios) {
    for (int i = 0; i < num_usuarios; i++) {
        printf("Usuario %d:\n", i + 1);
        printf("  Nombre: %s\n", usuarios[i].nombre_usuario);
        printf("  Clave: %s\n", usuarios[i].contrasena);
        printf("  Partidas Jugadas: %d\n", usuarios[i].partidas_jugadas);
        printf("  Partidas Ganadas: %d\n", usuarios[i].partidas_ganadas);
        printf("  Partidas Perdidas: %d\n", usuarios[i].partidas_perdidas);
        printf("  Puntaje Total: %d\n", usuarios[i].puntaje_total);
        printf("\n");
    }
}

//Funcion para mostrar las estadisticas de los jugadores actuales
void Mostrar_usuarios_actuales(Usuario usuarios[],int i){
    printf("Usuario %d:\n", 1);
        printf("  Nombre: %s\n", usuarios[0].nombre_usuario);
        printf("  Clave: %s\n", usuarios[0].contrasena);
        printf("  Partidas Jugadas: %d\n", usuarios[0].partidas_jugadas);
        printf("  Partidas Ganadas: %d\n", usuarios[0].partidas_ganadas);
        printf("  Partidas Perdidas: %d\n", usuarios[0].partidas_perdidas);
        printf("  Puntaje Total: %d\n", usuarios[0].puntaje_total);
        printf("\n");
        printf("\n");
        printf("Usuario %d:\n", 2);
        printf("  Nombre: %s\n", usuarios[i].nombre_usuario);
        printf("  Clave: %s\n", usuarios[i].contrasena);
        printf("  Partidas Jugadas: %d\n", usuarios[i].partidas_jugadas);
        printf("  Partidas Ganadas: %d\n", usuarios[i].partidas_ganadas);
        printf("  Partidas Perdidas: %d\n", usuarios[i].partidas_perdidas);
        printf("  Puntaje Total: %d\n", usuarios[i].puntaje_total);
        printf("\n");
        printf("\n");

}
//Funcion para que el usuario ajuste el tablero y la cantidad de minas
void ajustes_del_tablero(int *F,int *C, int *M){
    printf("Ingrese la cantidad de filas para la matriz (maximo 10):\n ");
    scanf("%d",&(*F));
    printf("Ingrese la cantidad de columnas para la matriz (maximo 10):\n ");
    scanf("%d",&(*C));
    printf("Ingrese la cantidad de minas:\n ");
    scanf("%d",&(*M));
    printf("Modificacion exitosa \n");

}
//Funcion para que el usuario vea la configuracion del tablero y cantidad de minas
void visualizar_Configuracion(int *F, int *C, int *M) {
    printf("Las configuraciones para el juego son: \n");
    printf("La cantidad de filas de la matriz es: %d \n", *F);
    printf("El cantidad de columnas de la matriz es: %d \n", *C);
    printf("La cantidad de minas son: %d \n", *M);
    printf("\n");

    // Crear una matriz para visualizar la configuracion
    char Visualizar[11][11] = {0};
    crearMatrizAux(Visualizar, *F, *C);
    imprimirMat(Visualizar, *F, *C);
    printf("\n");
}

//Funcion para mostrar el menu segundario, una vez que el usuario inicia sesion
int mostrar_menu(){
    int m;
    printf("Elige una de las opciones \n");
    printf("1. Visualizar configuracion del tablero.\n");
    printf("2. Ajustes del tablero y el numero de minas antes de comenzar una nueva partida.\n");
    printf("3. Ver estadisticas de los jugadores actuales.\n");
    printf("4. Iniciar una nueva partida de Buscaminas.\n");
    printf("5. Volver al menu principal.\n");
    scanf("%d",&m);
    printf("\n");
    return m;
}

int esvalido(Tupla *Lista, int x, int y, int tam){ //Verifica que la posicion donde se va colocar la mina este libre
    int i;                                         //ya que en la lista se guardan las coordenadas donde se van introduciendo las minas
    for (i=0; i<tam; i++) {
        if (x == Lista[i].coordenadax && y == Lista[i].coordenaday){ //Si encuentra coordenadas iguales, devuelve cero ya
            return 0;                                                //que no se puede colocar una mina ahí
        }
    }
    return 1;
}



void cargarMinasMatriz(char Mat[][11], int F, int C, int cantMinas, Tupla *L){ //Cargamos las minas, utilizando la funcion rand,
    int i = 0;                                                                 //que pertenece a la libreria stdlib.h,
    while (i < cantMinas) {                                                    //esto para que coloque las minas de forma aleatoria
        int x_aleatorio = rand() % F;
        int y_aleatorio = rand() % C;
        if (esvalido(L, x_aleatorio, y_aleatorio, i)){ //Una vez que se verifique que es valido, carga las coordenadas en la lista y ubica la mina en la matriz
            L[i].coordenadax = x_aleatorio;
            L[i].coordenaday = y_aleatorio;
            Mat[x_aleatorio][y_aleatorio] = '*'; //'*'->representa la mina
            i++;
        }
    }
}

void valoresadyacentes(char Mat[][11], int F, int C, int cantMinas, Tupla *L){
    int i,k,x,y,cx,cy;

    for (i=0; i<cantMinas; i++){ //Buscamos en la lista L, las coordenadas de las minas ya colocadas
        x=L[i].coordenadax;
        y=L[i].coordenaday;
        for (k=0; k<8; k++) {
            cx=x+P[k].coordenadax; //Vemos los alrededores, utilizando la lista P
            cy=y+P[k].coordenaday;
            if (cx>=0 && cx<F && cy>=0 && cy<C) { //Si esta dentro de la matriz esa coordenada y no hay una mina en esa posicion, se aumenta de numero
                if (Mat[cx][cy] != '*'){
                    Mat[cx][cy]++;
                }
            }
        }
    }
}

void crearMatrizAux(char Mat[][11], int F,int C){
     // Etiquetas de columnas (números)
    Mat[0][0] = ' ';  // La esquina superior izquierda se deja en blanco para separar las etiquetas de fila y columna.
    char valor = '0'; // Se inicializa una variable 'valor' con el carácter '0'.
    for (int j = 1; j < C; j++) { // Se itera a través de las columnas comenzando desde la primera columna después de la esquina superior izquierda.
        Mat[0][j] = valor; // Se asigna el valor actual a la primera fila de la matriz.
        valor++; // Se incrementa el valor para la siguiente columna.
    }

    // Etiquetas de filas (letras)
    for (int i = 1; i < F; i++) { // Se itera a través de las filas comenzando desde la segunda fila.
        Mat[i][0] = 'A' + (i - 1); // Se asigna una letra correspondiente a la fila. 'A' se incrementa con el índice de la fila.
    }

    // Inicializar el resto de la matriz con '.'
    for (int i = 1; i < F; i++) { // Se itera a través de las filas comenzando desde la segunda fila.
        for (int j = 1; j < C; j++) { // Se itera a través de las columnas comenzando desde la segunda columna.
            Mat[i][j] = '.'; // Se asigna el carácter '.' a cada celda de la matriz, indicando una celda vacía.
        }
    }
}

//Funcion utilizada para mostrar los cuadrados de la matriz donde el usuario o la computadora van disparando
void mostrardisparos(char Mat[][11], char Maux[][11], int F, int C, int c, char f, int *perdio){
    int fila = f - 'A';
    int columna = c; // convierte las coordenadas de la matriz auxiliar a coordenadas de la matriz original
    int k, cx, cy;
    // Hay 3 opciones al disparar la matriz
    // Opción 1: no hay minas adyacentes, por lo que se revelan los cuadros adyacentes
    if (Mat[fila][columna] == '0'){
        for (k = 0; k < 8; k++){
            cx = fila + P[k].coordenadax;
            cy = columna + P[k].coordenaday;
            if (cx >= 0 && cx < F && cy >= 0 && cy < C){
                Maux[cx + 1][cy + 1] = Mat[cx][cy];
            }
        }
        Maux[fila + 1][columna + 1] = Mat[fila][columna];
    }
    // Opción 2: es una mina
    else if (Mat[fila][columna] == '*'){
        Maux[fila + 1][columna + 1] = Mat[fila][columna];
        *perdio = 1;
    }
    // Opción 3: tiene una mina alrededor
    else {
        Maux[fila + 1][columna + 1] = Mat[fila][columna];
    }
}

//Funcion para que la computadora haga disparos inteligentes
void disparocomputadora(char Mat[][11], char Maux[][11], int F, int C, int *perdio){
    int x_disparo, y_disparo;
    do {
        x_disparo = rand() % F;
        y_disparo = rand() % C;
    } while (Maux[x_disparo + 1][y_disparo + 1] != '.'); // Nos aseguramos de no disparar en una celda que ya fue revelada

    // Opción de tener una posible mina
    int i, dx, dy;
    // Definimos estas tuplas que tienen las coordenadas de acuerdo a un lado adyacente de x_disparo e y_disparo
    Tupla horiz_arriba[3] = {P[0], P[1], P[2]};
    Tupla horiz_abajo[3] = {P[5], P[6], P[7]};
    Tupla verti_der[3] = {P[2], P[4], P[7]};
    Tupla verti_izq[3] = {P[0], P[3], P[5]};
    int cont1 = 0, cont2 = 0, cont3 = 0, cont4 = 0;

    // Primero verificamos si ya se revelaron las coordenadas horizontales superiores y si tienen mina alrededor
    for (i = 0; i < 3; i++) {
        dx = x_disparo + horiz_arriba[i].coordenadax;
        dy = y_disparo + horiz_arriba[i].coordenaday;
        if (dx >= 0 && dx < F && dy >= 0 && dy < C) {
            if (Maux[dx + 1][dy + 1] != '.' && Maux[dx + 1][dy + 1] != '0') {
                cont1++;
            }
        }
    }
    // Verificamos si ya se revelaron las coordenadas horizontales inferiores y si tienen mina alrededor para aumentar el contador correspondiente
    for (i = 0; i < 3; i++) {
        dx = x_disparo + horiz_abajo[i].coordenadax;
        dy = y_disparo + horiz_abajo[i].coordenaday;
        if (dx >= 0 && dx < F && dy >= 0 && dy < C) {
            if (Maux[dx + 1][dy + 1] != '.' && Maux[dx + 1][dy + 1] != '0') {
                cont2++;
            }
        }
    }
    // Verificamos si ya se revelaron las coordenadas verticales de la derecha y si tienen mina alrededor para aumentar el contador correspondiente
    for (i = 0; i < 3; i++) {
        dx = x_disparo + verti_der[i].coordenadax;
        dy = y_disparo + verti_der[i].coordenaday;
        if (dx >= 0 && dx < F && dy >= 0 && dy < C) {
            if (Maux[dx + 1][dy + 1] != '.' && Maux[dx + 1][dy + 1] != '0') {
                cont3++;
            }
        }
    }
    // Verificamos si ya se revelaron las coordenadas verticales de la izquierda y si tienen mina alrededor para aumentar el contador correspondiente
    for (i = 0; i < 3; i++) {
        dx = x_disparo + verti_izq[i].coordenadax;
        dy = y_disparo + verti_izq[i].coordenaday;
        if (dx >= 0 && dx < F && dy >= 0 && dy < C) {
            if (Maux[dx + 1][dy + 1] != '.' && Maux[dx + 1][dy + 1] != '0') {
                cont4++;
            }
        }
    }

    // Si algunos de esos contadores es igual a 3, significa que la coordenada que selecciono la computadora contiene una posible mina
    if (cont1 == 3 || cont2 == 3 || cont3 == 3 || cont4 == 3) {
        Maux[x_disparo + 1][y_disparo + 1] = 'B';  // Marca la celda como posible mina
    } else {
        char f2 = 'A' + x_disparo;
        mostrardisparos(Mat, Maux, F, C, y_disparo, f2, perdio);
    }
    printf("Las coordenadas donde tiro la computadora son: %c %d\n",('A'+x_disparo),(y_disparo));
    printf("\n");
}

//Funcion para imprimir la Matriz
void imprimirMat(char Mat[][11], int F, int C){
    for (int i = 0; i < F; i++) {
        for (int k = 0; k < C; k++) {
            printf("%c ", Mat[i][k]);
        }
        printf("\n");
    }
}

//Funcion para cargar la matriz completa a la matriz auxiliar una vez que perdieron
void cargardatos(char Mat[][11], char Maux[][11], int F, int C){
    int i,k;
    for (i=0;i<F;i++){
        for (k=0;k<C;k++){
            Maux[i+1][k+1]=Mat[i][k];
        }
    }
}

//Funcion para iniciar el juego
void jugar(Usuario usuarios[] ,int F, int C,int M, int *perdio,int indice){

    Tupla L[M]; //Lista que almacena las coordenadas de las minas ubicadas

    char Mat[11][11];    //Creamos una Matriz
    for (int i = 0; i < F; i++) {
        for (int j = 0; j < C; j++){
            Mat[i][j] = '0';
        }
    }

    srand(time(NULL)); // Inicializa la semilla una vez

    cargarMinasMatriz(Mat, F, C, M, L);   //Cargamos las minas y los valores adyacentes a la Matriz creada
    valoresadyacentes(Mat, F, C, M, L);


    char Maux[11][11];                   //Creamos una Matriz Auxiliar
    for ( int i = 0; i < F; i++) {
        for ( int j = 0; j < C; j++){
            Maux[i][j] = '0';
        }
    }
    printf("Tu mision es despejar el campo sin detonar ninguna mina.\n");
    printf("Escribe las coordenadas de las celdas para descubrir numeros que te indicaran cuantas minas hay cerca. Buena suerte y diviertete!\n");
    printf("QUE EMPIEZE EL JUEGO!! \n\n");
    crearMatrizAux(Maux,F+1,C+1);
    imprimirMat(Maux,F+1,C+1);

    printf("\n");

    int turnos = 0, columna; // Definimos la variable turnos igual a 0, como el usuario siempre es el que empieza
    char fila;               //cada vez que turnos sea par es turno del usuario
    int opcion;
    while (turnos < F * C){
        if (turnos % 2 == 0){
            do {
                printf("\n");
                printf("Ingrese las coordenadas donde desea disparar:\n");
                scanf(" %c %d", &fila, &columna);
            } while (!(columna >= 0 && columna < C && fila >= 'A' && fila < 'A' + F && Maux[fila - 'A' + 1][columna + 1] == '.'));
            printf("Tiene dos opciones:\n");
            printf("Opcion 1: Realizar el disparo:\n");
            printf("Opcion 2: Colocar la bandera:\n");
            scanf("%d",&opcion);
            if (opcion==1){
                mostrardisparos(Mat, Maux, F, C, columna, fila, perdio);
                imprimirMat(Maux, F + 1, C + 1);
                if (*perdio == 1){
                printf("Explotaste una mina! Perdiste\n\n");
                printf("Esta es la matriz descubierta:\n");
                cargardatos(Mat, Maux, F, C);
                imprimirMat(Maux, F + 1, C + 1);
                printf("\n");
                //Actualizamos las estadisticas de ambos jugadores  Gana la computadora
                actualizar_estadisticas_usuario(&usuarios[0] , 1, 1, 0, 5);  //Estadistica de la computadora
                actualizar_estadisticas_usuario(&usuarios[indice] , 1, 0, 1, 0);   //Estadistica del usuario
                printf("La computadora ha ganado 5 puntos!\n ");
                printf("\n");
                break;
                }
            }else{
                Maux[(fila-'A')+1][columna+1]='B';
                imprimirMat(Maux,F+1,C+1);
            }
        }
        else {
            printf("\n");
            printf("Turno de la computadora\n");
            disparocomputadora(Mat, Maux, F, C, perdio);
            imprimirMat(Maux, F + 1, C + 1); // Asegúrate de que la matriz se imprime después del disparo de la computadora
            if (*perdio == 1){
                printf("\n");
                printf("La computadora exploto una mina! Ganaste!!\n\n");
                printf("Esta es la matriz descubierta:\n");
                cargardatos(Mat, Maux, F, C);
                imprimirMat(Maux, F + 1, C + 1);
                printf("\n");
                //Actualizamos las estadisticas de ambos jugadores  Gana el usuario
                actualizar_estadisticas_usuario(&usuarios[0] , 1, 0, 1, 0);         //Estadistica de la computadora
                actualizar_estadisticas_usuario(&usuarios[indice] , 1, 1, 0, 5);    //Estadistica del usuario
                printf("Felicitaciones, Haz ganado 5 puntos!! \n");
                printf("\n");
                break;
            }
        }
        turnos++;
    }
    if(perdio==0){
        if((turnos-1)%2==0){
            printf("Ganaste la partida!\n");
            printf("Felicitaciones, Haz ganado 5 puntos!! \n");
            actualizar_estadisticas_usuario(&usuarios[0] , 1, 0, 1, 0);         //Estadistica de la computadora
            actualizar_estadisticas_usuario(&usuarios[indice] , 1, 1, 0, 5);    //Estadistica del usuario
        }else{
            printf("La computadora gano la partida! \n");
            actualizar_estadisticas_usuario(&usuarios[0] , 1, 1, 0, 5);  //Estadistica de la computadora
            actualizar_estadisticas_usuario(&usuarios[indice] , 1, 0, 1, 0);   //Estadistica del usuario
        }
    }
}
