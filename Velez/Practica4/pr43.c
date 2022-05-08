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
    printf("Señal 10 recivida pr43\n");
}


void rutina_alarm(){
    printf("pr43 con pid %d.Ha saltado el alarm. Mensaje 4\n", getpid());
}

int main(void) {
    int ppid = getppid(), seconds = 11;
    struct sigaction s10, s_alarm;
    printf("pr43 con pid %d. Mensaje 3\n", getpid());

    s10.sa_flags = 0;
    s10.sa_handler = rutina10;
    sigaction(10, &s10, NULL);


    s_alarm.sa_flags = SIGALRM;
    s_alarm.sa_handler = rutina_alarm;
    sigaction(SIGALRM, &s_alarm, NULL);

    pause();
    kill(ppid, 10);

    alarm(10);
    pause();
    kill(ppid, 10);
    exit(0);
}