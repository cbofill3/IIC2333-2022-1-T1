#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "../linked_list/linked_list.c"

int main()
{ 
  time_t start;
  time_t run_time;
  start = time(NULL); 
  printf("Hello World!\n");
  run_time = time(NULL) - start;   
  return 0;
}	