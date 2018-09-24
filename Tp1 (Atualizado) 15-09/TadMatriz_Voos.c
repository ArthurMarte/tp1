#include <stdio.h>
#include <stdlib.h>
#define MAXTAM 24
#include "TadMatriz_Voos.h"



void InicializaMatrizVoo(TipoMatriz *MatrizVoo)
{
     int cont1, cont2;
     for(cont1=0; cont1<MAXTAM; cont1++)
     {
         for(cont2=0; cont2<MAXTAM; cont2++)
         {
           InicializaItemMatriz(&(MatrizVoo->Matriz[cont1][cont2]));
         }
    }
     MatrizVoo->Data[0] = '0';
     MatrizVoo->HorarioAtualiza[0] = '0';
     MatrizVoo->TotalVoos = 0;
}



int ConverteHorario(char *horario)
{
    int i, converte[6], HorarioFinal = 0;
    for(i=0; i<2; i++)
    {
        converte[i] = horario[i] - 48;
    }
    HorarioFinal = converte[0] * 10;
    HorarioFinal += converte[1];

return HorarioFinal;
}



void InsereVooMatriz(TipoMatriz *MatrizVoo, TipoVoo Voo)
{
    int Decolagem, Pouso;
    TipoLista ListaVoo;
    FazListaVazia(&ListaVoo);
    InsereVoo(&ListaVoo, Voo);

    Decolagem = ConverteHorario(Voo.HorarioVoo);
    Pouso = ConverteHorario(Voo.HorarioPouso);
    ListaVoo = GetListaVoo(&MatrizVoo->Matriz[Decolagem][Pouso].ListaVoo);
    InsereVoo(&ListaVoo, Voo);

    MatrizVoo->Matriz[Decolagem][Pouso].NumeroVoos++;
    MatrizVoo->TotalVoos++;

    printf("Voo inserido com sucesso.\n");
}



void RemoveVooMatriz(TipoMatriz *MatrizVoo, int VID)
{
    TipoVoo Voo;
    int cont1, cont2, flag;
    for(cont1=0; cont1<MAXTAM; cont1++)
    {
        for(cont2=0; cont2<MAXTAM; cont2++)
        {
            {
                RetornaVooIdentificador(&MatrizVoo->Matriz[cont1][cont2].ListaVoo, VID, &Voo, &flag);
            }
        }
    }
    if(flag == 1)
    {
        printf("Voo removido com sucesso.\n");
    }
    else
    {
        printf("Error: Identificador invalido.\n");
    }
}




void ProcuraVooMatriz(TipoMatriz *MatrizVoo, int VID)
{
    TipoVoo Voo;
    int cont1, cont2, flag;
    for(cont1=0; cont1<MAXTAM; cont1++)
    {
        for(cont2=0; cont2<MAXTAM; cont2++)
        {
            ProcuraVoo(&MatrizVoo->Matriz[cont1][cont2].ListaVoo, VID, &Voo, &flag);
        }
    }
    if(flag == 1)
    {
    imprimeVoo(Voo);
    }
    else
    {
     printf("Error: Identificador invalido.\n");
    }
}




void ImprimirVooHoras(TipoMatriz *MatrizVoo, char *HorarioVoo, char *HorarioPouso)
{
    int Decolagem, Pouso;
    TipoLista ListaVoo;
    Decolagem = ConverteHorario(HorarioVoo);
    Pouso = ConverteHorario(HorarioPouso);
    ListaVoo = GetListaVoo(&MatrizVoo->Matriz[Decolagem][Pouso]);
    imprimeLista(ListaVoo);
}



void ImprimirHoraDecolagem(TipoMatriz *MatrizVoo, char *HorarioVoo)
{
    int Decolagem;
    int cont;
    TipoLista ListaVoo;
    Decolagem = ConverteHorario(HorarioVoo);
    for(cont=0; cont<MAXTAM; cont++)
    {
        ListaVoo = GetListaVoo(&MatrizVoo->Matriz[Decolagem][cont]);
        imprimeLista(ListaVoo);
    }
}



void ImprimirHoraPouso(TipoMatriz *MatrizVoo, char *HorarioPouso)
{
    int Pouso;
    int cont;
    TipoLista ListaVoo;
    Pouso = ConverteHorario(HorarioPouso);
    for(cont=0; cont<MAXTAM; cont++)
    {
        ListaVoo = GetListaVoo(&MatrizVoo->Matriz[cont][Pouso]);
        imprimeLista(ListaVoo);
    }
}



void ImprimeMatriz(TipoMatriz *MatrizVoo)
{
    TipoLista ListaVoo;
    int cont1, cont2;
    if (MatrizVoo->TotalVoos == 0)
    {
        printf("Error: Matriz Vazia\n");
    }
    for(cont1=0; cont1<MAXTAM; cont1++)
    {
        for(cont2=0; cont2<MAXTAM; cont2++)
        {
            ListaVoo = GetListaVoo(&MatrizVoo->Matriz[cont1][cont2]);
            imprimeLista(ListaVoo);
        }
    }
}



void FaixaHorarioMaiorNum(TipoMatriz *MatrizVoo)
{
    int cont1, cont2, Maior;
    int i = 0, j = 0;
    Maior = MatrizVoo->Matriz[0][0].NumeroVoos;
    for(cont1=0; cont1<MAXTAM; cont1++)
    {
        for(cont2=0; cont2<MAXTAM; cont2++)
        {
            if(MatrizVoo->Matriz[cont1][cont2].NumeroVoos > Maior)
            {
                i = cont1;
                j = cont2;
                Maior = MatrizVoo->Matriz[cont1][cont2].NumeroVoos;
            }
        }
    }
   printf("A matriz com maior numero de voos: i = %d, j = %d, Quantidade de Voos: %d\n", i, j, Maior);
}

void FaixaHorarioMenorNum(TipoMatriz *MatrizVoo)
{
    int cont1, cont2, Menor;
    int i = 0, j = 0;
    Menor = MatrizVoo->Matriz[0][0].NumeroVoos;
    for(cont1=0; cont1<MAXTAM; cont1++)
    {
        for(cont2=0; cont2<MAXTAM; cont2++)
        {
            if(MatrizVoo->Matriz[cont1][cont2].NumeroVoos < Menor)
            {
                i = cont1;
                j = cont2;
                Menor = MatrizVoo->Matriz[cont1][cont2].NumeroVoos;
            }
        }
    }
   printf("A matriz com o menor numero de voos: i = %d, j = %d, Quantidade de Voos: %d\n", i, j, Menor);
}


void UltimaAltera(TipoMatriz *MatrizVoo)
{
    int cont1, cont2;
    int i=0, j=0;
    char teste[MAXTAM];
    *teste = MatrizVoo->Matriz[0][0].HorarioAtualiza;

    for(cont1=0;cont1<MAXTAM;cont1++)
    {
        for(cont2=0;cont2<MAXTAM;cont2++)
        {
            if(strcmp(MatrizVoo->Matriz[cont1][cont2].HorarioAtualiza, teste) < 0)
            {
                *teste = MatrizVoo->Matriz[0][0].HorarioAtualiza;
                i = cont1;
                j = cont2;
            }
        }
    }
    printf("Indices da posicao encontrada: i=%d, j=%d e horario da ultima atualizacao = %s\n", i, j, teste);
}













int VerificaEsparca(TipoMatriz *MatrizVoo)
{
    int SemVoos = 0, ComVoos = 0;
    int cont1, cont2;
    for(cont1=0; cont1<MAXTAM; cont1++)
    {
        for(cont2=0; cont2<MAXTAM; cont2++)
        {
            if(VerificaVazia(MatrizVoo->Matriz[cont1][cont2].ListaVoo))
            {
                SemVoos++;
            }
            else
            {
                ComVoos++;
            }
        }
    }
    if(SemVoos >= (ComVoos*2))
    {
        printf("A matriz eh esparca.\n");
    }
    else
    {
        printf("A matriz nao eh esparca.\n");


    }
    return 0;
}
