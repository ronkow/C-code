/*
factorial.c
-----------

factorial(n) returns factorial of input n (0 to 12)
*/


#include <stdio.h>

int factorial(int n) 
{
    int fac = 1;
    
	if (n <= 12)
	{   for(int i = 2; i <= n; ++i)
		{   fac *= i;
		}
		return fac;
	}
	else
	{   printf("n must be an integer from 0 to 12.\n");
		return 0;
	}
}

int main(void)
{
    return 0;
}
