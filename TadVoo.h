#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    char HorarioVoo[6], HorarioPouso[6], AeroportoDecolagem[20], AeroportoPouso[20];
    int IdentificadorPista, VID;
}TipoVoo;


void Inicializa(TipoVoo *voo);

int GetVid(TipoVoo *voo);

int SetVid(TipoVoo *voo, int VID);

char GetHorarioVoo(TipoVoo *voo);
void SetHorarioVoo(TipoVoo *voo, char HorarioVoo);

char GetHorarioPouso(TipoVoo *voo);
void SetHorarioPouso(TipoVoo *voo, char HorarioPouso);

char GetAeroportoDecolagem(TipoVoo *voo);
void SetAeroportoDecolagem(TipoVoo *voo, char AeroportoDecolagem);

char GetAeroportoPouso(TipoVoo *voo);
void SetAeroportoPouso(TipoVoo *voo, char AeroportoPouso);

int GetIdentificadorPista(TipoVoo *voo);
void SetIdentificadorPista(TipoVoo *voo, int IdentificadorPista);

int converteHorario(char *horario);




