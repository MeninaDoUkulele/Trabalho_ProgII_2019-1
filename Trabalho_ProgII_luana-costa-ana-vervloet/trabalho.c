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

// Struct para armazenar alunos que passaram em PB
struct passei{
    char nome[30];
    float mediaParcial;
    float mediaFinal;
};

// Declaração de tipo struct
typedef struct aluno Aluno;
typedef struct passei Passei;


// void verificaAprovados(char nome[30][100], float *mP, float *mF, Passei *p){
//     int i, j = 0, aux;

//     for(i = 0; i < 100; i++){

//         if(mF[i] >= 6){
//             // strcpy(nome[i], p->nome[j]);
//             p[i].mediaParcial = mP[i];
//             p[i].mediaFinal = mF[i];
//             j++;
//             printf("dentro do loop%i - mp:%.2f mf:%.2f\n", i, p[i].mediaParcial, p[i].mediaFinal);
//         }
//         if(i == 99){
//             aux = j;
//         }
//     }
//     for(i = 0; i < aux; i++){
//         printf("fora do loop%i - mp:%.2f mf:%.2f\n", i, p[i].mediaParcial, p[i].mediaFinal);
//     }
// }

// Função que calcula a média parcial de um caso
float mediaParcial(float p1, float p2, float p3, float p4){
    float mP, menor = 10, soma;

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

    mP = soma/3;
   
    // Retorna a média parcial
    return mP;
}

// Função que calcula a média final de um caso
float mediaFinal(float p1, float p2, float p3, float p4, float pf){
    float mP, mF;

    // Chama a função que calcula a média parcial
    mP = mediaParcial(p1, p2, p3, p4);

    // Faz o cálculo da média final
    mF = (mP + pf)/2;
    
    // Retorna a média final
    return mF;
}

// Função que retorna a média parcial e a final
void medias(float p1, float p2, float p3, float p4, float pf, float *mP, float *mF, int count){
    // Atribui à posição do contador no momento a media final
    mF[count] = mediaFinal(p1, p2, p3, p4, pf);
    // Atribui à posição do contador no momento a media parcial
    mP[count] = mediaParcial(p1, p2, p3, p4);
    
}




// Função principal
int main(){
    FILE *entrada, *saida;
    Aluno a;
    Passei p[100];
    int i, j, m, count = 0;
    char nomeEntrada[20], nomesPB[30][100];
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
            // printf("\n%s\n", a.nome);
            // printf("%.2f ", a.p1);
            // printf("%.2f ", a.p2);
            // printf("%.2f ", a.p3);
            // printf("%.2f ", a.p4);
            // printf("%.2f ", a.pf);
            
            count = j + i*10;

            // Chama a função que calcula a média da posição
            medias(a.p1, a.p2, a.p3, a.p4, a.pf, mP, mF, count);
            strcpy(nomesPB[count], a.nome);
        }



    // Fecha o arquivo e vai para o próximo loop
        fclose(entrada);
    }

    // verificaAprovados(nomesPB, mP, mF, p);

    for(i = 0; i < 100; i++){
        printf("%s:\n", nomesPB[i]);
        printf("%i mP . %.2f mF . %.2f\n", i, mP[i], mP[i]);
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

teste1.txt teste2.txt teste3.txt teste4.txt teste5.txt teste6.txt teste7.txt teste8.txt teste9.txt teste10.txt
*/