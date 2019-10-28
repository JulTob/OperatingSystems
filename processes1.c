#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main (int argc, char *argv[])
{
  pid_t pid = 0;
  int i, n;
  int a = 1;
  if (argc != 2){
    fprintf(stderr,
      "Uso: %s [nº de procesos]\n",
      argv[0]);
      return 1;
    }
    n = atoi(argv[1]);
    for (i = 1; i < n; i++) {
      pid = fork();
      if (pid) {
        a += i;
        break;
      }
    }
    fprintf(stderr,
      "i:%d Proceso ID:%ld Padre-ID:%ld Hijo-ID:%ld a=%ld\n",
      i,
      (long)getpid(),
      (long)getppid(),
      (long)pid, a);
      return 0;
}
