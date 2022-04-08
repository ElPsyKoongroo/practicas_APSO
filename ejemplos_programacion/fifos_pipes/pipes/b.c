#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

main()
{

 int valor=4855;
 
 printf("Hola soy B\n");
 sleep(3);
 write(2,&valor,sizeof(valor));
 printf("Adios\n");
 exit(0);
}
