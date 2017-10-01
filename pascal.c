/*
pascal.c
--------

choose(n,k) returns nCk
pascal_triangle(row) returns the entire row for the input row number (0 to 29) of the pascal's triangle
*/


#include <stdio.h>

int choose(int n, int k) 
{
    int nCk = 1;
    
    if (n >= 0 && n <= 29 && k >= 0 && k <= n)
    {
        if (k==0 || k==n)         // includes (n==0 && k==0)
        {   return 1;
        }
        else if (k==1)
        {   return n;
        }
        else 
        {   if (k > n/2)
            {   k = n - k;
            }
 
            for (int i=1; i<=k; ++i)
            {   nCk *= n/i;
                n -= 1;
            }
            return nCk;
        }        
    }
    else
    {  if (n < 0 || k < 0 || n > 29 || k > 29)
       {   printf("n and k must be from 0 to 29, and k must not be larger than n.\n");
       }
       else 
       {   printf("k must not be larger than n.\n");
       }
       return -1;
    }   
}

 
void pascal_triangle(int row) 
{
    if (row >= 0 && row <= 29)
    {   for(int i = 0; i <= row; ++i)            
        {   printf("%d ",choose(row,i));        
        }
        printf("\n");
    }
    else
    {   printf("Row must be from 0 to 29.\n");
    } 
}
