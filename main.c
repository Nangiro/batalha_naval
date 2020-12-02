/*
    OBS:    O PROGRAMA CONTEM COMANDOS DE LIMPAR TELA QUE PRECISAM SER DESCOMENTADOS DEPENDENDO DO SISTEMA OPERACIONAL

    Bruno Lima Murakami             - RA 20124673
    Fernando Ken Ichi Kira Saeki    - RA 20127387
    João Victor de Faria e Souza    - RA 20017026
    Rafael Andrade Daher Daibes     - RA 19086818

    Bem-vindo ao nosso trabalho final de APC B!
    Fizemos este programa como uma forma de concluir todo o aprendizado que tivemos durante esse semestre, ele foi feito seguindo todas as condições pré-estabelecidas pela Professora Angela e utilizando a Linguagem C.
    
    Observações importantes:
    - O programa é quase uma réplica do jogo de tabuleiro, Batalha Naval, mas aqui só você afunda os navios, adivinhando em quais quadrados estão os navios escondidos,
    sendo o objetivo principal afundar todos os barcos.
    - Você pode jogar ele até, no máximo, 3 vezes. Sendo que ao final de cada vitória você pode escolher continuar ou não para a próxima fase.
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <ctype.h>

void welcome() //Exibe cabeçalho
{
    printf(" -----------------------\n");
    printf("|\tBATALHA NAVAL\t|\n");
    printf(" -----------------------\n");
}

void endGame() //Exibe mensagem final
{
    printf(" -------------------------------\n");
    printf("|\tOBRIGADO POR JOGAR\t|\n");
    printf(" -------------------------------\n");
}

int menu() //Exibe menu para jogar ou sair
{
    int selection;
    int flag = 0;

    do
    {
        printf(" -----------------------\n");
        printf("|\tMENU\t\t|\n");
        printf(" -----------------------\n");
        printf("| 1\tJOGAR\t\t|\n");
        printf("| 2\tSAIR\t\t|\n");
        printf(" -----------------------\n");
        printf("OPÇÃO:\t");
        scanf("%d", &selection);
        if ((selection<1) || (selection>2)) // Validando opcoes
        {
            printf("OPCAO INVALIDA\nFAVOR SELECIONAR UMA OPCAO VALIDA\n");
        }
        else
        {
            flag = 1;
        }
        
        
    } while (flag != 1);
    
    
    system("clear"); //LINUX
    //system("cls"); //Windows
    return selection;
}

int ** createMatrix () //Cria matriz dinamicamente e insere 0 em todas as posições
{
    int **mat;
    int i; //aux para for

    mat = (int**) calloc (10, sizeof (int*));
    if (mat == NULL)
    {
        printf("Erro ao alocar matriz\n");
        exit(1);
    }

    for (i=0; i<10; ++i)
    {
        mat[i] = (int*) calloc (10, sizeof(int));
        if (mat[i] == NULL)
        {
            printf("Erro ao alocar matriz\n");
            exit(1);
        }
    }

    return mat;
}

void hidingFleet(int** mat, int playedTimes) //Função que recebe a matriz para esconder a frota naval, a cada jogo novo o jogador sera colocado em um mapa diferente. Apos jogar 3x seguidas o programa se encerara automaticamente 
{
    switch (playedTimes)
    {
    case 0:
        mat[8][1] = 1; // Submarino 1

        mat[3][2] = 1; // Submarino 2

        mat[6][4] = 1; // Submarino 3

        mat[0][9] = 1; // Submarino 4

        mat[6][0] = 1; // Destroier 1A
        mat[6][1] = 1; // Destroier 1B

        mat[4][4] = 1; // Destroier 2A
        mat[3][4] = 1; // Destroier 2B

        mat[1][4] = 1; // Destroier 3A
        mat[1][5] = 1; // Destroier 3B

        mat[0][0] = 1; // Bombardeiro 1A
        mat[1][0] = 1; // Bombardeiro 1B
        mat[2][0] = 1; // Bombardeiro 1C
        mat[3][0] = 1; // Bombardeiro 1D

        mat[8][4] = 1; // Bombardeiro 2A
        mat[8][5] = 1; // Bombardeiro 2B
        mat[8][6] = 1; // Bombardeiro 2C
        mat[8][7] = 1; // Bombardeiro 2D

        mat[2][8] = 1; // Encouraçado 1A
        mat[3][8] = 1; // Encouraçado 1B
        mat[4][8] = 1; // Encouraçado 1C
        mat[5][8] = 1; // Encouraçado 1D
        mat[6][8] = 1; // Encouraçado 1E
        break;

    case 1:
        mat[9][0] = 1; // Submarino 1

        mat[7][1] = 1; // Submarino 2

        mat[8][3] = 1; // Submarino 3

        mat[9][5] = 1; // Submarino 4

        mat[1][4] = 1; // Destroier 1A
        mat[2][4] = 1; // Destroier 1B

        mat[1][7] = 1; // Destroier 2A
        mat[1][8] = 1; // Destroier 2B

        mat[3][9] = 1; // Destroier 3A
        mat[4][9] = 1; // Destroier 3B

        mat[0][2] = 1; // Bombardeiro 1A
        mat[1][2] = 1; // Bombardeiro 1B
        mat[2][2] = 1; // Bombardeiro 1C
        mat[3][2] = 1; // Bombardeiro 1D

        mat[6][8] = 1; // Bombardeiro 2A
        mat[7][8] = 1; // Bombardeiro 2B
        mat[8][8] = 1; // Bombardeiro 2C
        mat[9][8] = 1; // Bombardeiro 2D

        mat[5][2] = 1; // Encouraçado 1A
        mat[5][3] = 1; // Encouraçado 1B
        mat[5][4] = 1; // Encouraçado 1C
        mat[5][5] = 1; // Encouraçado 1D
        mat[5][6] = 1; // Encouraçado 1E
        break;

    case 2:
        mat[6][3] = 1; // Submarino 1

        mat[9][3] = 1; // Submarino 2

        mat[8][5] = 1; // Submarino 3

        mat[9][8] = 1; // Submarino 4

        mat[1][3] = 1; // Destroier 1A
        mat[2][3] = 1; // Destroier 1B

        mat[3][5] = 1; // Destroier 2A
        mat[4][5] = 1; // Destroier 2B

        mat[6][7] = 1; // Destroier 3A
        mat[7][7] = 1; // Destroier 3B

        mat[6][1] = 1; // Bombardeiro 1A
        mat[7][1] = 1; // Bombardeiro 1B
        mat[8][1] = 1; // Bombardeiro 1C
        mat[9][1] = 1; // Bombardeiro 1D

        mat[1][8] = 1; // Bombardeiro 2A
        mat[2][8] = 1; // Bombardeiro 2B
        mat[3][8] = 1; // Bombardeiro 2C
        mat[4][8] = 1; // Bombardeiro 2D

        mat[0][1] = 1; // Encouraçado 1A
        mat[1][1] = 1; // Encouraçado 1B
        mat[2][1] = 1; // Encouraçado 1C
        mat[3][1] = 1; // Encouraçado 1D
        mat[4][1] = 1; // Encouraçado 1E
        break;
    
    default:
        break;
    }
}

void printMatrix(int **mat) //Funcao que imprime a matriz mostrando o indice de linhas e colunas
{
    int i, j;

    printf("      1   2   3   4   5   6   7   8   9   10\n");
    printf("    -----------------------------------------\n");
    for(i=0; i<10;++i)
    {
        switch (i)
        {
        case 0:
            printf("A   ");
            break;
        
        case 1:
            printf("B   ");
            break;
        
        case 2:
            printf("C   ");
            break;
        
        case 3:
            printf("D   ");
            break;

        case 4:
            printf("E   ");
            break;

        case 5:
            printf("F   ");
            break;

        case 6:
            printf("G   ");
            break;

        case 7:
            printf("H   ");
            break;

        case 8:
            printf("I   ");
            break;

        case 9:
            printf("J   ");
            break;
        
        default:
            break;
        }

        printf("|");
        for(j=0; j<10; ++j)
        {
            if ((mat[i][j] == 0) || (mat[i][j] == 1))
            {
                printf("   |");
            }
            else if(mat[i][j] == -1)
            {
                printf(" ~ |");
            }
            else
            {
                printf(" x |");
            }
            
        } 
        printf("\n    -----------------------------------------\n");
    }
}

void shot(char * l, int *c) //Funcao que faz a leitura de onde o usuario deseja atirar e realiza a validacao da opcao
{
    int flag =0;


    do
    {
        printf("ONDE DESEJA ATIRAR?\n[LINHA: A - J]\n[COLUNA: 1 - 10]\nDIGITE [LETRA+NUMERO]:\n");
        getchar();
        scanf("%c%d", l, c);

        *l = toupper (*l); // Transforma a letra para maiuscula
        *c = *c -1;
        
        if (*l == 80)
        {
            printf("ENCERRANDO O JOGO\n");
            exit(1);
        }

        if ((*l > 64) && (*l < 75))
        {
            if ((*c > -1) && (*c < 10 ))
            {
                flag = 1;
            }
            else
            {   
                printf("------- POSICAO INVALIDA -------\n");
                printf("DIGITE UMA POSICAO [Linha X Coluna] VALIDA\n\n");
            }
        }
        else
        {
            printf("------- POSICAO INVALIDA -------\n");
            printf("DIGITE UMA POSICAO [Linha X Coluna] VALIDA\n\n");
        }

    } while (flag!=1);

}

int checkShot (char letra, int col, int **mat) // Atualiza a matriz de acordo com o tiro do usuario
{
    int linha;

    // Convertendo letra para numero
    switch (letra)
    {
    case 'A':
        linha = 0;
        break;

    case 'B':
        linha = 1;
        break;

    case 'C':
        linha = 2;
        break;

    case 'D':
        linha = 3;
        break;

    case 'E':
        linha = 4;
        break;
    
    case 'F':
        linha = 5;
        break;
    
    case 'G':
        linha = 6;
        break;
    
    case 'H':
        linha = 7;
        break;
    
    case 'I':
        linha = 8;
        break;

    default: //J - A verificacao para que so sejam essas opcoes foi feita na funcao shot
        linha = 9;
        break;
    }

    // o mudar 0 para -1: representando ÀGUA (erro);
    // o mudar 1 para 2: acerto

    if (mat[linha][col]== 0) //errou
    {
        mat[linha][col] = -1;
    }
    else //acertou
    {
        mat[linha][col] = 2;
        return 1;
    }
    
    return 0;
}

int ** freeMatrix (int **v) //Libera espaco alocado dinamicamente para matriz
{
    int i;
    if (v == NULL)
    {
        return (NULL);
    }
    
    for (i=0; i<10; i++)
    {
        free (v[i]);
    }
    free (v);
    return (NULL);
} 

void startGame(int *times) //Quando o jogador seleciona jogar caira nessa funcao, a qual é responsavel por criar a matriz correta dependendo do numeros de vezes que o usuario jogoum responsavel tambem por todo controle do jogo.
{
    int **matSetup; // Matriz que contém a frota escondida
    char lineShot;
    int collumShot;
    int flag=0; // Flag para controle de repeticao
    int gotShot=0; 
    int win = 23;

    switch (*times)
    {
    case 0:
        matSetup = createMatrix (); //Aloca espaço dinamicamente
        hidingFleet(matSetup, *times); //Esconde a frota

        do
        {
            system("clear"); //LINUX
            //system("cls"); //Windows
            printMatrix(matSetup); //Imprime a matriz
            shot(&lineShot, &collumShot); //Faz a leitura do tiro
            gotShot += checkShot (lineShot, collumShot, matSetup); // Verifica se o tiro acertou ou não o alvo

            if(gotShot == win) //Quando toda a frota é derrotada o jogo acaba
            {
                flag = 1;
                printf("PARABENS, VOCE VENCEU!!!\n");
            }

        } while (flag != 1);
        
        matSetup = freeMatrix (matSetup);
        break;

    case 1:
        matSetup = createMatrix ();
        hidingFleet(matSetup, *times);

        do
        {
            system("clear"); //LINUX
            //system("cls"); //Windows
            printMatrix(matSetup);
            shot(&lineShot, &collumShot);
            gotShot += checkShot (lineShot, collumShot, matSetup);

            if(gotShot == win)
            {
                flag = 1;
                printf("PARABENS, VOCE VENCEU!!!\n");
            }

        } while (flag != 1);
        
        matSetup = freeMatrix (matSetup);
        break;

    case 2:
        matSetup = createMatrix ();
        hidingFleet(matSetup, *times);

        do
        {
            system("clear"); //LINUX
            //system("cls"); //Windows
            printMatrix(matSetup);
            shot(&lineShot, &collumShot);
            gotShot += checkShot (lineShot, collumShot, matSetup);

            if(gotShot == win)
            {
                flag = 1;
                printf("PARABENS, VOCE VENCEU!!!\n");
            }

        } while (flag != 1);
        
        matSetup = freeMatrix (matSetup);
        break;
    
    default: //Verificar
        system("clear"); //LINUX
        //system("cls"); //Windows
        break;
    }

}

int main()
{
    int menuSelection; //Opcao de selecao do menu
    int timesPlayed=0; //Quantas vezes o jogador ja jogou
    int playAgain; // Salva o desejo ou não de continuar o jogo


    setlocale(LC_ALL,"portuguese");

    welcome();
    do
    {
        menuSelection = menu();

        if (menuSelection == 1)
        {
            startGame(&timesPlayed);
            ++ timesPlayed; //Incrementa num de vezes jogadas para selecionar matrizes diferentes
            if (timesPlayed>2)
            {
                endGame();
                menuSelection =2;
            }
            else
            {
                printf("Deseja jogar novamente?\n");
                printf("[1]\tSim\n[2]\tNao\n");
                scanf("%d", &playAgain);
                if(playAgain == 2)
                {
                    endGame();
                    menuSelection =2;
                }
            }
        }
        else // menuSelection = 2 = sair
        {
            endGame();
        }

    } while (menuSelection != 2);
    

    return 0;
}