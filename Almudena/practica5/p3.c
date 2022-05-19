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
    pid_t p2;
    char mensajito[50];
    
    struct sigaction s10;
    s10.sa_flags = 0;
    s10.sa_handler = rutina10;
    sigaction(10, &s10, NULL);

    pause();

    int fifito = open("fifo_p3", O_RDONLY);
    read(fifito, &p2, sizeof(p2));

    printf("Soy el proceso P3 y mi PID es %d\n", getpid());

    int chars = sprintf(mensajito, "PID proceso 3: %d\n", getpid());
    write(file, mensajito, chars);

    chars = sprintf(mensajito, "El pid de mi hermano es %d\n", p2);
    write(file, mensajito, chars);

    kill(getppid(), 10);
    unlink("fifo_p3");
    exit(0);
}
