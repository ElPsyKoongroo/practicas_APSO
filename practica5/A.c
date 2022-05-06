#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(void) {
    int pipas_reyes[2], vpidb, vpidc, retorno, numerito = 2;
    mkfifo("fifito", 0777);
    int err = pipe(pipas_reyes);
    if (err == -1){
        perror("Imposible crear la pipe: ");
        return -1;
    }

    vpidb = fork();
    if (vpidb == 0) {
        dup2(pipas_reyes[0], 4);
        execl("B", "B", NULL);
        perror("no se puede ejecutar B: ");
        exit(-1);
    } else if (vpidb == -1) {
        fprintf(stderr, "No se puede forkear\n");
    }

    vpidc = fork();
    if (vpidc == 0) {
        execl("C", "C", NULL);
        perror("no se puede ejecutar B: ");
        exit(-1);
    } else if (vpidb == -1) {
        fprintf(stderr, "No se puede forkear\n");
    }

    close(pipas_reyes[0]);
    write(pipas_reyes[1], &numerito, sizeof(numerito));


    sleep(1);
    fprintf(stdout, "El segundo mensaje\n");
    wait(&retorno);
    fprintf(stdout, "El ultimo mensaje\n");
    close(pipas_reyes[1]);
    return 0;
}