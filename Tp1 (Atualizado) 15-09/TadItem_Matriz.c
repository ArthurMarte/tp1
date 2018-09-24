#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "TadItem_Matriz.h"


void InicializaItemMatriz(TipoMatrizItem *ItemMatriz)
{
    FazListaVazia(&ItemMatriz->ListaVoo);
    ItemMatriz->NumeroVoos = 0;
    strcpy(ItemMatriz->HorarioAtualiza, __TIME__);
}



TipoLista GetListaVoo(TipoMatrizItem *ItemMatriz)
{
    return ItemMatriz->ListaVoo;
}
void SetListaVoo(TipoMatrizItem *ItemMatriz, TipoLista ListaVoo)
{
    ItemMatriz->ListaVoo = ListaVoo;
}



int GetNumeroVoos(TipoMatrizItem *ItemMatriz)
{
    return ItemMatriz->NumeroVoos;
}
void SetNumeroVoos(TipoMatrizItem *ItemMatriz, int NumeroVoos)
{
    ItemMatriz->NumeroVoos = NumeroVoos;
}



char *GetHorarioAtualiza(TipoMatrizItem *ItemMatriz)
{
    return ItemMatriz->HorarioAtualiza;
}
void SetHorarioAtualiza(TipoMatrizItem *ItemMatriz, char *HorarioAtualiza)
{
    strcpy(ItemMatriz->HorarioAtualiza,HorarioAtualiza);
}




