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
  int c1;
  
  m1.tipo=2;
  m1.elpid=getpid();
  
  idcola=ftok("./Makefile",20);
  if(idcola==(key_t) -1) 
    perror("Cola2: ftok");
  
  c1=msgget(idcola,0600 | IPC_CREAT);
  if(c1==-1) 
    perror("Cola2: msgget");
  
  if(-1==msgsnd(c1,(struct msgbuf *) &m1, sizeof(struct Mens)-sizeof(long),0)) perror("cola2: msgsnd");;
  printf("Cola 2: He enviado mi pid que es %d\n",getpid());
  printf("Cola 2: Espero por el mensaje de mi vecino\n");
  if(-1==msgrcv(c1,(struct msgbuf *) &m2, sizeof(struct Mens)-sizeof(long),1,0)) perror("cola2: msgrcv");
  printf("Cola 2: Mi vecino me dice que su pid es %d\n",m2.elpid);
  
  sleep(1);
  msgctl(c1,IPC_RMID,0);
}

