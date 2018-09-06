#include <stdio.h>
#include <stdlib.h>
#include "TadVoo.h"
#include "TadLista_De_Voos.h"
#include "TadLista_De_Voos.c"
#include "TadVoo.c"
int main()
{
    TipoVoo voo1, voo2, voo3;
    Inicializa(&voo1);
    Inicializa(&voo2);
    Inicializa(&voo3);
    SetAeroportoDecolagem(&voo1, "xesque");
    SetAeroportoPouso(&voo1, "xesque");
    SetHorarioPouso(&voo1, "xesque");
    SetHorarioVoo(&voo1, "17:30");
    SetIdentificadorPista(&voo1, 30);
    SetVid(&voo1, 30);
    SetAeroportoDecolagem(&voo2, "xesque");
    SetAeroportoPouso(&voo2, "xesque");
    SetHorarioPouso(&voo2, "xesque");
    SetHorarioVoo(&voo2, 20:45);
    SetIdentificadorPista(&voo2, 30);
    SetVid(&voo2, 30);
    SetAeroportoDecolagem(&voo3, "xesque");
    SetAeroportoPouso(&voo3, "xesque");
    SetHorarioPouso(&voo3, "xesque");
    SetHorarioVoo(&voo3, "15:22");
    SetIdentificadorPista(&voo3, 31);
    SetVid(&voo3, 20);

    TipoLista lista;
    FazListaVazia(&lista);
    InsereVoo(&lista, voo)
    return 0;
}
