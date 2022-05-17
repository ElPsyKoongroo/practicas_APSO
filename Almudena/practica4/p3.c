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
    char mensajito[50];
    int file = atoi(argv[1]);
    int chars;

    struct sigaction s10;
    s10.sa_flags = 0;
    s10.sa_handler = rutina10;
    sigaction(10, &s10, NULL);

    if(!file){
        printf("Error al parsear el archivo\n");
        exit(-1);
    }    
    pause();

    printf("Soy el proceso P3 y mi PID es: %d\n", getpid());
    chars = snprintf(mensajito, 50, "PID proceso 3: %d\n", getpid());
    write(file, mensajito, chars);

    kill(getppid(), 10);
    exit(0);
}