#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>        

main()
{

int vpid,retorno,elhijo;

printf("Hola, soy el padre y creo a mi hijo\n");

vpid=fork();
if(vpid==0) {
  execl("hijo","hijo",0);
  perror("no se puede ejecutar otro\n");
  exit(-1);
}
else if(vpid==-1) printf("Imposible hacer el fork\n");;

printf("El hijo %d esta creado y espero a que termine\n",vpid);
elhijo=wait(&retorno);
printf("La se�al vale %d\n",retorno & 0x7F);
printf("El valor vale %d\n",(retorno>>8) & 0xFF);

printf("Termina el padre y ya termino el hijo %d\n",elhijo);
}
