#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>                     

void r13()
{
 printf("Ha llegado SIGPIPE\n");
}                     

main()
{
 
 int f1;
 float dato=3.1415;

 signal(13,r13);
 f1=open("fifo1",O_WRONLY);

 printf("Hola soy c\n");
 sleep(7);
 write(f1,&dato,sizeof(dato));
 printf("Fin de c\n");
// sleep(2);
// write(f1,&dato,sizeof(dato));

 // AQUI PUEDE HABER MAS WRITES, ANTES DEL CLOSE

 close(f1);
}
