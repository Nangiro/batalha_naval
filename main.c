/*
    Fernando Ken Ichi Kira Saeki - 20127387
*/

#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

void welcome()
{
    printf(" ---------------\n");
    printf("| BATALHA NAVAL |\n");
    printf(" ---------------\n");
}

int main()
{
    setlocale(LC_ALL,"portuguese");

    welcome();

    return 0;
}