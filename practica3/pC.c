#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]) {
    int parent = getppid();
    int arg_parent = atoi(argv[1]);
    if (argc < 2 || arg_parent != parent) {
        printf("Se acaba de iniciar el proceso C con PID %d\n", getpid());
    } else {  
        printf("Se acaba de iniciar el proceso C con PID %d, y el padre A: %d\n",getpid(), arg_parent);
    }
    return 0;
}