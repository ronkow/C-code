#include <stdio.h>
	
// prints rows for symmetric pyramid
void print_row( int space_length, 
                int hash_length )
{   	int i;
  	for( i=0; i<space_length; i++ )
	    	printf( " " );
 
   	for( i=0; i<hash_length; i++ )
        	printf( "#" );
}


void pyramid_symmetric( int height )
{   	int row;

	for( row=1; row<=height; row++ )
	{	int space = height-row;
		int hash = 2*row-1;

		print_row( space, hash );
		printf( "\n" );
	}
}

int main()
{   	int height;
    	printf("Enter height of pyramid: ");
    	scanf("%d", &height);
	printf( "\n" );
    	pyramid_symmetric (height);
	return 0;
}

/*
OUTPUT for height = 4
---------------------
   #
  ###
 #####
#######
/*
