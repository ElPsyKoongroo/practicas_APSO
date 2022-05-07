#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
    int proc;
    pid_t padre = getpid();
    printf("Se acaba de iniciar el proceso A con PID %d\n", getpid());

    proc = fork();

    if (!proc) {
        printf("Se acaba de iniciar el proceso B con PID %d, y el padre A: %d\n",getpid(), getppid());
        exit(0);
    }

    proc = fork();
    
    if (!proc) {
        close(1);
        open("infoc", O_WRONLY | O_CREAT | O_TRUNC, 0666);
        char ppid[10];
        snprintf(ppid, 10, "%d\0", padre);
        execl("pC", "pC", ppid, NULL);

        printf("Error al ejecutrar proceso C");
        exit(0);
    }
    printf("Creado C con PID %d\n", proc);
    sleep(2);
}