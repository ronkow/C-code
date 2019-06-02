//To sort an array of integers from smallest to largest

#include <stdio.h>
#include <stdbool.h>

void swap( int arr[], int first, int next  )
{   int temp = arr[first];

    arr[first] = arr[next];
    arr[next] = temp;
}

void sort( int arr[], int size )
{   	int i, j;
	int max_index;
    
	  for( i=size-1; i>=1; i-- )    	//number of passes = size-1
	  {   	max_index = i;          	//index i contains the last unsorted number
	   					//assume this number is the largest
	      	//compare [index i number] with all the numbers before it
		//find the largest number and swap it with [index i number]
	   
	        for( j=0; j<=i-1; j++ )		
		{   if( arr[j] > arr[max_index] )
		          max_index = j;
		}
	   	if( max_index != i)
	      		swap(arr, max_index, i); 
	  }
}

//BigO analysis:
// for size N
// i has size-1 iterations and 1 op = N-1 ops
// j has (N-1)+(N-2)+...+1 iterations/comparisions = (N-1)/2 (1 + N -1)
// max ops is N(N-1)/2 * 2 = N(N-1) = N^2 - N
// max total ops is N^2 - N + N - 1 = N^2 - 1

int main()
{   
    int arr[5]={5,4,3,2,1};
    int size=5;
    sort(arr, size);
 
    for( int i=0; i<=size-1; i++ )
    	printf("%d ", arr[i]);
    
    return 0;
}

/* EXAMPLE
size=4
arr[]={4,3,2,1}
i=3	arr[3]=1	assume this is the largest of all numbers. max_index=3
compare with 	j=0	arr[0]=4 > 1 max_index=0
		j=1
		j=2
swap index 0 and index 3

arr[]={1,3,2,4}	arr[3] is now sorted
i=2	arr[2]=2	assume this is the largest of first 3 numbers. max_index=2
compare with 	j=0
		j=1	arr[1]=3 > 2 max_index=1
swap index 1 and index 2

arr[]={1,2,3,4}		arr[2] is now sorted
i=1	arr[1]=2	assume this is the largest of first 2 numbers. max_index=1
compare with	j=0	
no swap
*/
