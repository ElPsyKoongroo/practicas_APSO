#include <stdio.h>
#include <signal.h>

void rutina12(){
 printf("Llega 12\n");
}

void rutina2(){
 printf("Llega control-c\n");
}


main()
{
 signal(12,rutina12);
 signal(2,rutina2);
 
 while(1){
   printf("Hola\n");
   sleep(3);
 }

}
