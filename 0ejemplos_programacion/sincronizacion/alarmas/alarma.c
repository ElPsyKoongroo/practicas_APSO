#include <stdio.h>
#include <signal.h>

int fin=0;

void rutina14(){
 printf("Llega 14 que es una alarma\n");
 fin=1;
}

main()
{
 
 int holas=0;
 signal(14,rutina14);

 alarm(5);

// alarm(0); 
 
 sleep(1);

 while(fin==0){

   printf("Hola\n");
   printf("hola ...\n");
   holas=holas+2;
 }

 printf("Numero de holas: %d\n",holas);
}
