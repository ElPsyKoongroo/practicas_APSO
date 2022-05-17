#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>
#include<signal.h>


void rutina10(){
    fprintf(stdout, "\n");
}

int main(){
    int p2, p3;
    int file_desc = open("fich1.txt", O_WRONLY | O_CREAT);
    char pid_p3[10], file_str[10];
    
    struct sigaction s10;
    s10.sa_flags = 0;
    s10.sa_handler = rutina10;
    sigaction(10, &s10, NULL);

    sprintf(file_str, "%d", file_desc);

    p3 = fork();
    if(p3 == 0){
        execl("p3.bin", "p3.bin", file_str, NULL);
        perror("No se puedo ejecutar p3: ");
        exit(-1);
    }

    sprintf(pid_p3, "%d", p3);
    p2 = fork();
    if(p2 == 0){
        execl("p2.bin", "p2.bin", file_str, pid_p3, NULL);
        perror("No se puedo ejecutar p2: ");
        exit(-1);
    }
    
    printf("Soy P1 y mi PID es: %d\n", getpid());
    sleep(1);
    kill(p2, 10);
    pause();
    close(file_desc);
    return EXIT_SUCCESS;
}