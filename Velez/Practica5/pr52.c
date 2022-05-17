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
    puts("pr52, signal12 recivida");
}

int main(){
    int pr52 = getpid(), pr54;
    struct sigaction s12;
    
    s12.sa_flags = 0;
    s12.sa_handler = rutina12;
    sigaction(12, &s12, NULL);

    printf("pr52 con pid %d. Mensaje 2\n", pr52);

    pr54 = fork();
    if(pr54 == 0){
        execl("pr54", "pr54", NULL);
        perror("Error al execl pr54: ");
        exit(-1);
    }
    write(4, &pr54, sizeof(pr54));
    
    exit(0);
}