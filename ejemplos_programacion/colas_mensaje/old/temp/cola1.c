#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <unistd.h>
#include <sys/msg.h>
              

struct Mens{
  long tipo;
  int elpid;
};

main(){

  struct Mens m1,m2;
  key_t idcola;
  int c1,env,rec;
  
  m1.tipo=1;
  m1.elpid=getpid();
  
  idcola=ftok("./Makefile",20);
  if(idcola==(key_t) -1) perror("Cola1: ftok");
  
  c1=msgget(idcola,0600 | IPC_CREAT);
  if(c1==-1) perror("Cola1: msgget");
  env=msgsnd(c1,(struct msgbuf *) &m1, sizeof(struct Mens)-sizeof(long),0); 
  if(env==-1) perror("cola1: msgsnd");
  printf("Cola 1: He enviado mi pid que es %d\n",getpid());
  printf("Cola 1: Espero por el mensaje de mi vecino\n");
  rec=msgrcv(c1,(struct msgbuf *) &m2, sizeof(struct Mens)-sizeof(long),2,0);
  if(rec==-1) perror("cola1: msgrcv");
  printf("Cola 1: Mi vecino me dice que su pid es %d\n",m2.elpid);
  
  sleep(1);
  msgctl(c1,IPC_RMID,0);
}
