#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void rutina10(){
    fprintf(stdout, "\n");
}

int main(int argc, char* argv[]){
    int file = atoi(argv[1]);
    int fifito;
    char mensajito[50];
    pid_t p3, p2 = getpid();
    mkfifo("fifo_p3", 0777);

    struct sigaction s10;
    s10.sa_flags = 0;
    s10.sa_handler = rutina10;
    sigaction(10, &s10, NULL);

    pause();
    
    
    printf("Soy p2 y mi pid es: %d\n", getpid());

    int chars = sprintf(mensajito, "PID proceso 2: %d\n", getpid());
    write(file, mensajito, chars);

    read(4, &p3, sizeof(int));
    kill(p3, 10);


    fifito = open("fifo_p3", O_WRONLY);
    write(fifito, &p2, sizeof(int));
    if(fifito == -1){
        perror("Error al abrir la fifo");
    }

    
    exit(0);
}