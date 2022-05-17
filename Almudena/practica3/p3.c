#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char* args[]){
    pid_t p2        = atoi(args[2]);
    int   file_desc = atoi(args[1]);
    int   chars     = 0;

    printf("Soy el proceso P3 y mi PID es: %d\n", getpid());
    char mensajito[50] = {};
    
    chars = snprintf(mensajito, 50, "PID proceso 3: %d\n", p2);
    write(file_desc, mensajito, chars);
    
    chars = snprintf(mensajito, 50, "El PID de mi hermano es: %d\n", p2);
    write(file_desc, mensajito, chars);

    return EXIT_SUCCESS;
}