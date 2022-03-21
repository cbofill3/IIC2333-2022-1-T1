#include <stdio.h>
#include <stdlib.h>
#include "../input_manager/manager.h"

int main(int argc, char **argv)
{
  int n = atoi(argv[1]);
  int rest = 0;
  for(int i=2;i<=n/2;i++)
	{
		if(n%i!=0)
			continue;
		else
			rest = 1;
	}
  if(rest==0)
		printf("%d is a prime number.\n",n);
	else
		printf("%d is not a prime number.\n",n);
  return 0;
}	