#include <stdio.h>

main()
{
 printf("Soy el proceso %d: Comienza la ejecucion y voy a lanzar un fork\n",getpid());
 fork();
 printf("Soy el proceso %d, mi padre es %d: Termino la ejecucion\n",getpid(),getppid());
}

