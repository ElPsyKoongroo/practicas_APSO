#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <stdlib.h>

main(int argc, char *argv[])
{
 
 DIR *dire;

 struct dirent *entrada;
 
 entrada=(struct dirent *) malloc(sizeof(struct dirent));

  if (argc<2){ 
  printf("Se necesita un parametro\n");
  exit(-1);
 }

 dire=opendir(argv[1]);

 //dire=opendir(".");
 
 if(dire==NULL) perror("opendir");
 else {
  rewinddir(dire);
  
  entrada=readdir(dire); 

  while(entrada!=NULL)
  {
     printf("El nombre de la entrada es %s, y su i-nodo es %d, y el tipo es %d\n",entrada->d_name,entrada->d_ino,entrada->d_type); 
   entrada=readdir(dire); 
  } 
  
  closedir(dire);
 }
}
      