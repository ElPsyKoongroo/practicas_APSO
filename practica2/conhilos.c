#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

void *f1()
{
    for(int i = 0; i < 5; i++)
    {
        printf("Hilo 1: %d\n", i);
        sleep(1);
    }
}

void *f2()
{
    for(int i = 0; i < 5; i++)
    {
        printf("Hilo 2: %d\n", i);
        sleep(1);
    }
}

int main()
{
    pthread_t h1, h2;

    printf("Empieza el programa\n");

    pthread_create(&h1, NULL, f1, NULL);
    pthread_create(&h2, NULL, f2, NULL);

    pthread_join(h1, NULL);
    pthread_join(h2, NULL);

    printf("Termina el programa\n");
}