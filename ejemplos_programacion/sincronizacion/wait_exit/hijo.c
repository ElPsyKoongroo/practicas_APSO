#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h> 

main()
{
 printf("Soy el hijo y mi pid es %d\n",getpid());
 sleep(35);
 printf("Finaliza el hijo\n");
 exit(3);
}
