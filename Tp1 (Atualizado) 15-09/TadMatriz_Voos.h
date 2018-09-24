#include <stdio.h>
#include <stdlib.h>
#include "TadItem_Matriz.h"
#define MAXTAM 24
#include <time.h>


typedef struct
{
    TipoMatrizItem Matriz[MAXTAM][MAXTAM];
    char Data[11];
    int TotalVoos;
    char HorarioAtualiza[6]
}TipoMatriz;

int ConverteHorario(char *horario);

void InicializaMatrizVoo(TipoMatriz *MatrizVoo);

void InsereVooMatriz(TipoMatriz *MatrizVoo, TipoVoo Voo);

void RemoveVooMatriz(TipoMatriz *MatrizVoo, int VID);

void ProcuraVooMatriz(TipoMatriz *MatrizVoo, int VID);

void ImprimirVooHoras(TipoMatriz *MatrizVoo, char *HorarioVoo, char *HorarioPouso);

void ImprimirHoraDecolagem(TipoMatriz *MatrizVoo, char *HorarioVoo);

void ImprimirHoraPouso(TipoMatriz *MatrizVoo, char *HorarioPouso);

void ImprimeMatriz(TipoMatriz *MatrizVoo);

void FaixaHorarioMaiorNum(TipoMatriz *MatrizVoo);

void UltimaAltera(TipoMatriz *MatrizVoo);


int VerificaeEsparca(TipoMatriz *MatrizVoo);

