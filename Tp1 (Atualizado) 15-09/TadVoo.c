#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "TadVoo.h"

int GeraAleatorio()
{
    return rand() % 1000000;
}



void Inicializa(TipoVoo *voo){
    voo->HorarioVoo[0] = '0';
    voo->HorarioPouso[0] = '0';
    voo->AeroportoDecolagem[0] = '0';
    voo->AeroportoPouso[0] = '0';
    voo->IdentificadorPista = 0;
    voo->VID = GeraAleatorio();
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


char *GetHorarioVoo(TipoVoo *voo)
{
    return voo->HorarioVoo;
}
void SetHorarioVoo(TipoVoo *voo, char *HorarioVoo)
{
    strcpy(voo->HorarioVoo, HorarioVoo);
}


char *GetHorarioPouso(TipoVoo *voo)
{
    return voo->HorarioPouso;
}
void SetHorarioPouso(TipoVoo *voo, char *HorarioPouso)
{
    strcpy(voo->HorarioPouso, HorarioPouso);
}


char *GetAeroportoDecolagem(TipoVoo *voo)
{
    return voo->AeroportoDecolagem;
}
void SetAeroportoDecolagem(TipoVoo *voo, char *AeroportoDecolagem)
{
    strcpy(voo->AeroportoDecolagem, AeroportoDecolagem);
}


char *GetAeroportoPouso(TipoVoo *voo)
{
    return voo->AeroportoPouso;
}
void SetAeroportoPouso(TipoVoo *voo, char *AeroportoPouso)
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



void imprimeVoo(TipoVoo voo)
{
        printf("VID: %d\n", GetVid(&voo)); //
        printf("Hora Decolagem: %s\n", GetHorarioVoo(&voo));
        printf("Hora Prevista para Pouso: %s\n", GetHorarioPouso(&voo));
        printf("Aeroporto Decolagem: %s\n", GetAeroportoDecolagem(&voo));
        printf("Aeroporto Previsto para Pouso: %s\n", GetAeroportoPouso(&voo));
        printf("Pista de Decolagem: %d\n\n", GetIdentificadorPista(&voo));
}
