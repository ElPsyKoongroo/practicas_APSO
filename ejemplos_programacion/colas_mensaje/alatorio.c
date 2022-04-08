#include <stdio.h>
#include <stdlib.h>
 

main()
{
 int aleatorio,i;

   srand(getpid()); //inicializa la semilla del rand
 
   for (i=1;i<4;i++){

    aleatorio=rand()%4+1; //numero aleatorio entre 1 y 4

    sleep(aleatorio);

    printf("numero: %d\n",aleatorio);
    if(aleatorio%2 == 0) printf("Es par\n");
    else printf("Es impar\n");
    
  }

}
