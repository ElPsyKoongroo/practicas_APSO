#include <stdio.h>
#include <unistd.h>

main()
{
 int vpid;
 
 printf("Soy el proceso %d: Comienza la ejecucion y voy a lanzar un fork\n",getpid());
 vpid=fork();
 if(vpid==0)
     printf("Soy el Hijo con pid %d, mi padre es %d porque el fork devuelve %d\n",getpid(),getppid(),vpid);
 else
     printf("Soy el proceso %d, soy el padre, y el fork devuelve  %d\n",getpid(),vpid);
}
