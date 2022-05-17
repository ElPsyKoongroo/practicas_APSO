#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
               
main()
{
 int f1;
 char a='b';
 
 f1=open("f1.txt",O_WRONLY|O_CREAT|O_APPEND,0700);
 write(f1,&a,sizeof(a));
 close(f1);

}
