#include <stdio.h>
#include <stdlib.h>
#include "TadVoo.h"


/*
void nicializa(TipoVoo *voo,char *HorarioVoo,char *HorarioPouso,char *AeroportoDecolagem,char *AeroportoPouso, int IdentificadorPista)
{
    strcpy(voo->HorarioVoo, NULL);
    strcpy(voo->HorarioPouso, NULL);
    strcpy(voo->AeroportoDecolagem, NULL);
    strcpy(voo->AeroportoPouso, NULL);
    voo->IdentificadorPista = 0;
}
*/
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
