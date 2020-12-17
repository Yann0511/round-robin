#include<stdio.h>
#include<stdlib.h>
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

	return P ;
    }

    else
    {
	printf("\n Erreur allocation échoué") ;
	exit(0) ;
    }
}

void print(Process **tab, int size)
{
    int i ;
    float TAM = 0.0 , TRM = 0.0 , debit = tab[size-1]->CT/size ;

    for(i = 0 ; i < size ; i++)
    {
	TAM += tab[i]->WT ;
	TRM += tab[i]->TAT ;
    }
    
    TAM = TAM/size ;
    TRM = TRM/size ;
    
    printf("\n       Round Robin\n_____________________________________________\n\n");
	
    printf("Processus\t");
    for (int i = 0; i < size; ++i)
	printf("P%d\t",tab[i]->id );
    printf("\n\n");

    printf(" T Arrivée\t");
    for (int i = 0; i < size; ++i)
	printf("%d\t",tab[i]->AT );
    printf("\n\n");

    printf(" T Cycle \t");
    for (int i = 0; i < size; ++i)
	printf("%d\t",tab[i]->BT );
    printf("\n\n");

    printf("T Attente\t");
    for (int i = 0; i < size; ++i)
	printf("%d\t",tab[i]->WT );
    printf("\n\n");

    printf("T Séjour\t");
    for (int i = 0; i < size; ++i)
	printf("%d\t",tab[i]->TAT);
    printf("\n\n");

    printf("Temps d'attente moyen : %.2f\nTemps de rotation moyen : %.2f\nDebit : %.2f\n\n",TAM,TRM,debit );
}

void free_process(Process **tab , int size)
{
    int i ;

    for(i = 0 ; i < size ; i++)
	free(tab[i]) ;

    free(tab);
}
