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

int main(void){
    srand(time(NULL));
    int counter = 0, sleep_time = rand()%(16-8)+8, id_cola;
    key_t Clave;
    struct Msg caracter;
    caracter.type = 1;

    Clave = ftok("./Makefile", 33);
    id_cola = msgget(Clave, S_IWUSR | IPC_CREAT);

    while (counter < 10){
        caracter.value = (rand()%(123-65))+65;
        msgsnd(id_cola, (void*)&caracter, sizeof(caracter.value), 0);
        sleep(sleep_time);
        sleep_time = rand()%(16-8)+8;
        ++counter;
    }      
    exit(0);
}