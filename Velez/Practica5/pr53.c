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

int main(){
    
    int pr53=getpid(), pr54;
    printf("pr53 con pid %d. Mensaje 3\n", pr53);
    read(5, &pr54, sizeof(pr54));

    kill(pr54, 12);

    exit(0);

}