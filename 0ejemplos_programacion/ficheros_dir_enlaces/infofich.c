#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <time.h>
#include <stdlib.h>

main(int argc, char *argv[])
{

 struct stat info;
/*
 if (argc<2){
  printf("Se necesita un parametro\n");
  exit(-1);
 }
 
 if(stat(argv[1],&info)==-1)
 { 
  perror("stat");
  exit(-1);
 } 
*/  
 stat("infofich.c",&info);

 printf("El i-nodo es %d\n",info.st_ino);
 printf("El propietario  es %d\n",info.st_uid);
 printf("El tamano  es %d\n",info.st_size);
 printf("Se creo en : %s\n",ctime(&info.st_mtime));
 if(info.st_mode & 00700) printf("Tiene lectura para el propietario\n");
 if(S_ISREG(info.st_mode)) printf("Es un fichero regular \n");
 if(S_ISDIR(info.st_mode)) printf("Es un directorio \n");
}
       