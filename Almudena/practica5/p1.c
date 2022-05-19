#include <fcntl.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void rutina10(){
    fprintf(stdout, "\n");
}

int main(){
    pid_t p2, p3;
    int file = open("fich1.txt", O_CREAT | O_TRUNC | O_WRONLY);
    int mi_pipesita[2];
    char file_str[10];

    struct sigaction s10;
    s10.sa_flags = 0;
    s10.sa_handler = rutina10;
    sigaction(10, &s10, NULL);

    sprintf(file_str, "%d", file);

    printf("Soy el proceso 1 y mi pid es: %d\n", getpid());

    int err = pipe(mi_pipesita);
    if(err == -1){
        perror("Imposible crear la pipe: ");
        exit(-1);
    }

    p3 = fork();

    if(p3 == 0){
        execl("p3.bin", "p3.bin", file_str, NULL);
        perror("No se pudo execlear p3: ");
        exit(1);
    }

    p2 = fork();

    /*
        pipes: 
            0 --> Leer
            1 --> Escribir
    */

    if(p2 == 0){
        dup2(mi_pipesita[0], 4);
        execl("p2.bin", "p2.bin", file_str, NULL);
        perror("No se pudo execlear p3: ");
        exit(1);
    }
    sleep(1);
    close(mi_pipesita[0]);
    write(mi_pipesita[1], &p3, sizeof(int));

    kill(p2, 10);
    pause();

    close(file);
    close(mi_pipesita[1]);

    return 0;
}
