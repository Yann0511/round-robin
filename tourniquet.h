#ifndef TOURNIQUET

#define TOURNIQUET
#define EXECUTE 1
#define NOT_EXECUTE 0
#define BLOQUER 2
#include <stdlib.h>

typedef struct
{
    int id ;
    int AT ;
    int BT ;
    int CT ;
    int TAT ;
    int WT ;
    int RT ;
    int status ;
}Process ;


Process * scan_process(int id) ;

void calc(Process **tab , int size) ;

void free_process(Process **tab , int size) ;

int search_ct(Process **tab , int size) ;

void print(Process **tab , int size) ;

void copie_BT(Process **tab , int size , int *copie) ;

void tourniquet(Process **tab , int size , int quantum) ;

void tri_AT(Process **tab , int size) ;

#endif
