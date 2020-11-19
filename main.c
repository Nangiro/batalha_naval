/*
    Fernando Ken Ichi Kira Saeki - 20127387
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void welcome()
{
    printf(" -----------------------\n");
    printf("|\tBATALHA NAVAL\t|\n");
    printf(" -----------------------\n");
}

int menu()
{
    int selection;
    printf(" -----------------------\n");
    printf("|\tMENU\t\t|\n");
    printf(" -----------------------\n");
    printf("| 1\tJOGAR\t\t|\n");
    printf("| 2\tSAIR\t\t|\n");
    printf(" -----------------------\n");
    printf("OPÇÃO:\t");
    scanf("%d", &selection);
    system("clear"); //LINUX
    system("cls"); //Windows

    return selection;
}

int main()
{
    int menuSelection;

    setlocale(LC_ALL,"portuguese");

    welcome();
    menuSelection = menu();

    return 0;
}