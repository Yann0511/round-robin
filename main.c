#include <stdio.h>
#include <stdlib.h>
#include "tourniquet.h"

int main(int c , char **arg)
{
    int x , i  , q;

    if( c == 3 )
    {
	x = atoi(arg[1]) ;
	q = atoi(arg[2]) ;
	Process **tab = malloc(sizeof(Process*) *x) ;

	if(tab != NULL)
	{
	    for(i = 0 ; i < x ; i++)
		tab[i] = scan_process(i+1) ;

	    tourniquet(tab , x , q) ;
	    print(tab , x) ;

	    free_process(tab , x);
	}
    }
    
    else
	printf("\n Usage : ./tourniquet arg1[nmbre_processus] arg2[quantum] \n\n") ;

    return 0 ;	    
}
