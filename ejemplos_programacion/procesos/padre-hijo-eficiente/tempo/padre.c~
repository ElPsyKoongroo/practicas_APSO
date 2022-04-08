#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main()
{
 
 int vpid;
 printf("Hola, soy el padre con pid %d\n",getpid());
 
 vpid=fork();
 if(vpid==0) 
 {  
    execl("hijo","hijo",NULL);
    perror("El execl de hijo no se pudo completar ");
    exit(-1);
 }else if(vpid==-1) perror("Error de fork ");
 
 
 printf("Hola, soy el padre (%d) y termino\n",getpid());

}
