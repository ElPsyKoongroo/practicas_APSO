#include <errno.h>
#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

void rutina1(){
    fprintf(stdout, "[ B dise que bien fresco ]\n");
}

int main(void){
    int fifito;
    pid_t pid = getpid();
    struct sigaction s1;

    s1.sa_flags=0;
    s1.sa_handler=rutina1;
    sigaction(22,&s1,NULL);

    fifito = open("fifito", O_WRONLY);
    if (fifito == -1){
        perror("Error al abrir fifito: ");
        exit(-1);
    }
    
    write(fifito, &pid, sizeof(pid_t));

    fprintf(stdout, "Primer mensaje\n");
    pause();
    fprintf(stdout, "Quinto mensaje\n");
    close(fifito);
    exit(0);
}