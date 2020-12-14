#include <stdio.h>
#include <stdlib.h>
#include "tourniquet.h"


void tri_AT(Process **tab , int size)
{
    int i, j, k ;
    Process *C = NULL ;
    
    for(i = 0 ; i < size-1 ; i++)
    {
        if(tab[i]->AT > tab[i+1]->AT)
	{
	    C = tab[i] ;
	    tab[i] = tab[i+1] ;
	    tab[i+1] = C ;
	}
	
        for(j = i ; j > 0 ; j--)
	    if(tab[j-1]->AT > tab[j]->AT)
	    {
		C = tab[j-1] ;
		tab[j-1] = tab[j] ;
		tab[j] = C ;
	    }
    }
}

void copie_BT(Process **tab , int size , int *copie)
{
    int i ;

    for( i = 0 ; i < size ; i++)
	copie[i] = tab[i]->BT ;
}

int search_ct(Process **tab , int size)
{
    int i , ct = tab[0]->AT ;

    for(i = 1 ; i < size ; i++)
	if(tab[i]->AT < ct)
	    ct = tab[i]->AT ;
    return ct ; 
}


void tourniquet(Process **tab , int size , int quantum)
{
    int time , count , remain = size , check = 0  , copie[size];

    tri_AT(tab , size) ;
    copie_BT(tab , size , copie) ;
    
    for(time = search_ct(tab , size) , count = 0 ; remain !=0 ;)
    {
	if(copie[count] <= quantum &&  tab[count]->status != EXECUTE)
	{
	    time += tab[count]->BT ;
	    tab[count]->status = EXECUTE ;
	    check = 1 ;
	}

	else if(tab[count]->status != EXECUTE)
	{
	    copie[count] -= quantum ;
	    time += quantum ;
	    tab[count]->status = BLOQUER ;
	    printf("\t P%d", tab[count]->id);
	}


	if(tab[count]->status == EXECUTE && check == 1)
	{
	    remain -- ;
	    printf("\t P%d", tab[count]->id);
	    tab[count]->CT = time ;
	    check = 0 ;
	}

	if(count == size-1)
	    count = 0 ;

	else if(tab[count+1]->AT <= time)
	    count ++ ;

	else
	    count = 0 ;
    }
    printf("\n") ;

    calc(tab , size) ;
}
