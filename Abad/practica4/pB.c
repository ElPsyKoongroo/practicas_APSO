#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

void Accion1()
{
    printf("Mensaje 3 (Sleep 3 Segundos)\n");
    sleep(3);
    printf("Mensaje 4\n");
    kill(getppid(), 14);
}

int main()
{
    signal(14, Accion1);
    pause();

    return 0;
}

