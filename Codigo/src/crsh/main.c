#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "unistd.h"
#include <time.h>
#include "../input_manager/manager.h"
#include "../linked_list/linked_list.h"

int main(int argc, char const *argv[])
{
  int is_running = 1; 
  while(is_running == 1){
    char **input = read_user_input();
    if(strcmp(input[0], "hello") == 0){
      pid_t p = fork();
      insertFirst(p, "hello", time(NULL)); 
      if(p == 0){
        execv("./hello", NULL);
      } 
    }
    else if(strcmp(input[0], "sum") == 0){
      pid_t p = fork();
      insertFirst(p, "sum", time(NULL)); 
      if(p == 0){
        execv("./sum", input);
      }
    }
    else if(strcmp(input[0], "is_prime") == 0){
      pid_t p = fork();
      insertFirst(p, "is_prime", time(NULL));
      if(p == 0){
        execv("./is_prime", input);
      }
    }
    else if(strcmp(input[0], "crexec") == 0){
      if( access( ("./%s", input[1]), F_OK ) == 0 ) {
        char **command = &input[1];
        pid_t p = fork();
        insertFirst(p, "crexec", time(NULL));
        if(p == 0){
          execv(("./%s",input[1]), command);
        }
      } else {
        printf("%s does not exist.\n", input[1]);
      }
    }
    else if(strcmp(input[0], "crlist") == 0){
     printList();
    }
    else if(strcmp(input[0], "crexit") == 0){
      continue;
    }
    free_user_input(input);
  }
}
