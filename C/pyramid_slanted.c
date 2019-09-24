#include <stdio.h>
		
void pyramid_slanted( int height )
{  	int row;

	for( row=1; row<=height; row++ )  
	{  	for(int i=0; i<row; i++ ) 
			printf( "#" );
        	printf( "\n" );
	}
}

int main()
{   int height;

    printf("Enter height of pyramid: ");
    scanf("%d", &height);
    printf( "\n" );
    pyramid_slanted (height);
    return 0;
}

/*
OUTPUT for height = 4
---------------------
#
##
###
####
*/
