#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>                     
                     

main()
{
 
 int f1;
 float dato;
 
 f1=open("fifo1",O_RDONLY);

 printf("Hola soy b\n");
 read(f1,&dato,sizeof(dato));
 printf("Fin de B, y leyo %f\n",dato);
 
 // AQUI PUEDE HABER MAS READS, ANTES DEL CLOSE
 
 close(f1);
}
