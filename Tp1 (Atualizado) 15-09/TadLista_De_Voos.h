#include <stdio.h>
#include <stdlib.h>
#include "TadVoo.h"

typedef struct TipoCelula *TipoApontador;

typedef struct TipoCelula
{
  TipoVoo voo;
  TipoApontador Prox;
}TipoCelula;

typedef struct
{
  TipoApontador Primeiro, Ultimo;
}TipoLista;



void FazListaVazia(TipoLista *ListaVoo);

int VerificaVazia(TipoLista ListaVoo);

void InsereVoo(TipoLista *ListaVoo, TipoVoo voo);

TipoVoo *RetornaVooIdentificador(TipoLista *ListaVoo, int VID, TipoVoo *VooRemovido, int *flag);

void imprimeLista(TipoLista ListaVoo);

int ProcuraVoo(TipoLista *ListaVoo, int VID, TipoVoo *Retorno, int *flag);
