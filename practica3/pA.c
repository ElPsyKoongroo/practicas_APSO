#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    printf("Se acaba de iniciar el proceso A con PID %d\n", getpid());

    int proc = fork();

    if(!proc)
    {
        printf("Se acaba de iniciar el proceso B con PID %d\n, y el padre A: %d", getpid(), getppid());
        exit(0);
    }
    printf("Creado B con PID %d\n", proc);

    proc = fork();

    if(!proc)
    {
        close(1);
        open("infoc", O_WRONLY | O_CREAT, 0666);

        execl("pC", "pC", NULL);

        printf("Error al ejecutrar proceso C");
        exit(0);
    }
    printf("Creado C con PID %d\n", proc);
}