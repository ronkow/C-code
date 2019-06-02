#include <stdio.h>
#include <stdbool.h>

void swap( int arr[], int first, int next  )
{   int temp = arr[first];   
    
    arr[first] = arr[next];  
    arr[next] = temp;	     //arr[next] = arr[first]
}

void sort( int arr[], int size )
{   int i, j;
    bool sorted;

    for( i=size-1; i>=1; i-- )  //number of passes = size-1. Stop at i=1 because we will compare it with i=0
    {   sorted = true;		//assume the sequence is already sorted
	
        //compare arr[j] with the next number, 
        //excluding the k sorted numbers at the end
     
        for( j=1; j<=i; j++ )			//start with j=1 because we will compare it with j=0  
	{   if( arr[j-1] > arr[j])
	    {    swap( arr, j-1, j );
		 sorted = false;   		//if there is a swap, the sequence originally was not sorted
	    }
	}
     
    	if( sorted )	//if there were no swaps, sorted = true, the sequence is sorted
	   return;
    }
}
//BigO analysis:
// size=N
// i has N-1 iterations and 1 op = N-1 ops
// j has (N-1)+(N-2)+(N-3)+...+1 iterations and maximum N-1 ops
// max ops = (N-1)/2 (1+N-1) = (N-1)/2 (N) = N(N-1)/2
// total ops = N(N-1)/2 + (N-1) = 0.5N^2 - 0.5N + N -1 = 0.5N^2 + 0.5N -1

int main()
{   int arr[5]={5,4,3,2,1};
    int size=5;
    sort(arr, size);
 
    for( int i=0; i<=size-1; i++ )
    	printf("%d ", arr[i]);
    
    return 0;
}

/*
OUTPUT
------
1 2 3 4 5
*/
