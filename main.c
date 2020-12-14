#include <stdio.h>
#include <stdlib.h>
#include "tourniquet.h"

int main(int c , char **arg)
{
    int x , i  , q;
    FILE *fichier = NULL ;
    Process **tab = NULL ;

    if( c == 3 )
    {
	tab = malloc(sizeof(Process*)) ;
			       
	fichier = fopen("sortie.txt" , "r") ;
	
	if(fichier != NULL)
	{
	    x = atoi(arg[1]);
	    q = atoi(arg[2]) ;
	    
	    if(tab != NULL)
	    {
		tab[0] = malloc(sizeof(Process*)*x) ;
		for(i = 0 ; i < x ; i++)
		    tab[i] = scan_process(i+1) ;

		tourniquet(tab , x , q) ;
		print(fichier , tab , x) ;

		fclose(fichier) ;
		free_process(tab , x);
	    }
	}
    }

    else
	printf("\n Usage : ./tourniquet arg1[nmbre_processus] arg2[quantum] \n\n") ;

    return 0 ;	    
}
