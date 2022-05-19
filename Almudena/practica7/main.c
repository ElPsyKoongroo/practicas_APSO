#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <time.h>
#include <unistd.h>


void no_existe(char* ruta){
    struct stat datos_fichero;

    mkdir(ruta, 0777);
    chdir(ruta);
    FILE *ficherito = fopen("pruebas", "w");
    char mensajito[20];
    int chars = sprintf(mensajito, "%d, %d", getpid(), rand());
    fwrite(mensajito, chars, sizeof(char), ficherito);
    fclose(ficherito);

    stat("pruebas", &datos_fichero);

    printf("Inodito: %d\n", datos_fichero.st_ino);
}

void existe(char* ruta){
    struct dirent *fichero_actual;
    DIR *directorio = opendir(ruta);
    do{
        fichero_actual = readdir(directorio);
        printf("Inode: %d, Nombre: %s\n", fichero_actual->d_ino, fichero_actual->d_name);
    }while((int)fichero_actual->d_off != -1);
}

int main(int argc, char* argv[]){
    struct stat datos_fichero;
    int err = stat(argv[1], &datos_fichero);
    if (err == -1) {
        srand(time(NULL));
        no_existe(argv[1]);
    } else if (S_ISDIR(datos_fichero.st_mode)) {
        existe(argv[1]);
    } else {
        printf("Eso que me has pasado no es un directorio\n");
    }
    return 0;
}