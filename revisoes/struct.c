#include <stdio.h>
#include <stdlib.h>


typedef struct aluno{
    char nome[30];
    int matricula;
    int p1;
    int p2;
    int p3;
} a;


int main(){

    printf("Nome do aluno: ");
    scanf("%s", &a.nome);
    return 0;
}