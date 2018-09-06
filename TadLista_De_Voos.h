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



void FazListaVazia(TipoLista *Lista);

void InsereVoo(TipoLista *Lista, TipoVoo voo);

void Imprime(TipoLista Lista);
