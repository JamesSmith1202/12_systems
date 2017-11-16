#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

int main(){
  printf("I AM PAREN GIB RESPEK 2 PATRIARCH\n");
  pid_t child1;
  pid_t child2;
  child1 = fork();
  if (!(child1)){
    if(getpid() == 0){
      printf("%d\n",getpid());
      printf("%d\n", child1);
      exit(0);
    }
  }
  printf("Successful\n");
  return 0;
}
