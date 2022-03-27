#include <stdio.h>
#include <stdlib.h>
#include "../input_manager/manager.h"

int main(int argc, char **argv)
{
  long n = atol(argv[1]);
  int rest = 0;
  for(long i=2;i<=n/2;i++)
	{
		if(n%i!=0)
			continue;
		else
			rest = 1;
	}
  if(rest==0)
		printf("%ld is a prime number.\n",n);
	else
		printf("%ld is not a prime number.\n",n);
  return 0;
}	
