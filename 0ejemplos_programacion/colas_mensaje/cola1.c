#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <sys/msg.h>

struct Mensaje{
 long tipo;
 int pid;
};

int main()
{
 struct Mensaje m1, m2;
 key_t nombrecola;
 int idcola;

 m1.tipo=1;
 m1.pid=getpid();

 printf("Soy cola 1 con pid %d\n",getpid());
 //Obtengo el nombre de la cola
 nombrecola=ftok("./Makefile",22);
 if(nombrecola==-1) {
	perror("Error de ftok en cola1 ");
	exit(-1);
 }
 //Obtengo la cola
 idcola=msgget(nombrecola,0600 | IPC_CREAT);
 if(idcola==-1)
 {
	perror("Error de msgget en cola1 ");
	exit(-1);
 }
 //Escribo el mensaje TIPO 1
 if(-1==msgsnd(idcola,(struct msgbuf *) &m1, sizeof(m1)-sizeof(long),0)) 
											perror("Error de msgsnd en cola1 ");
 //Recibo el mensaje TIPO 2
 if(-1==msgrcv(idcola,(struct msgbuf *) &m2, sizeof(m2)-sizeof(long),2,0))
											perror("Error de msgrcv en cola1 ");

 printf("COLA 1: El pid de cola 2 es %d\n", m2.pid);
 printf("FIN DE  cola 1 \n");
 //Borro la cola
 sleep(1);
 msgctl(idcola,IPC_RMID,NULL);

 




 return 0;
}
