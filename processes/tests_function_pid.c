#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

pid_t function_pid(){
  pid_t pid = getpid();

  return pid;
}

int main (int argc, char *argv[]){
  pid_t pid = 0;

  fprintf(
    stdout,
    "Proceso ID:%ld Funcion ID:%ld\n",
    (long)getpid(),
    (long)function_pid()
  );
  return 0;

}


/*
gcc test.c -o test;./test
*/
