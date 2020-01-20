#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[]){
  pid_t pid = 0;
  int i, n; 
    //  i counts iterations
  int a = 1;
    //  a counts childrens 
  if (argc != 2){
    fprintf( stderr, "Uso: %s procesos\n", argv[0]);
  return 1;
  }
  n = atoi(argv[1]);
  for (i = 1; i < n;  i++) {
    pid = fork();
    if (pid < 0) break; /*Error control*///
    if (pid == 0) fprintf(  //  0 means is child
      stderr,
      "i:%d a=%d\n",
      i,
      a);
    if (pid) { 
      a += i;
      //       wait(pid);  /* To wait for the children*/
      break;
    }
  }
  fprintf( stderr,
    "i:%d Proceso ID:%ld Padre ID:%ld Hijo ID:%ld a=%d\n",
    i,
    (long)getpid(),
    (long)getppid(),
    (long)pid,
    a);
  return 0;
}
