/*
primes.c
--------
<init_primes> sets all values in the array primes to 1.

<sieve_primes> implements the Sieve of Eratosthenes algorithm to remove non-primes.
If a number i is non-prime, primes[i] will be set to 0.

The idea comes from the fact that multiples of a prime are not primes. 
To find all primes from 2 to n, remove all multiples of 2 up to n.
The smallest remaining number will be 3, which is the next prime. 
Remove all other multiples of 3 to get 5 as the next prime.
Continue this process until no numbers can be removed. 
The remaining numbers will be all primes from 2 to n.

<print_primes> prints all primes from 2 to n.
*/

#include <stdio.h>
#include <stdbool.h>

void init_primes(bool primes[], int n) 
{
    primes[0]=0;         
    primes[1]=0;        
    
    for (int i=2; i<=n; i++)
       primes[i]=1;       
}
void sieve_primes(bool primes[], int size, int k) 
{   for (int i=k+k; i<size; i+=k)               
        primes[i]=0;
}

void print_primes(int n) 
{
    bool primes[n+1];    
    init_primes(primes,n);
    
    for (int i=2; i<=n; i++)
    {   if (primes[i])              // if (primes[i]==1) 
            sieve_primes(primes,n+1,i);
    }
    
    for (int i=2; i<=n; i++)
    {   if (primes[i])
           printf("%d ",i);
    }    
}

int main(void)
{   // Edit the number n to test
    print_primes(50);
    return 0;
}

/*
OUTPUT
------
2 3 5 7 11 13 17 19 23 29 31 37 41 43 47
*/
