#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>                     
                     

main()
{
 
 int f1;
 float dato=3.1415;

 f1=open("fifo1",O_WRONLY);

 printf("Hola soy c\n");
 sleep(2);
 write(f1,&dato,sizeof(dato));
 printf("Fin de c\n");

 // AQUI PUEDE HABER MAS WRITES, ANTES DEL CLOSE

 close(f1);
}
