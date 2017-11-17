#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <time.h>

void print_byte(void *p, int size){
  int i = 0;
  unsigned char *cp = (unsigned char*) p;
  for (;i < size; i++){
    printf("byte %d: %u\n", i, *cp);
    cp++;
  }
}

int get_status(void *p){
  unsigned char *cp = (unsigned char*) p;
  return cp[1];
}

int main(){
  printf("I AM PAREN GIB RESPEK 2 PATRIARCH\nPAREN pid: %d\n\n", getpid());
  pid_t child1;
  child1 = fork();
  if (child1) {
    child1 = fork();
  }
  if (!child1) {
    srand(getpid());
    printf("I'm child with pid: %d\n", getpid());
    int sleep_time = 5 + (rand() % 16);
    printf("%d is gonna sleep for %d seconds\n", getpid(), sleep_time);
    sleep(sleep_time);
    printf("\nI AM CHILD %d AND HAVE FINISHED SCHLEEP\n\n", getpid());
    exit(sleep_time);
  }

  else {
    int info;
    child1 = wait(&info);
    printf("Child process %d took a %d second nap... lazy bum\n", child1, get_status(&info));
    printf("PAREN %d is done\n", getpid());
    exit(0);
  }
  //printf("I'm %d and my child is: %d\n", getpid(), child1);
  return 0;
}
