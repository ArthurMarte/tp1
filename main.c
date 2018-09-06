#include <stdio.h>
#include <stdlib.h>
#include "TadVoo.h"
int main()
{
    TipoVoo voo, *voo1;
    int vid;
    voo1 = &voo;
    Inicializa(voo1);
    SetVid(voo1, rand());
    vid = GetVid(voo1);
    printf("Seu voo é: %d\n", vid);
    return 0;
}
