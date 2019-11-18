#include <unistd.h>
//  execl
#include <stdio.h>
//  fprintf
#include <sys/types.h>
#include <unistd.h>
//  pid_t fork(void); getpid

void  run_xeyes(), run_xcalc(), run_xload(),
      run_xlogo(), run_xclock(),  check_tree(pid_t);

int main (int argc, char *argv[]){

  pid_t control = getpid();

  pid_t const Unset = -1;

  pid_t peyes  = Unset;
  pid_t pcalc  = Unset;
  pid_t pload  = Unset;
  pid_t plogo  = Unset;
  pid_t pclock = Unset;


  if (control == getpid()) { peyes = fork(); };
  if (control == getpid()) { pcalc = fork(); };
  if (control == getpid()) { pload = fork(); };
  if (control == getpid()) { plogo = fork(); };
  if (control == getpid()) { pclock = fork(); };
  /* Branches Root into 5 childs */


  if (peyes == 0) run_xeyes();
  if (pcalc == 0) run_xcalc();
  if (pload == 0) run_xload();
  if (plogo == 0) run_xlogo();
  if (pclock == 0) run_xclock();

/*
  if (control == getpid()) fprintf(
       stderr,
       " %ld | %d | %d | %d | %d  | %d \n \n",
       (long)getpid(),
       peyes,
       pcalc,
       pload,
       plogo,
       pclock
     );
*/
  return 0;

}

void run_xcalc(){
  do {
    pid_t looper = fork();
    if (looper==0){
      int p = execl(
        "/usr/bin/xcalc",
        "xcalc",
        NULL);
      };
    wait(looper);
  } while(1);

};

void run_xeyes(){
  do {
    pid_t looper = fork();
    if (looper==0){
      int  p = execl(
         "/usr/bin/xeyes",
         "xeyes",
         NULL);
      };
    wait(looper);
  } while(1);


};

void run_xload(){
  do {
    pid_t looper = fork();
    if (looper==0){
      int  p = execl(
         "/usr/bin/xload",
         "xload",
         NULL);
      };
    wait(looper);
  } while(1);


};

void run_xlogo(){
  do {
    pid_t looper = fork();
    if (looper==0){
      int  p = execl(
         "/usr/bin/xlogo",
         "xlogo",
         NULL);
      };
    wait(looper);
  } while(1);


}

void run_xclock(){
  do {
    pid_t looper = fork();
    if (looper==0){
      int  p = execl(
         "/usr/bin/xclock",
         "xclock",
         "-update",
         "2",
         NULL);
       };
    wait(looper);
  } while(1);


}
