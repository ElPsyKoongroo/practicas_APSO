#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <signal.h>

/*
C
A
B
B
C
A
*/

int pidB, pidC;

void Accion3()
{
    printf("Mensaje 6\n");
}

void Accion2()
{
    kill(pidC, 14);
    signal(14, Accion3);
}

void Accion1()
{
    printf("Mensaje 2\n");
    signal(14, Accion2);
    kill(pidB, 14);
}


int main()
{
    signal(14, Accion1);

    int pidAux;

    printf("Iniciando\n");

    pidAux = fork();

    if(pidAux == 0)
    {
        execl ("pB", "pB", NULL);
        perror("Error al abrir pB\n");
        exit(0);
    }
    pidB = pidAux;

    pidAux = fork();

    if(pidAux == 0)
    {
        execl ("pC", "pC", NULL);
        perror("Error al abrir pC\n");
        exit(0);
    }
    pidC = pidAux;

    pause();
    pause();
    pause();
    
    printf("FIN\n");

    return 0;
}

