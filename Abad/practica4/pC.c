#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

void Accion1()
{
    printf("Mensaje 5\n");
    kill(getppid(), 14);
}

int main()
{
    signal(14, Accion1);
    sleep(1);

    printf("Mensaje 1\n");
    kill(getppid(), 14);

    pause();

    return 0;
}


