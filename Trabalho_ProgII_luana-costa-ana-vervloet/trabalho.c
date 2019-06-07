// Trabalho Computacional de Programação II - 2019/1
// Ciência da Computação
//     Alunas:
//         Ana Carolina Vervloet dos Santos
//         Luana Gabriele de Sousa Costa

// Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>


// Função que calcula a média parcial de um caso
void mediaParcial(float p1, float p2, float p3, float p4, float mParcial){
    int i;
    float menor = 10, soma;

// Soma de todas as notas (incluindo a menor)
    soma = p1 + p2 + p3 + p4;

// Condicionais para descobrir a menor nota
    if(menor >= p1){
        menor = p1;
    }

    if(menor >= p2){
        menor = p2;
    }

    if(menor >= p3){
        menor = p3;
    }

    if(menor >= p4){
        menor = p4;
    }

    soma = soma - menor;

    mParcial = soma/3;
}

// Função que calcula a média final de um caso
void mediaFinal(float p1, float p2, float p3, float p4, float mParcial, float pf, float mFinal){
    
    mediaParcial(p1, p2, p3, p4, mParcial);

    mFinal = (mParcial + pf)/2;
}

// Struct que armazena nome e notas de um aluno
struct aluno{
    char nome[30];
    float p[5];
}; 

// Função principal
int main(){
    FILE *entrada, *saida;
    struct aluno a;
    int i, j, m;
    char nomeEntrada[20];

// Pedindo as informações pelo teclado
    printf("Digite o nome dos arquivos de entrada: ");
// Loop para percorrer 10 arquivos
    for(i = 0; i < 10; i++){
    // Pega o nome de cada arquivo
        scanf("%s", nomeEntrada);
    // Abre o arquivo
        entrada = fopen(nomeEntrada, "r");

        for(j = 0; j < 10; j++){
            fgets(a.nome, sizeof(entrada), entrada);
            fscanf(entrada, "%f %f %f %f %f", &a.p[0], &a.p[1], &a.p[2], &a.p[3], &a.p[4]);

            printf("%s", a.nome);
            for(m = 0; m < 5; m++){
                printf("%f", a.p[m]);
            }

        }

    // Fecha o arquivo e vai para o próximo loop
        fclose(entrada);
    }
    
    return 0;
}