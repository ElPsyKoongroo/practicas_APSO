#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int main(int args, char* argsv){
    printf("Soy pr32 y mi pid es: %d\n", getpid());
    sleep(0.4);
    FILE *f = fopen("prac3.dat", "a");
    fprintf(f, "%d", getpid());
    fclose(f);
    int vpid = fork();

    if(vpid == 0)
        execl("pr33", "pr33", NULL);
    else{
        sleep(1);
        printf("Fin de pr32\n");
        return 0;
    }
}