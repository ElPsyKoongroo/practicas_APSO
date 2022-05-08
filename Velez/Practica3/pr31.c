#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int main(int args, char* argsv){
    int vpid;
    printf("Soy pr31 y mi pid es: %d\n", getpid());
    vpid = fork();
    sleep(0.2);
    if (vpid == 0){
        printf("Soy la copia de pr31 y mi pid es: %d\n", getpid());
        sleep(0.1);
        FILE *f = fopen("prac3.dat", "a");

        fprintf(f, "%d", getpid());
        fclose(f);
        
        sleep(2);
        printf("Fin de la copia de pr31\n");

        exit(0);
    } else {
        open("prac3.dat", O_WRONLY | O_CREAT);
        sleep(0.2);

        vpid = fork();
        if(vpid == 0)
            execl("pr32", "pr32", NULL);
        else {
            sleep(3);
            printf("Fin de pr31 original\n");
        }
    }

    return 0;
}