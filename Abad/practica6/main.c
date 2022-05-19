#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/msg.h>
#include <time.h>
#include <unistd.h>

struct Numero {
    long type; // 1 -> Positivo, 2 -> Negativo
    int value;
};

void ProcesoA(int Clave) {
    int id_cola, num_aletatorio, bytes_sent;

    id_cola = msgget(Clave, S_IWUSR | S_IRUSR | IPC_CREAT);

    if (id_cola == -1) {
        perror("Error al abrir la cola: ");
    }

    struct Numero numero;
    int contador = 0;
    int sleep_time;
    srand(time(NULL));

    while (contador != 10) {
        sleep_time = rand() % 2 + 1;

        num_aletatorio = (rand() % 201) - 100;

        numero.type = (num_aletatorio < 0 ? 2 : 1);
        numero.value = num_aletatorio;

        bytes_sent =
            msgsnd(id_cola, (struct msgbuf *)&numero, sizeof(numero.value), 0);
        if (bytes_sent)
            perror("Error al escribir: ");
        ++contador;
        sleep(sleep_time);
    }
    msgctl(id_cola, IPC_RMID, (struct msqid_ds *)NULL);
}

void ProcesoB(int Clave) {
    int id_cola, bytes_read;
    struct Numero numero;
    long msgtyp = 1;
    sleep(1);
    id_cola = msgget(Clave, S_IRUSR | IPC_CREAT);

    if (id_cola == 0) {
        printf("Error al abrir la cola en B\n");
    }

    do {
        bytes_read = msgrcv(id_cola, (void *)&numero,
                            sizeof(numero) - sizeof(long), msgtyp, 0);
        fprintf(stdout, "Numerito desde B: %d, bytes leidos: %d \n",
                numero.value, bytes_read);
    } while (bytes_read != -1);
}

void ProcesoC(int Clave) {
    int id_cola, bytes_read;
    long msgtyp = 2;
    sleep(1);
    id_cola = msgget(Clave, S_IRUSR | IPC_CREAT);

    if (id_cola == 0) {
        printf("Error al abrir la cola en C\n");
    }

    struct Numero numero;

    do {
        bytes_read = msgrcv(id_cola, (void *)&numero,
                            sizeof(numero) - sizeof(long), msgtyp, 0);
        fprintf(stdout, "Numerito desde C: %d, bytes_leidos: %d\n",
                numero.value, bytes_read);
    } while (bytes_read != -1);
}

int main() {
    int forks;

    key_t Clave;
    int id_cola;

    Clave = ftok("./Makefile", 14);
    if (Clave == (key_t)-1) {
        printf("Error al crear la clave");
        exit(-1);
    }

    id_cola = msgget(
        Clave, S_IRUSR | S_IWUSR); // Asegurarse que la cola no está ya creada

    if (id_cola != -1) {
        fprintf(stderr, "Borrando la cola anterior\n");
        msgctl(id_cola, IPC_RMID, (struct msqid_ds *)NULL);
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