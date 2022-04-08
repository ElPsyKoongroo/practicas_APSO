#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>        

main()
{

int vpidb,vpidc,retorno;

mkfifo("fifo1",0777);    

vpidb=fork();
if(vpidb==0) {
  execl("b","b",0);
  perror("no se puede ejecutar b");
  exit(-1);
}
else if(vpidb==-1) printf("Imposible hacer el fork\n");;

vpidc=fork();
if(vpidc==0) {
  execl("c","c",0);
  perror("no se puede ejecutar c");
  exit(-1);
}
else if(vpidc==-1) printf("Imposible hacer el fork\n");;


wait(&retorno);
wait(&retorno);

printf("Fin de A\n");

//unlink("fifo1");
}
