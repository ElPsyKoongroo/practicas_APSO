#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/msg.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <time.h>
#include <unistd.h>

void rutina12(){
    puts("pr51, signal12 recivida");
}



int main(){
    int pr52, pr53, tub1[2], fifo_id, fifo_err;
    pid_t pr51 = getpid();
    struct sigaction s12;
    
    s12.sa_flags = 0;
    s12.sa_handler = rutina12;
    sigaction(12, &s12, NULL);


    printf("pr51 con pid %d. Mensaje 1\n", pr51);

    pipe(tub1);
    fifo_err = mkfifo("f1", 0777);
    perror("Error al generar la fifo: ");
    if(fifo_err != 0){
        unlink("f1");
        printf("Unlinking f1\n");
        sleep(3);
        mkfifo("f1", 0777);
    }

    pr52 = fork();
    if(pr52 == 0){
        dup2(tub1[1], 4);
        execl("pr52", "pr52", NULL);
        perror("Error al execl pr52: ");
        exit(-1);
    }
    sleep(1);
    kill(pr52, 12);
    

    pr53 = fork();

    if(pr53 == 0){
        dup2(tub1[0], 5);
        execl("pr53", "pr53", NULL);
        perror("Error al execl pr53: ");
        exit(-1);
    }
    
    sleep(1);
    fifo_id = open("./f1", O_WRONLY);
    if(fifo_id == -1){
        perror("Error al abrir la fifo: ");
        exit(-1);
    }
    write(fifo_id, &pr51, sizeof(pr51));

    pause();
    
    printf("pr51 con pid %d. Mensaje 5\n", pr51);

    unlink("f2");
    close(fifo_id);
    close(tub1[0]);
    close(tub1[1]);
    return 0;
}