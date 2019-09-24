#include <stdio.h>

void print_row ( int space, int hash, 
		 int row, int height )

{	int i;

	for( i=1; i<=space; i++ )		//print space
		printf( " " );

	if( row==1 || row==height )		//print first and last rows
	{	for( i=1; i<=hash; i++ )
 			printf( "#" );
	}
	else					//print rows with hollow
	{	printf( "#" );
		for( i=1; i<=hash-2; i++ )
			printf( "." );
		printf( "#" );
	}
}	

void pyramid_hollow( int height )
{	int row;
	for( row=1; row<=height; row++ )
	{	int space = height-row;
		int hash = 2*row-1;
		
	    	print_row( space, hash, row, height );  
		printf( "\n" );
	}
}

int main()
{   	int height;

    	printf("Enter height of pyramid: ");
    	scanf("%d", &height);
	printf( "\n" );
    	pyramid_hollow(height);
	return 0;
}
/*
OUTPUT for height = 4
---------------------
   #
  #.#
 #...#
#######
*/
