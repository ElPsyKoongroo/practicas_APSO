#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>

main()
{
 
 int vpid;
 printf("Hola, soy el padre con pid %d\n",getpid());
 
 vpid=fork();
 if(vpid==0) 
 {  
    close(1);
    open("F1.hijo",O_WRONLY|O_CREAT,0600);   
    execl("hijo","hijo",NULL);
    perror("El execl de hijo no se pudo completar ");
    exit(-1);
 }else if(vpid==-1) perror("Error de fork ");
 
 
 printf("Hola, soy el padre (%d) y termino\n",getpid());

}
