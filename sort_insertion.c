#include <stdio.h>
#include <stdbool.h>

void sort( int arr[], int size )
{   	int i, j;
	int temp;
	
	for( i=1; i<=size-1; i++ ) 	// i=0 card is already in your hand, start from i=1 card
	{   	temp = arr[i];		// i card
	  
	   	for( j=i-1; j>=0; j-- )		// check with all the cards before the i card
		{	if( arr[j] > temp )	// if j card > i card
			{	arr[j+1] = arr[j];	//swap j+1 card becomes j card (shift one card forward)
				arr[j] = temp;		//j card becomes i card
			}					
		}		
	}				  
}

/* EXAMPLE
arr[]={5,4,3,2}
i=1 arr[1]=4	temp=4
		j=0	arr[0]=5	
		5>4
			arr[1]=5	
			arr[0]=4	{4,5,3,2}
		
i=2 arr[2]=3	temp=3
		j=1	arr[1]=5
		5>3
			arr[2]=5
			arr[1]=3	{4,3,5,2}

		j=0	arr[0]=4
		4>3
			arr[1]=4
			arr[0]=3	{3,4,5,2}
i=size-1=3  
    arr[3]=2	temp=2
		j=2
		j=1
		j=0

*/

int main()
{   int arr[5]={5,4,3,2,1};
    int size = 5;
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
