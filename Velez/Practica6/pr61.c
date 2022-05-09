#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

struct Msg {
    long type; // 1 -> chars, 2 -> ints 
    int value; 
};

int main(){
    pid_t pr62, pr63;
    key_t Clave;
    int id_cola;
    struct Msg mensajito;

    Clave = ftok("./Makefile", 33);
    if (Clave == -1) {
        printf("Error al crear la clave");
        exit(-1);
    }

    id_cola = msgget(Clave, S_IRUSR | IPC_CREAT); // Asegurarse que la cola no está ya creada
    if (id_cola == -1) {
        fprintf(stderr, "Borrando la cola anterior\n");
        msgctl(id_cola, IPC_RMID, NULL);
    }

    pr62 = fork();
    if(pr62 == 0){
        execl("pr62", "pr62", NULL);
        perror("No se pudo ejecutar pr62: ");
        exit(-1);
    }
    pr63 = fork();
    if(pr63 == 0){
        execl("pr63", "pr63", NULL);
        perror("No se pudo ejecutar pr63: ");
        exit(-1);
    }


    int i = 1, bytes_rev = 0, msgtype = 1;
    do{
        bytes_rev = msgrcv(id_cola, &mensajito, sizeof(mensajito.value), msgtype, 0);
        if(bytes_rev != -1){
            if(msgtype == 1)
                printf("type: %d, %c\n", msgtype, mensajito.value); 
            else
                printf("type: %d, %d\n", msgtype, mensajito.value); 
            msgtype = i%2 + 1;   
            i++;
        }
    }while(i<=20);
    msgctl(id_cola, IPC_RMID, (struct msqid_ds *)NULL);
}