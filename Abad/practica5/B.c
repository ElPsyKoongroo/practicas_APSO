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

int main(void){
    int numero, fifito, segunditos;
    pid_t c_pid;
    fifito = open("fifito", O_RDONLY);

    if (fifito == -1){
        fprintf(stderr, "Error al abrir la fifito: ");
        perror("");
        exit(-1);
    }

    read(4,&segunditos,sizeof(numero));

    read(fifito,&c_pid,sizeof(c_pid));

    sleep(2);
    fprintf(stdout, "Tercer mensaje\n");

    sleep(segunditos);

    fprintf(stdout, "Cuarto mensaje\n");
    kill(c_pid, 22);
    close(fifito);
    exit(0);
}