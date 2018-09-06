#include <stdio.h>
#include <stdlib.h>
#include "TadVoo.h"


void Inicializa(TipoVoo *voo){
    voo = NULL;
}

int GetVid(TipoVoo *voo)
{
    return voo->VID;
}
int SetVid(TipoVoo *voo, int VID)
{
    voo->VID = VID;
    return 0;
}


char GetHorarioPouso(TipoVoo *voo)
{
    return voo->HorarioPouso;
}
void SetHorarioPouso(TipoVoo *voo, char HorarioPouso)
{
    strcpy(voo->HorarioPouso, HorarioPouso);
}


char GetAeroportoDecolagem(TipoVoo *voo)
{
    return voo->AeroportoDecolagem;
}
void SetAeroportoDecolagem(TipoVoo *voo, char AeroportoDecolagem)
{
    strcpy(voo->AeroportoDecolagem, AeroportoDecolagem);
}


char GetAeroportoPouso(TipoVoo *voo)
{
    return voo->AeroportoPouso;
}
void SetAeroportoPouso(TipoVoo *voo, char AeroportoPouso)
{
    strcpy(voo->AeroportoPouso, AeroportoPouso);
}


int GetIdentificadorPista(TipoVoo *voo)
{
    return voo->IdentificadorPista;
}
void SetIdentificadorPista(TipoVoo *voo, int IdentificadorPista)
{
    voo->IdentificadorPista = IdentificadorPista;
}

int converteHorario(char *horario){
    int i,minutosTotal = 0;
    for(i=0;i<5;i++){
        horario[i] = horario[i] - 48;
    }
    minutosTotal += (horario[0] * 10) * 60;
    minutosTotal += horario[1] * 60;
    minutosTotal += horario[3] * 10;
    minutosTotal += horario[4];
    return minutosTotal;
}

