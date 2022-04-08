#include <stdio.h>

void f1();
void f2();

main()
{
 printf("Comienza la main \n");
 f1();
 f2();
 printf("Fin de la main\n");
}

void f1()
{
 int i;
 for (i=1; i<=3; i ++) 
 {
	printf("Soy f1 y estoy en la iteracion %d\n",i);
	sleep(1);
 }
}

void f2()
{
 int i;
 for (i=10; i<=13; i ++) 
 {
	printf("Soy f2 y estoy en la iteracion %d\n",i);
	sleep(1);
 }
}

