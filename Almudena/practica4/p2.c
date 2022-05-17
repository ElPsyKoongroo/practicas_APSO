#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<signal.h>

void rutina10(){
    fprintf(stdout, "\n");
}


int main(int argc, char* argv[]){
    int file = atoi(argv[1]);
    char mensajito[50];
    int chars;

    struct sigaction s10;
    s10.sa_flags = 0;
    s10.sa_handler = rutina10;
    sigaction(10, &s10, NULL);

    if(!file){
        printf("Error al parsear el archivo\n");
        exit(-1);
    }

    pid_t p3 = atoi(argv[2]);
    if(!p3){
        printf("Error al parsear la PID\n");
        exit(-1);
    }
    pause();
    printf("Soy el proceso 2 y mi pid es: %d\n", getpid());
    chars = snprintf(mensajito, 50, "PID proceso 2: %d\n", getpid());

    write(file, mensajito, chars);
    chars = snprintf(mensajito, 50, "El PID de mi hermano es: %d\n", p3);
    write(file, mensajito, chars);

    kill(p3, 10);
    exit(0);
}