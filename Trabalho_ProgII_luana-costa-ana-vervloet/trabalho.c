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


struct turmasNovas{
    char nome[30][10];
    float mP[10];
    float mF[10];
};

// Declaração de tipo struct
typedef struct aluno Aluno;
typedef struct passei Passei;
typedef struct turmasNovas Turmas;

// Função que preenche o struct de cada turma de PA;
void preencheTurmas(Passei *p, Turmas *t, int numeroTurmas, int contaAprovados, int resto){
    int i, j, aux;

    // Se o resto for igual a zero significa que todas as turmas possuem 10 alunos
    // e, assim, posso preencher todas de forma igual
    if(resto == 0){
        // Loop que varre o vetor de structs
        for(i = 0; i < numeroTurmas - 1; i++){
            // Loop que varre o vetor de cada elemento do struct
            for(j = 0; j < 10; j++){
                // Variável auxiliar com valor maximo igual a 'contaAprovados'
                aux = j + i * 10;
                // Copia nome
                strcpy(t[i].nome[j], p[aux].nome);
                // Copia media parcial
                t[i].mP[j] = p[aux].mediaParcial;
                // Copia media final
                t[i].mF[j] = p[aux].mediaFinal;
            }
        }
    // Caso contrario há uma turma que o numero de loops nao sera 10, mas sim o valor
    // de 'resto'
    } else{
        // Loop que varre o vetor de structs
        for(i = 0; i < numeroTurmas - 1; i++){
            // Condicional para verificar se nao é o último loop
            if(i != numeroTurmas - 1){
                // Loop que varre o vetor de cada elemento do struct
                for(j = 0; j < 10; j++){
                    // Variável auxiliar com valor maximo igual a 'contaAprovados'
                    aux = j + i * 10;
                    // Copia nome
                    strcpy(t[i].nome[j], p[aux].nome);
                    // Copia media parcial
                    t[i].mP[j] = p[aux].mediaParcial;
                    // Copia media final
                    t[i].mF[j] = p[aux].mediaFinal;
                }
            // Caso seja o último loop ele faz um loop que varre 10
            } else{
                // Loop que varre o vetor de cada elemento do struct
                for(j = 0; j < resto - 1; j++){
                    // Variável auxiliar com valor maximo igual a 'contaAprovados'
                    aux = j + i * 10;
                    // Copia nome
                    strcpy(t[i].nome[j], p[aux].nome);
                    // Copia media parcial
                    t[i].mP[j] = p[aux].mediaParcial;
                    // Copia media final
                    t[i].mF[j] = p[aux].mediaFinal;
                }
            }
        }
    }



    for(i = 0; i < numeroTurmas - 1; i++){
        if(i != numeroTurmas-1){
            for(j = 0; j < 10; j++){
                printf("%s turma %i: mp - %.2f mf - %.2f\n", t[i].nome[j], i, t[i].mP[j], t[i].mF[j]);
            }
        } else{
            for(j = 0; j < resto - 1; j++){
                printf("%s turma %i: mp - %.2f mf - %.2f\n", t[i].nome[j], i, t[i].mP[j], t[i].mF[j]);
            }
        }
    }
}

// Função que verifica quais alunos da turma de PB foram aprovados e retorna a quantidade
int verificaAprovados(char nome[30][100], float *mP, float *mF, Passei *p){
    int i, j = 0;

    // For para preencher o struct 'passei'
    for(i = 0; i < 100; i++){

        // Condicional que verifica alunos acima da média
        if(mF[i] >= 6){
            // Atribuição de valores do aluno na struct se tiver passado
            strcpy(p[j].nome, nome[i]);
            p[j].mediaParcial = mP[i];
            p[j].mediaFinal = mF[i];

            // Contador do numero de alunos aprovados
            j++;
        }
    }

    // for(i = 0; i < j; i++){
    //     printf("fora do loop%i - %s\nmp:%.2f mf:%.2f\n", i, p[i].nome, p[i].mediaParcial, p[i].mediaFinal);
    // }

    // Retorna o contador de alunos aprovados
    return j;
}

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
    int i, j, m, count = 0, contaAprovados, numeroTurmas, resto;
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

    // Chama a função que preenche o struct de aprovados
    contaAprovados = verificaAprovados(nomesPB, mP, mF, p);

    resto = contaAprovados%10;

    if(resto != 0){
        numeroTurmas = contaAprovados/10 + 1;
    } else{
        numeroTurmas = contaAprovados/10 ;
    }

    Turmas t[numeroTurmas];

    preencheTurmas(p, t, numeroTurmas, contaAprovados, resto);

    // printf("CONTADOR DE APROVADOS: %i\n", contaAprovados);

    // for(i = 0; i < contaAprovados; i++){
    //     printf("fora do loop%i - %s\nmp:%.2f mf:%.2f\n", i, p[i].nome, p[i].mediaParcial, p[i].mediaFinal);
    // }

    // for(i = 0; i < 100; i++){
    //     printf("%s:\n", nomesPB[i]);
    //     printf("%i mP . %.2f mF . %.2f\n", i, mP[i], mP[i]);
    // }
    
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