#include <stdio.h>
#include <stdlib.h>
#include "../input_manager/manager.h"

int main(int argc, char **argv)
{
  float a = atof(argv[1]);
  float b = atof(argv[2]);
  float c = a + b;
  printf("The sum of %.1f and %.1f is %.1f.\n", a, b, c);
  return 0;
}	