#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>

void proceso1(){
    pid_t p2, p3;
    int file = open("fich1", O_WRONLY | O_CREAT | O_TRUNC);

    if(file == -1){
        perror("No se pudo abrir el archivo: ");
        exit(-1);
    }
    char file_desc[10], p2_pid[10];
    snprintf(file_desc, 10, "%d", file);

    printf("Soy p1 y mi pid es: %d\n", getpid());

    p2 = fork();
    if(p2 == 0){
        execl("p2", "p2", file_desc, NULL);
        perror("Error al crear el proceso: ");
        exit(-1);
    }
    snprintf(p2_pid, 10, "%d", p2);
    sleep(2);
    p3 = fork();
    if(p3 == 0){
        execl("p3", "p3", file_desc, p2_pid, NULL);
        perror("Error al crear el proceso: ");
        exit(-1);
    }
    sleep(1);
    close(file);
}

int main(){
    proceso1();
    return EXIT_SUCCESS;
}