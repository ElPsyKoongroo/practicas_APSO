#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

typedef struct thread_info {
    int running;
    int number;
} Thread_info;

void *input_thread(void *x) {
    Thread_info *info = (Thread_info *)x;
    while (info->running) {
        scanf("%d", &info->number);
        if (info->number == -1) {
            info->running = 0;
        }
    }
    return NULL;
}

void *mostrar(void *x) {
    Thread_info *info = (Thread_info *)x;
    while (info->running) {
        printf("%d\n", (rand() % 100 + info->number));
        sleep(1);
    }
    return NULL;
}

void pr21() {
    pthread_t mostar_id, input_id;
    Thread_info *info = malloc(sizeof(Thread_info));
    info->running = 1;

    pthread_create(&input_id, NULL, input_thread, &info);
    pthread_create(&mostar_id, NULL, mostrar, &info);

    pthread_join(mostar_id, NULL);
}

int main(int argc, char *argv[]) {
    srand(time(NULL));
    pr21();
    return 0;
}