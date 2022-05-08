#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int main(int args, char* argsv){

    printf("Soy pr33 y mi pid es: %d\n", getpid());
    FILE *f = fopen("prac3.dat", "r");
    char *pid_pr32[7], *pid_pr31[7];
    fread(&pid_pr31, sizeof(char), 6, f);
    fread(&pid_pr32, sizeof(char), 6, f);
    printf("Soy pr33 y el pid de pr32 es: %s\n", pid_pr32);
    printf("Soy pr33 y el pid de pr31 copia es: %s\n", pid_pr31);

    printf("Fin de pr33\n");
    exit(0);
}