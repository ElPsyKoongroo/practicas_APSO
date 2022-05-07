#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int parent = getppid();

    if (parent) {
        printf("Se acaba de iniciar el proceso C con PID %d\n", getpid());
    } else {
        FILE *infoc = fopen("infoc", "w");
        fprintf(infoc, "Se acaba de iniciar el proceso C con PID %d\n, y el padre A: %d",getpid(), parent);
        fclose(infoc);
    }
    return 0;
}