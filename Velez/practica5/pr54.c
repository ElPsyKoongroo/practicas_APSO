#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

void rutina12(){
    puts("pr54, signal12 recivida");
}


int main(){
    int pr51, pr54 = getpid(), f1_pid;
    struct sigaction s12;
    
    s12.sa_flags = 0;
    s12.sa_handler = rutina12;
    sigaction(12, &s12, NULL);
    pause();
    printf("pr54 con pid %d. Mensaje 4\n", pr54);

    f1_pid = open("f1", O_RDONLY);
    read(f1_pid, &pr51, sizeof(pr51));

    kill(pr51, 12);
    close(f1_pid);
    exit(0);
}