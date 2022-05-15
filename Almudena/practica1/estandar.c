#include<estandar.h>

void printear(char* dato){
    write(STDOUT_FILENO, dato, sizeof(char));
}

void cin(char* dato, size_t nbytes){
    read(STDIN_FILENO, dato, nbytes);
}