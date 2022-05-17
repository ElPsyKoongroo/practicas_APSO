#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <stdlib.h>

main()
{
 int tubo[2],pidb,numero,retorno;
 
 printf("hola soy A\n");
 pipe(tubo);
 
 pidb=fork();
 if(pidb==0)
 {
   close(2);
   dup(tubo[1]);
   execl("b","b",0);
   printf("error de execl: b no se crea\n");
   exit(-1);
 }
 close(tubo[1]);
 printf("Ya soy padre \n");
 read(tubo[0],&numero,sizeof(numero));
 printf("Mi hijo me manda %d\n",numero);
 wait(&retorno);

}
