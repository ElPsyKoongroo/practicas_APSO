#include<unistd.h>
#include<stdlib.h>
#include<fcntl.h>
#include<stdio.h>
#include<string.h>

int main(int argc, char* args[]){
    char mensajito[30] = {};
    int  file = atoi(args[1]);
    int  chars = 0;

    printf("Soy p2 y mi pid es: %d \n", getpid());
    chars = snprintf(mensajito, 30, "PID proceso 2: %d \n", getpid());
    write(file, mensajito, chars);
    
    return EXIT_SUCCESS;
}