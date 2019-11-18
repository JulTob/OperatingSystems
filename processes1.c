#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main (int argc, char *argv[]){
  pid_t pid = 0;
  int i, n;
  int a = 1;
  if (argc != 2){
    fprintf( stderr, "Uso: %s procesos\n", argv[0]);
  return 1;
  }
  n = atoi(argv[1]);
  for (i = 1; i < n;  i++) {
    pid = fork();
    if (pid) {  //  0 means is child
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
