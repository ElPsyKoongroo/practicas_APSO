#include <dirent.h>
#include <fcntl.h>
#include <grp.h>
#include <pwd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <unistd.h>

void permisos(struct stat* datos_fichero){
    if(datos_fichero->st_mode & S_IRUSR) printf("r");
    else printf("-");    
    
    if(datos_fichero->st_mode & S_IWUSR) printf("w");
    else printf("-");    

    if(datos_fichero->st_mode & S_IXUSR) printf("x");
    else printf("-");    
    
    // GROUP
    if(datos_fichero->st_mode & S_IRGRP) printf("r");
    else printf("-");    
    
    if(datos_fichero->st_mode & S_IWGRP) printf("w");
    else printf("-");    

    if(datos_fichero->st_mode & S_IXGRP) printf("x");
    else printf("-");    

    // OTHERS
    if(datos_fichero->st_mode & S_IROTH) printf("r");
    else printf("-");    
    
    if(datos_fichero->st_mode & S_IWOTH) printf("w");
    else printf("-");    

    if(datos_fichero->st_mode & S_IXOTH) printf("x");
    else printf("-");    

    printf(" ");
}

int main(int argc, char* argv[]){
    struct stat datos_fichero;
    struct dirent *fichero_actual;
    DIR *directorio;
    char ruta[100];

    int err = stat(argv[1], &datos_fichero);
    if(err == -1 || argc < 1){
        printf("No es un fichero valido\n");
        exit(-1);
    }
    if(!S_ISDIR(datos_fichero.st_mode)){
        printf("El fichero no es un directorio\n");
        exit(-1);
    }

    directorio = opendir(argv[1]);
    fichero_actual = readdir(directorio);
    
    do{
        memset(ruta, '\0', sizeof(char)*100);

        fichero_actual = readdir(directorio);
        strncpy(ruta, argv[1], 100);
        strcat(ruta, fichero_actual->d_name);
        stat(ruta, &datos_fichero);

        permisos(&datos_fichero);
        printf("%d, ", fichero_actual->d_ino);
        switch (fichero_actual->d_type)
        {
        case 4:
            printf("%-12s", "directory, ");
            break;
        case 8:
            printf("%-12s", "file, ");
            break;
        case 10:
            printf("%-12s", "softlink, ");
            break;
        default:
            printf("%-12s", "la cosa, ");
            break;
        }

        printf("%s, ", getgrgid(datos_fichero.st_uid)->gr_name);

        printf("%s\n", fichero_actual->d_name);
    }while((int) fichero_actual->d_off != -1);


    return 0;
}