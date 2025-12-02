#include "librerias.h"
int main() {
    printf(" Bienvenido a **BUSCAMINAS**!! Preparate para poner a prueba tu ingenio y habilidad.\n ");
    printf("¿Estas listo para despejar el campo de minas? Buena suerte!! \n\n");
    Usuario usuarios[MAX_USUARIOS];
    int num_usuarios = 0;
    int opcion;
    int F=7; //Numero de filas definido por defecto
    int C=7; //Numero de columnas definido por defecto
    int M=5;  //Numero de minas definido por defecto
    int perdio=0;

    // Cargar los usuarios existentes desde el archivo CSV al iniciar el programa
    cargar_usuarios_de_archivo_csv(usuarios, &num_usuarios);
    printf("Elige una de las opciones. \n");
    while (1) {
        printf("1. Registrar nuevo usuario\n2. Iniciar sesion\n3. Guardar y Salir\n4. Mostrar Usuarios\nIngrese su opcion: ");
        scanf("%d", &opcion);
        printf("\n");

        if (opcion == 1) {
            registrar_usuario(usuarios, &num_usuarios);
        } else if (opcion == 2) {
            int indice_usuario = autenticar_usuario(usuarios, num_usuarios);
            if (indice_usuario != -1) {
                    int k;
                     do{
                         k=mostrar_menu();
                         if (k==1){
                            visualizar_Configuracion(&F,&C,&M);

                         }else if(k==2){
                            ajustes_del_tablero(&F,&C,&M);

                         }else if(k==3){
                            Mostrar_usuarios_actuales(usuarios,indice_usuario);
                         }else if(k==4){
                            jugar(usuarios,F,C,M,&perdio,indice_usuario);
                         }else if(k==5){
                            printf("Gracias por Jugar!! \n");
                            k=-1;
                            printf("\n");
                         }else{
                            printf("Opcion invalida. Por favor intente nuevamente.\n");
                             }


                      }while(k!=-1);


            }
        } else if (opcion == 3) {
            // Guardar los usuarios en el archivo CSV antes de salir del programa
            guardar_usuarios_a_archivo_csv(usuarios, num_usuarios);
            printf("Gracias por jugar a **Buscaminas**!! Esperamos que hayas disfrutado desafiando tu mente con nuestros campos minados.\n");
            printf("Vuelve pronto para mas diversion explosiva!!\n");
            break;
        } else if (opcion == 4) {
            // Imprimir los usuarios para depuración
            imprimir_usuarios(usuarios, num_usuarios);


        }else {
            printf("Opcion invalida. Por favor intente nuevamente.\n");
        }
    }
    return 0;
}
