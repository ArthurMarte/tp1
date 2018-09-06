#include <stdio.h>
#include <stdlib.h>
#include "TadLista_De_Voos.h"


void FazListaVazia(TipoLista *Lista)
{ Lista -> Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  Lista -> Ultimo = Lista -> Primeiro;
  Lista -> Primeiro -> Prox = NULL;
}



void InsereVoo(TipoLista *Lista, TipoVoo voo)
{
    TipoApontador i, aux;
    i = Lista->Primeiro;
    while((i->Prox != NULL) && (converteHorario(i->Prox->voo.HorarioVoo) < converteHorario(voo.HorarioVoo)))
    {
        i = i->Prox;
    }
    aux = (TipoApontador) malloc(sizeof(TipoCelula));
    aux->voo = voo;
    aux->Prox = i->Prox;
    i->Prox = aux;
}

void Imprime(TipoLista Lista)
{ TipoApontador Aux;
  Aux = Lista.Primeiro -> Prox;
  while (Aux != NULL)
    { printf("%d\n", Aux->voo.HorarioVoo);
      Aux = Aux -> Prox;
    }
}
