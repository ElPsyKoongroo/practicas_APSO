#include<stdlib.h>
#include<stdio.h>
#include<pthread.h>
#include<unistd.h>
#include<time.h>

float contador = 0, maximo = 0, minimo = 0;

void* leedor(){
    float aux;
    scanf("%f", &contador);

    while(contador != -5){
        scanf("%f", &aux);
        if(aux == 0){
            contador *= 10;
        } else if(aux == -1){
            contador = 1;
        } else if(aux == -5){
            contador = -5;
        } else {
            contador *= aux;
        } 
        if(contador > maximo) maximo = contador;
        if(contador < minimo) minimo = contador;
    }

}

void* escribidor(){
    while(contador != -5){
        printf("Contador: %f\n", contador*2);
        sleep(1);
    }
}


int main(){

    pthread_t thread1, thread2;

    pthread_create(&thread1, NULL, leedor, NULL);
    pthread_create(&thread2, NULL, escribidor, NULL);

    pthread_join(thread1, NULL);

    printf("Valor maximo: %f, Valor minimo %f\n", maximo, (minimo==-5)?0:minimo);

    return EXIT_SUCCESS;
}