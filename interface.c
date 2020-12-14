#include <stdio.h>
#include <string.h>
#include "tourniquet.h"

Process * scan_process(int id)
{
    Process* P = malloc(sizeof(Process *)) ;

    if(P != NULL)
    {

	printf("\n Temps d'arrivé de P%d : \t", id) ;

	scanf("%d", &P->AT) ;

	printf("\n Temps de cycle de P%d : \t", id) ;

	scanf("%d", &P->BT) ;

	printf("\n") ;

	P->id = id ;
	P->status = NOT_EXECUTE ;
	P->WT = 0 ;

	return P ;
    }

    else
    {
	printf("\n Erreur allocation échoué") ;
	exit(0) ;
    }
}

void calc(Process **tab , int size)
{
    int i ;

    tab[0]->TAT = tab[0]->CT - tab[0]->AT ;
    tab[0]->WT = tab[0]->TAT - tab[0]->BT ;
    tab[0]->RT = tab[0]->TAT - tab[0]->BT ;

    for(i = 1 ; i < size ; i++)
    {
	tab[i]->TAT = tab[i]->CT - tab[i]->AT ;
	tab[i]->WT = tab[i]->TAT - tab[i]->BT ;
	tab[i]->RT = tab[i]->TAT - tab[i]->BT ;
    }

}


void free_process(Process **tab , int size)
{
    int i ;

    for(i = 0 ; i < size ; i++)
	free(tab[i]) ;
}

void print_entete(FILE *fichier)
{
    int cur = 0 ;

    cur = fgetc(fichier) ;
    
    while(cur != 'X' && !feof(fichier))
    {
	printf("%c", cur);
	cur = fgetc(fichier) ;
    }
}

void search_car(FILE *fichier , char car)
{
    int cur ;
    
    rewind(fichier) ;

    do
    {
	cur = fgetc(fichier) ;
	if(cur == car)
	    break ;
    }while(!feof(fichier)) ;
}
    
    
void print(FILE *fichier , Process **tab , int size)
{
    int cur , i ;

    print_entete(fichier) ;

    for(i = 0 ; i < size ; i++)
    {
	search_car(fichier , 'X') ;
	cur = fgetc(fichier) ;
	do
	{
	    cur = fgetc(fichier) ;
	    
	    if( cur == '1')
		printf("P%d", tab[i]->id);

	    else if(cur == '2')
		printf("%d", tab[i]->AT) ;

	    else if(cur == '3')
		printf("%d", tab[i]->BT) ;

	    else if(cur == '4')
		printf("%d", tab[i]->CT) ;

	    else if(cur == '5')
		printf("%d" , tab[i]->TAT) ;

	    else if(cur =='6')
		printf("%d" , tab[i]->WT) ;

	    else if(cur == '7')
		printf("%d" , tab[i]->RT) ;

	    else if (cur != 'F')
		printf("%c" , cur);
	    
	}while(cur != 'F');
    }
}
