#include<ficheros.h>

int escribir_fichero(int fileno, char* dato){
    return write(fileno, dato, sizeof(char));
}

int leer_fichero(int fileno, char* dato){
    return read(fileno, dato, sizeof(char));
}