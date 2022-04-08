#include <stdio.h>
#include <signal.h>

void rutina12(){
 printf("Llega 12\n");
}

main()
{
 struct sigaction s12;
 
 s12.sa_flags=0;
 s12.sa_handler=rutina12;
 sigaction(12,&s12,NULL);
 
 while(1){
 printf("Hola\n");
 sleep(3);
 }

}
