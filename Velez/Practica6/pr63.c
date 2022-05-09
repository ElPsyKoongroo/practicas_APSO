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

int main(int argc, char* argv[]){
    srand(time(NULL));
    int counter = 0, sleep_time = rand()%(13-3)+3, id_cola;
    key_t Clave;
    struct Msg caracter;
    caracter.type = 2;

    Clave = ftok("./Makefile", 33);
    id_cola = msgget(Clave, S_IWUSR | IPC_CREAT);
    int bytes_sent;
    while (counter < 10){
        caracter.value = rand();
        bytes_sent = msgsnd(id_cola, &caracter, sizeof(caracter.value), 0);
        sleep(sleep_time);
        sleep_time = rand()%(13-3)+3;
        ++counter;
    }      
    exit(0);
}