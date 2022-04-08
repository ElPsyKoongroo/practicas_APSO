#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "funciones.h"

int menu()
{
    system("clear");
    printf("\n1.Leer datos\n");
    printf("2.Visualizar la suma\n");
    printf("3.Raiz cubica del maximo\n");
    printf("4.Salir\n");
    printf("\nIngrese una opcion:\n");
    int opcion;
    scanf("%d",&opcion);
    fflush(stdin);

    return opcion;
}

void introducirNumeros(int array[5])
{
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el numero %d:\n", i+1);
        scanf("%d",&array[i]);
    }

    printf("\nArray-> [ ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d", array[i]);
        if(i < 4)
        {
            printf(", ");
        }
    }
    printf(" ]\n");


}

int main()
{
    int array[5];

    int opcion;

    do
    {
        opcion = menu();

        switch (opcion)
        {
        case 1:
            introducirNumeros(array);
            getchar();
            getchar();

            break;
        
        case 2:
            printf("La suma es: %d\n",suma(array));
            getchar();
            getchar();
            break;
        
        case 3:
            printf("La raiz cubica del maximo es: %f\n",cubica(array));
            getchar();
            getchar();
            break;
        
        case 4: break;
        default:
            printf("Numero introducido no valido\n");
            getchar();
            getchar();
            break;
        }

    } while (opcion != 4);
    
    return 0;
}