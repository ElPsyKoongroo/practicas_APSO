#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int main()
{
    int parent = getppid();

    if(parent)
    {
        printf("Se acaba de iniciar el proceso C con PID %d\n", getpid());
    }
    else
    {
        printf("Se acaba de iniciar el proceso C con PID %d\n, y el padre A: %d", getpid(), parent);
    }
    return 0;
}