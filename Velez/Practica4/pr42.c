#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/msg.h>
#include <time.h>
#include <unistd.h>


void rutina10(){
    printf("Señal 10 recivida pr42\n");
}

int main(void) {
    int ppid = getppid();
    struct sigaction s10;
    printf("pr42 con pid %d. Mensaje 2\n", getpid());
    s10.sa_flags = 0;
    s10.sa_handler = rutina10;
    sigaction(10, &s10, NULL);
    pause();
    kill(ppid, 12);
    exit(0);
}