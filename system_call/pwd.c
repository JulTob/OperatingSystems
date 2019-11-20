/*-------------
pwd
Julio Toboso
--------------*/


int main(int argc, char const *argv[]) {
  char *Work_Dirct=NULL;

  //Get PWD (enviroment variable[Where am I: Present Working Directory])
  Working_Directory= getenv("PWD")
  printf("Working Directory:\n\t%s\n", Working_Directory);
  return 0;
}
