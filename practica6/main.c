#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <time.h>
#include <unistd.h>

struct Numero {
    long Id_Men; // 1 -> Positivo, 2 -> Negativo
    int Numero;
};

void ProcesoA(int Clave) {
    int Id_Cola;
    int num_aletatorio;

    Id_Cola = msgget(Clave, 0600 | IPC_CREAT);

    if (Id_Cola == 0) {
        printf("Error al abrir la cola en A");
    }

    struct Numero numero;
    int contador = 0;
    int sleep_time;
    srand(time(NULL));

    while (contador != 10) {
        sleep_time = rand() % 2 + 1;

        sleep(sleep_time);

        num_aletatorio = (rand() % 201) - 100;

        numero.Id_Men = (num_aletatorio < 0 ? 2 : 1);
        numero.Numero = num_aletatorio;

        msgsnd(Id_Cola, (struct msgbuf *)&numero, sizeof(numero) - sizeof(long),
               0);
        contador++;
    }
    msgctl(Id_Cola, IPC_RMID, (struct msqid_ds *)NULL);
}

void ProcesoB(int Clave) {
    int Id_Cola;

    Id_Cola = msgget(Clave, 0600 | IPC_CREAT);

    if (Id_Cola == 0) {
        printf("Error al abrir la cola en B");
    }

    struct Numero numero;
    int leido;

    do {

    } while (leido != 0);
}

void ProcesoC(int Clave) {
    int Id_Cola;

    Id_Cola = msgget(Clave, 0600 | IPC_CREAT);

    if (Id_Cola == 0) {
        printf("Error al abrir la cola en C");
    }

    struct Numero numero;
}

int main() {
    int forks;

    key_t Clave;
    int Id_Cola;

    Clave = ftok("Makefile", 14);
    if (Clave == (key_t)-1) {
        printf("Error al crear la clave");
        exit(-1);
    }

    Id_Cola = msgget(Clave, 0600); // Asegurarse que la cola no está ya creada

    if (Id_Cola != -1) {
        msgctl(Id_Cola, IPC_RMID, (struct msqid_ds *)NULL);
    }

    forks = fork();

    if (forks == 0) {
        ProcesoB(Clave);
        exit(0);
    } else if (forks == -1) {
        printf("Error al forkear B");
        exit(-1);
    }

    forks = fork();

    if (forks == 0) {
        ProcesoC(Clave);
        exit(0);
    } else if (forks == -1) {
        printf("Error al forkear C");
        exit(-1);
    }

    ProcesoA(Clave);

    return 0;
}