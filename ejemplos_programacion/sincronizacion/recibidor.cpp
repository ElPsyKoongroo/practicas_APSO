#include <iostream>
#include <signal.h>

using namespace std;


void rutina12(int i){
 printf("Llega 12\n");
}

void rutina2(int i){
 printf("Llega control-c\n");
}


main()
{
 signal(12,rutina12);
 signal(2,rutina2);
 
 while(1){
   cout<<"Hola\n";
   sleep(3);
 }

}
