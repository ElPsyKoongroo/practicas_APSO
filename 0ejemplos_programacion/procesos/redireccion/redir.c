#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{
 printf("Me redirecciono a f1\n");
 close(1);
 open("f1",O_WRONLY|O_CREAT,0600);
 printf("Esto debe salir en el fichero f1\n");
}