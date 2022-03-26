#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include "unistd.h"
#include <sys/wait.h>

#include "../input_manager/manager.h"
#include "../linked_list/linked_list.c"

int main(int argc, char const *argv[])
{
  int is_running = 1; 
  while(is_running == 1){
    printf("> ");
    char **input = read_user_input();
    if(strcmp(input[0], "hello") == 0){
      pid_t p = fork();
      if(p == 0){
        execv("./hello", NULL);
      }
      else{
        insertFirst(p, "hello"); 
        wait(NULL);
      }
    }
    // SI INPUT ES SUM
    else if(strcmp(input[0], "sum") == 0){
      pid_t p = fork();
      if(p == 0){
        execv("./sum", input);
      }
      else{
        wait(NULL);
      }
    }
    // SI INPUT ES IS_PRIME
    else if(strcmp(input[0], "is_prime") == 0){
      pid_t p = fork();
      if(p == 0){
        execv("./is_prime", input);
      }
      else{
        wait(NULL);
      }
    }
    // SI INPUT ES CREXEC
    else if(strcmp(input[0], "crexec") == 0){
      if( access( ("./%s", input[1]), F_OK ) == 0 ) {
        char **command = &input[1];
        pid_t p = fork();
        if(p == 0){
          execv(("./%s",input[1]), command);
        }
        else{
          wait(NULL);
        }
      } else {
        printf("%s does not exist.\n", input[1]);
      }
    }
    // SI INPUT ES CRLIST
    else if(strcmp(input[0], "crlist") == 0){
      printList();
    }
    // SI INPUT ES CREXIT
    else if(strcmp(input[0], "crexit") == 0){
      continue;
    }
    free_user_input(input);
  }
}
