#include <stdio.h>
#include <stdlib.h>
#include "TadInterface.h"

#define TAMNOMEARQUIVO 200
#define BUFFERSIZE 255


void imprimeCabecalho () {
    printf("|| ||\n");
    printf("->->->    Trabalho Pratico 1 de \"Algoritmos e Estruturas de Dados\"\n");
    printf("->->->    Setembro de 2017 - UFV Campus Florestal\n");
    printf("->->->    Arthur Marciano, Andre Elias e Jhorrane Aguiar\n");
    printf("|| ||\n");
    //printf("\nO programa irá pedir pra que você digite um código após cada operação executada. Basta digitar o código requisitado pra a operação ser executada. \n\n");
}


void imprimeLinha () {
    int i;
    printf("\n");
    for (i = 0; i < 100; i++) {
        printf("-");
    }
    printf("\n\n");
}


void imprimeProcedimentos()
{
    printf("Os procedimentos disponiveis sao: \n\n");
    printf("Insira a \t->\t Inicializar matriz.\n");
    printf("Insira b \t->\t Inserir voo.\n");
    printf("Insira c \t->\t Remover voo atraves do identificador(VID).\n");
    printf("Insira d \t->\t Procurar voo atraves do identificar(VID).\n");
    printf("Insira e \t->\t Imprimir voo, dado horario de decolagem e horario de pouso.\n");
    printf("Insira f \t->\t Imprimir voo, dado o horario de decolagem.\n");
    printf("Insira g \t->\t Imprimir voo, dado o horario de pouso.\n");
    printf("Insira h \t->\t Imprimir toda a matriz.\n");
    printf("Insira i \t->\t Encontrar a faixa de horario e pouso com maior numero de voos cadastrados.\n");
    printf("Insira j \t->\t Encontrar a faixa de horario e pouso com menor numero de voos cadastrados.\n");
    printf("Insira k \t->\t Encontrar a lista de voos mais recentemente alterada.\n");
    printf("Insira l \t->\t Encontrar a lista de voos menos recentemente alterada.\n");
    printf("Insira m \t->\t Verifica se a matriz eh esparca.\n");
    printf("Insira x \t->\t Encerra o programa.\n\n");
}


int SelecionaModo()
{
    int modo;
    printf("Escolha o modo a ser utilizado:\n");
    printf("1 -> Interativo.\n2 -> Arquivo.\n");
    printf("->->: ");
    scanf("%d", &modo);
    if(modo == 1){
        printf("Voce optou pelo modo Interativo.\n");
        ModoInterativo();
    }
    else if(modo == 2){
        printf("Voce optou pelo modo Arquivo.\n");
        ModoArquivo();
    }
    else{
        printf("Modo invalido.\n");
        printf("Escolha um modo valido.\n\n");
        SelecionaModo();
    }
    return 0;
}

int ModoInterativo()
{
    TipoMatriz MatrizVoo;
    TipoVoo Voo;
    int retorno = 0;
    char codigo;
    char HorarioVoo[6], HorarioPouso[6], AeroportoDecolagem[10], AeroportoPouso[10];
    int IdentificadorPista, VID;


    Inicializa(&Voo);
    imprimeLinha();
    imprimeProcedimentos();


    while(retorno == 0)
    {
        printf("Digite o codigo do procedimento que deseja executar:");
        fflush(stdin);
        scanf("%c", &codigo);

        switch (codigo)
        {
            case 'a':
                InicializaMatrizVoo(&MatrizVoo);
                printf("Matriz inicializada com sucesso.\n");
                imprimeLinha();
                break;

            case 'b':
                printf("Entre com os dados do voo:\n");
                printf("Horario de decolagem:");
                scanf("%s", &HorarioVoo);
                printf("Horario de pouso:");
                scanf("%s", &HorarioPouso);
                printf("Aeroporto de decolagem:");
                scanf("%s", &AeroportoDecolagem);
                printf("Aeroporto de pouso:");
                scanf("%s", &AeroportoPouso);
                printf("Identificador da pista de decolagem:");
                scanf("%d", &IdentificadorPista);
                SetHorarioVoo(&Voo, HorarioVoo);
                SetHorarioPouso(&Voo, HorarioPouso);
                SetAeroportoDecolagem(&Voo, AeroportoDecolagem);
                SetAeroportoPouso(&Voo, AeroportoPouso);
                SetIdentificadorPista(&Voo, IdentificadorPista);
                SetVid(&Voo, GeraAleatorio());
                InsereVooMatriz(&MatrizVoo, Voo);
                imprimeLinha();
                break;

            case 'c':
                printf("Insira o identificador do voo (VID) a ser removido:");
                scanf("%d", &VID);
                RemoveVooMatriz(&MatrizVoo, VID);
                imprimeLinha();
                break;

            case 'd':
                 printf("Insira o identificador do voo (VID) a ser procurado:");
                 scanf("%d", &VID);
                 ProcuraVooMatriz(&MatrizVoo, VID);
                 imprimeLinha();
                break;

            case 'e':
                printf("Insira os horarios de decolagem e pouso respectivamente:\n");
                printf("Horario do voo:");
                scanf("%s", &HorarioVoo);
                printf("Horario do pouso:");
                scanf("%s", &HorarioPouso);
                printf("\n");
                ImprimirVooHoras(&MatrizVoo, HorarioVoo, HorarioPouso);
                imprimeLinha();
                break;

            case 'f':
                printf("Insira o horario de decolagem desejado:");
                scanf("%s", &HorarioVoo);
                printf("\n");
                ImprimirHoraDecolagem(&MatrizVoo, HorarioVoo);
                imprimeLinha();
                break;

            case 'g':
                printf("Insira o horario de pouso desejado:");
                scanf("%s", &HorarioPouso);
                printf("\n");
                ImprimirHoraPouso(&MatrizVoo, HorarioPouso);
                imprimeLinha();
                break;

            case 'h':
                ImprimeMatriz(&MatrizVoo);
                imprimeLinha();
                break;

            case 'i':
                FaixaHorarioMaiorNum(&MatrizVoo);
                imprimeLinha();
                break;

            case 'j':
                FaixaHorarioMenorNum(&MatrizVoo);
                imprimeLinha();
                break;

            case 'k':
                break;

            case 'l':
                break;

            case 'm':
                VerificaEsparca(&MatrizVoo);
                imprimeLinha();
                break;

            case 'x':
                retorno = 1;
                break;

            default:
                printf("Codigo invalido!! \n");
                imprimeLinha();
                break;
        }
    }
    return 0;
}


int ModoArquivo()
{
    TipoMatriz MatrizVoo;\
    char nomeArquivo[TAMNOMEARQUIVO]; // Caminho pro arquivo
    char buffer[BUFFERSIZE]; // Buffer de uma linha (255 caracteres)
    char opcao;
    char HorarioVoo[6], HorarioPouso[6], AeroportoDecolagem[10], AeroportoPouso[10];
    int IdentificadorPista, VID;
    FILE *arquivo = NULL; // Arquivo TXT lido


    TipoVoo Voo;
    Inicializa(&Voo);

    printf("Insira o caminho do arquivo, com extensão: ");
    scanf(" %s", nomeArquivo);
    arquivo = fopen(nomeArquivo, "r");
    if (arquivo == NULL)
    {
        printf("O arquivo %s não existe. Encerrando a execução. \n", nomeArquivo);
        return 0;
    }
    else{
        while(fscanf(arquivo, "%s", &opcao) != EOF){
            switch(opcao){
                case 'a':
                    InicializaMatrizVoo(&MatrizVoo);
                    printf("Matriz inicializada com sucesso.\n");
                    break;

                case 'b':
                    fscanf(arquivo, "%s", &HorarioVoo);
                    fscanf(arquivo, "%s", &HorarioPouso);
                    fscanf(arquivo, "%s", &AeroportoDecolagem);
                    fscanf(arquivo, "%s", &AeroportoPouso);
                    fscanf(arquivo, "%d", &IdentificadorPista);

                    SetHorarioVoo(&Voo, HorarioVoo);
                    SetHorarioPouso(&Voo, HorarioPouso);
                    SetAeroportoDecolagem(&Voo, AeroportoDecolagem);
                    SetAeroportoPouso(&Voo, AeroportoPouso);
                    SetIdentificadorPista(&Voo, IdentificadorPista);
                    SetVid (&Voo, GeraAleatorio());
                    InsereVooMatriz(&MatrizVoo, Voo);
                    break;

                case 'c':
                    fscanf(arquivo, "%d", &VID);
                    RemoveVooMatriz(&MatrizVoo, VID);
                    imprimeLinha();
                    break;

                 case 'd':
                     fscanf(arquivo, "%d", &VID);
                     ProcuraVooMatriz(&MatrizVoo, VID);
                     imprimeLinha();
                     break;

                case 'e':
                    fscanf(arquivo, "%s", &HorarioVoo);
                    fscanf(arquivo, "%s", &HorarioPouso);
                    ImprimirVooHoras(&MatrizVoo, HorarioVoo, HorarioPouso);
                    imprimeLinha();
                    break;

                case 'f':
                    fscanf(arquivo, "%s", &HorarioVoo);
                    ImprimirHoraDecolagem(&MatrizVoo, HorarioVoo);
                    imprimeLinha();
                    break;

                case 'g':
                    scanf(arquivo, "%s", &HorarioPouso);
                    ImprimirHoraPouso(&MatrizVoo, HorarioPouso);
                    imprimeLinha();
                    break;

                case 'h':
                    ImprimeMatriz(&MatrizVoo);
                    imprimeLinha();
                    break;

                case 'i':
                    FaixaHorarioMaiorNum(&MatrizVoo);
                    imprimeLinha();
                    break;

                case 'j':
                    FaixaHorarioMenorNum(&MatrizVoo);
                    imprimeLinha();
                    break;

                case 'k':
                    break;

                case 'l':
                    break;

                case 'm':
                    VerificaEsparca(&MatrizVoo);
                    imprimeLinha();
                    break;

                default:
                    printf("Codigo invalido!! \n");
                    imprimeLinha();
                    break;
            }
        }
    }
    fclose(arquivo);
    return 0;
}
