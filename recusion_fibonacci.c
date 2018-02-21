#include <stdio.h>

int fibonacci_m(int N, int known_result[])
{
    if( N>=1 && N<=46 )  //Result for N=47 is too big for int
    {   if( known_result[N]==0 )
        {   if( N==1 )    
                known_result[N]=1;
		        else
		            known_result[N] = fibonacci_m(N-1, known_result) + known_result[N-2];
	      }    
        return known_result[N];
    }
    else
    {   printf("Invalid entry. Please enter 1 to 46.\n");
		    return 0;
	  }
}

int main()
{
    int N;
    int known[50] = {0}; 
    
    printf("Please enter a number N (1 to 46): ");
    scanf("%d", &N);

    printf("Fibonacci(%d) is %d\n", N, fibonacci_m(N, known));
   
    return 0;
}
