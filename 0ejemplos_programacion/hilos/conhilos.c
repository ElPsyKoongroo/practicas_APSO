#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void *f1();
void *f2();

main()
{
 int i,num=10;
 char letra='m';
 int *devuelto;
 pthread_t h1,h2;

 printf("Comienza la main \n");
 //f1();
 pthread_create(&h1,NULL,(void *) &f1,&num);
 //f2();
 pthread_create(&h2,NULL,(void *) &f2,&letra);
// pthread_detach(h2);
 
 pthread_join(h1,(void *) &devuelto);
 pthread_join(h2,NULL);

 sleep(2);

 printf("El hilo 1 devuelve %d\n",*devuelto);

 printf("Fin de la main\n");
}

void *f1(int *argu)
{
 int i, *retorno;
 retorno=(int *) malloc(sizeof(retorno));
 
 for (i=1; i<=3; i ++) 
 {
	printf("Soy f1 y estoy en la iteracion %d, y me pasan %d\n",i,*argu);
	sleep(1);
 }
 *retorno=6;
 pthread_exit(retorno);

}

void *f2(char *c)
{
 int i;
 for (i=10; i<=13; i ++) 
 {
	printf("Soy f2 y estoy en la iteracion %d, y me pasan %c\n",i,*c);
	sleep(1);
 }
}

