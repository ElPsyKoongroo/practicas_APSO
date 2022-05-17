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

 m1.tipo=2;
 m1.pid=getpid();

 printf("Soy cola 2 con pid %d\n",getpid());
 //Obtengo el nombre de la cola
 nombrecola=ftok("./Makefile",22);
 if(nombrecola==-1) {
	perror("Error de ftok en cola2 ");
	exit(-1);
 }
 //Obtengo la cola
 idcola=msgget(nombrecola,0600 | IPC_CREAT);
 if(idcola==-1)
 {
	perror("Error de msgget en cola2 ");
	exit(-1);
 }
 //Escribo el mensaje TIPO 1
 if(-1==msgsnd(idcola,(struct msgbuf *) &m1, sizeof(m1)-sizeof(long),0)) 
											perror("Error de msgsnd en cola2 ");
 //Recibo el mensaje TIPO 2
 if(-1==msgrcv(idcola,(struct msgbuf *) &m2, sizeof(m2)-sizeof(long),1,0))
											perror("Error de msgrcv en cola2 ");

 printf("COLA 2: El pid de cola 1 es %d\n", m2.pid);
 printf("FIN DE  cola 2 \n");
 
 return 0;
}
