#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

void rutina10(){
    printf("Señal 10 recivida pr41\n");
}
void rutina12(){
    printf("Señal 12 recivida pr41\n");
}


int main(void) {
    int pr42, pr43;

    struct sigaction s10, s12;

    s10.sa_flags = 0;
    s10.sa_handler = rutina10;

    s12.sa_flags = 0;
    s12.sa_handler = rutina12;

    sigaction(10, &s10, NULL);
    sigaction(12, &s12, NULL);

    fprintf(stdout, "pr41 con pid: %d. Mensaje 1\n", getpid());

    pr42 = fork();
    if (pr42 == 0) {
        execl("pr42", "pr42", NULL);
        perror("No se pudo crear pr42");
        exit(-1);
    } else {
        sleep(1);
        kill(pr42, 10);
        pause();

        pr43 = fork();
        if (pr43 == 0) {
            execl("pr43", "pr43", NULL);
            perror("No se pudo crear pr43");
            exit(-1);
        } else {
            sleep(1);
            kill(pr43, 10);
            pause();
            pause();
            fprintf(stdout, "pr41 con pid %d. Mensaje 5\n", getpid());

            return 0;
        }
    }
    
}