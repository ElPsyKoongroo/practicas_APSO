#include <stdio.h>
#include <termio.h>
#include <unistd.h>
#include <sys/ioctl.h>

#define STDINFD 0

char inkey(void) { 
  char c; 
  struct termio param_ant, params; 

  ioctl(STDINFD,TCGETA,&param_ant); 

  params = param_ant; 
  params.c_lflag &= ~(ICANON|ECHO); 
  params.c_cc[4] = 1; 

  ioctl(STDINFD,TCSETA,&params); 

  fflush(stdin); fflush(stderr); fflush(stdout); 
  read(STDINFD,&c,1); 

  ioctl(STDINFD,TCSETA,&param_ant); 
  return c; 
} 

