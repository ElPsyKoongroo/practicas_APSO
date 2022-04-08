#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

void *read(int* sumador)
{
    while(*sumador != 0){
    scanf("%d", sumador);
    }
}

int main()
{
    pthread_t h1;
    int sumador = 1;
    int numero;

    printf("Introduzca un numero inicial:\n");
    scanf("%d", &numero);

    printf("Cualquier contador a partir de ahora sera usador para sumarlo");

    pthread_create(&h1, NULL, (void*)read, (void*)&sumador);

    while(sumador != 0)
    {
        numero = numero + sumador;
        printf("%d\n", numero);
        sleep(1);
    }

    pthread_join(h1, NULL);

    return 0;
}