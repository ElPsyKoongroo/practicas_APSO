#include <stdio.h>
#include <unistd.h>
#include <signal.h>

main()
{
printf("Soy el hijo de padre_recibe\n");
sleep(5);
kill(getppid(),12);
sleep(2);
kill(getppid(),2);
sleep(3);
kill(getppid(),10);

}
