#include <stdio.h>
#include <stdlib.h>
#include "TadLista_De_Voos.h"


void FazListaVazia(TipoLista *ListaVoo)
{ ListaVoo->Primeiro = (TipoApontador) malloc(sizeof(TipoCelula));
  ListaVoo->Ultimo = ListaVoo->Primeiro;
  ListaVoo->Ultimo->Prox = NULL;
}



int VerificaVazia(TipoLista ListaVoo)
{
    return (ListaVoo.Ultimo == ListaVoo.Primeiro);

}



void InsereVoo(TipoLista *ListaVoo, TipoVoo voo)
{
    TipoApontador i, aux;
    i = ListaVoo->Primeiro;
    while(i->Prox != NULL)
    {
        if((strcmp(i->Prox->voo.HorarioVoo, voo.HorarioVoo) >= 0))
        {
            aux = (TipoApontador) malloc(sizeof(TipoCelula));
            aux->voo = voo;
            aux->Prox = i->Prox;
            i->Prox = aux;
            return;
        }
       i = i->Prox;
    }
    ListaVoo->Ultimo->Prox = (TipoApontador) malloc(sizeof(TipoCelula));
    ListaVoo->Ultimo = ListaVoo->Ultimo->Prox;
    ListaVoo->Ultimo->voo = voo;
    ListaVoo->Ultimo->Prox = NULL;
}


TipoVoo *RetornaVooIdentificador(TipoLista *ListaVoo, int VID, TipoVoo *VooRemovido, int *flag)
{
    if(VerificaVazia(*ListaVoo) != 1){
        printf("Error: Lista Vazia.\n");
        return;
    }
    TipoApontador i, aux;
    i = ListaVoo->Primeiro;
    aux = ListaVoo->Primeiro->Prox;

    while((aux != NULL))
    {
        if(aux->voo.VID == VID)
        {
            *VooRemovido = aux->voo;
            i->Prox = aux->Prox;
            free(aux);
            if(ListaVoo->Primeiro->Prox == NULL)
            ListaVoo->Ultimo = ListaVoo->Primeiro;
            *flag = 1;
            return VooRemovido;
        }
        i = aux;
        aux = aux->Prox;
    }
}



int ProcuraVoo(TipoLista *ListaVoo, int VID, TipoVoo *Retorno, int *flag)
{
    if (VerificaVazia(*ListaVoo) != 1){
        printf("Erro: Lista vazia\n");
        return 0;
}
    TipoApontador i, aux;
    i = ListaVoo->Primeiro;
    aux = i->Prox;
    while(i->Prox != NULL){
        if(i->Prox->voo.VID == VID){
            *Retorno = aux->voo;
            *flag = 1;
        }
        i = i->Prox;
    }
}




void imprimeLista(TipoLista ListaVoo){
    TipoApontador aux; //Crio um ponteiro auxiliar para percorrer a lista
    aux = ListaVoo.Primeiro->Prox; //Faço o ponteiro ser igual ao ponteiro prox do primeiro elemento da lista(célula cabeça)
    while(aux != NULL){ //Enquanto o ponteiro próx(próximo) não apontar para NULL
        imprimeVoo(aux->voo);
        aux = aux->Prox; //Incrementa meu ponteiro para o próximo elemento da lista
    }
}



