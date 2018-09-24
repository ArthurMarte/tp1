#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "TadLista_De_Voos.h"


typedef struct
{
    TipoLista ListaVoo;
    int NumeroVoos;
    char HorarioAtualiza[6];
}TipoMatrizItem;


void InicializaMatrizItem(TipoMatrizItem *ItemMatriz);

TipoLista GetListaVoo(TipoMatrizItem *ItemMatriz);
void SetListaVoo(TipoMatrizItem *Item, TipoLista ListaVoo);

int GetNumeroVoos(TipoMatrizItem *ItemMatriz);
void SetNumeroVoos(TipoMatrizItem *ItemMatriz, int NumeroVoos);

char *GetHorarioAtualiza(TipoMatrizItem *ItemMatriz);
void SetHorarioAtualiza(TipoMatrizItem *ItemMatriz, char *HorarioAtualiza);



