#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/msg.h>


main()
{

 struct mensa{
   long tipo;
   int elpid;
 };
 
 struct mensa m1,m2;
 key_t cola1;
 int c1;
 
 m1.tipo=2;
 m1.elpid=getpid();
 
 cola1=ftok("./Makefile",20);
 c1=msgget(cola1,0600 | IPC_CREAT);

 printf("COLA4: Mi pid vale %d\n",getpid());
 msgsnd(c1,(struct msgbuf *) &m1,sizeof(m1)-sizeof(long),0);
 msgrcv(c1,(struct msgbuf *) &m2,sizeof(m2)-sizeof(long),1,0);
 printf("COLA4: El pid recibido es %d\n",m2.elpid);
 sleep(1);
 msgctl(c1,IPC_RMID,0);
 
}
