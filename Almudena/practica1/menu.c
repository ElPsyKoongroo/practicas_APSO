#include<stdlib.h>
#include<stdio.h>
#include<unistd.h>
#include <fcntl.h>
#include<ficheros.h>
#include<estandar.h>

char datos[10];

int menu(){
    int opcion = 0;
    printf(
        "1. Leer datos desde teclado\n"
        "2. Leer datos desde fichero\n"
        "3. Visualizar datos en pantalla\n"
        "4. Volcar datos a fichero\n"
        "5. Salir\n"
    );
    scanf("%d", &opcion);
    return opcion;
}


void caso1(){
    char valor_introducido[2] = {};
    for(int i = 0; i<10 && valor_introducido[0] != '0'; ++i){
        printf("Introduce un valor: ");
        fflush(stdout);
        read(STDIN_FILENO, valor_introducido, sizeof(char)*2);
    }
}


void caso2(){
    char nombre_fichero[50] = {};
    cin(nombre_fichero, sizeof(char)*50);


    char dato = 'a';
    int file_desc = open(nombre_fichero, S_IRUSR);
    int bytes_read = 1;


    if(file_desc == -1){
        perror("No se ha podido abrir el archivo.");
        exit(-1);
    }

    for(int i = 0; i<10 && bytes_read != 0; ++i){
        bytes_read = leer_fichero(file_desc, &dato);
        datos[i] = dato;
    }
    close(file_desc);
}


void caso3(){
    for(int i = 0; i<10 && datos[i] != '0'; i++){
        printear(&datos[i], sizeof(char));
    }
    printf("\n");
}



void caso4(){
    char nombre_fichero[50] = {};
    printf("Introduce el nombre del fichero: ");
    cin(nombre_fichero, sizeof(char)*50);

    int file_desc = open(nombre_fichero, S_IWUSR | O_CREAT);

    if(file_desc == -1){
        printf("No se ha podido abrir el archivo\n");
        exit(-1);
    }

    for(int i = 0; i<10; ++i){
        escribir_fichero(file_desc, &datos[i]);
    }
    close(file_desc);
}

int main(){
    int opcion = 0;
    do{
        opcion = menu();
        switch (opcion){
            case 1:
                caso1();
                break;
            case 2:
                caso2();
                break;
            case 3:
                caso3();
                break;
            case 4:
                caso4();
                break;
            case 5:

            default:
                opcion = 5;
                break;
        }
    }while(opcion != 5);
    return EXIT_SUCCESS;
}