#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void rutina12(){
 printf("Llega 12\n");
}

void rutina2(){
 printf("Llega control-c\n");
}


main()
{
 int vpid;
 
 signal(12,rutina12);
 signal(2,rutina2);

 vpid=fork();
 if(vpid==0) {
   execl("hijo_manda","hijo_manda",0);
   perror("Error de execl:");
   exit(-1);
  }
  else if (vpid==-1) perror ("Error fork:");

 
 while(1){
   printf("Hola\n");
   sleep(3);
   //pause();
 }

}
