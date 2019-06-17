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



// Struct que armazena nome e notas de um aluno
struct aluno{
    char nome[30];
    float p1;
    float p2;
    float p3;
    float p4;
    float pf;
};

struct passei{
    char nome[30];
    float mediaParcial;
    float mediaFinal;
};

typedef struct aluno Aluno;
typedef struct passei Passei;

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
void mediaFinal(float p1, float p2, float p3, float p4, float mP, float pf, float mF){
    
    mediaParcial(p1, p2, p3, p4, mP);

    mF = (mP + pf)/2;
}

// Função que retorna a média parcial e a final
void medias(float p1, float p2, float p3, float p4, float pf, float *mP, float *mF, int count){
    mediaFinal(p1, p2, p3, p4, mP[count], pf, mF[count]);
}




// Função principal
int main(){
    FILE *entrada, *saida;
    Aluno a;
    Passei p[100];
    int i, j, m;
    char nomeEntrada[20];
    float mP[100], mF[100];

// Pedindo as informações pelo teclado
    printf("Digite o nome dos arquivos de entrada: ");
// Loop para percorrer 10 arquivos
    for(i = 0; i < 10; i++){
    // Pega o nome de cada arquivo
        scanf("%s", nomeEntrada);
    // Abre o arquivo
        entrada = fopen(nomeEntrada, "r");

     // Lê o arquivo
        for(j = 0; j < 10; j++){
            fscanf(entrada, "%s %f %f %f %f %f", a.nome, &a.p1, &a.p2, &a.p3, &a.p4, &a.pf);

            // Teste para garantir o valor das variáveis (apagar)
            printf("\n%s\n", a.nome);
            printf("%.2f ", a.p1);
            printf("%.2f ", a.p2);
            printf("%.2f ", a.p3);
            printf("%.2f ", a.p4);
            printf("%.2f ", a.pf);

            medias(a.p1, a.p2, a.p3, a.p4, a.pf, mP, mF, j);
        }



    // Fecha o arquivo e vai para o próximo loop
        fclose(entrada);
    }
    
    return 0;
}


/*
https://pt.stackoverflow.com/questions/72494/printar-strings-em-ordem-alfab%C3%A9tica

para estudo de ordem alfabética
- preciso revisar o funcionamento de struct e bibliotecas.


-> LISTA DE AFAZERES
    . ver os que passaram, anotar o nome, a média parcial e a média final


    param cont
    for(i = 0; i < 10; i++){
        funcao(*mParcial, i);
    }
    
    void funcao(...){
        mParcial[i] = 10;
    }
*/