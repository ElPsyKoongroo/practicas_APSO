#include <stdio.h>
#include <unistd.h>

main()
{
 int vpid;
 
 printf("Soy el proceso %d: Comienza la ejecucion y voy a lanzar un fork\n",getpid());
 vpid=fork();
 printf("Soy el proceso %d, el fork devuelve %d\n",getpid(),vpid);
 printf("Soy el proceso %d, mi padre es %d: Termino la ejecucion\n",getpid(),getppid());
}
