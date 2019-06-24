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


struct bolsista{
    char nome[30];
    float mP;
    float mF;
};

struct auxiliar{
    char nome[30];
    float mP;
    float mF;
};

// Declaração de tipo struct
typedef struct aluno Aluno;
typedef struct passei Passei;
typedef struct turmasNovas Turmas;
typedef struct bolsista Bolsista;
typedef struct auxiliar Aux;

// Função que preenche o struct de cada turma de PA;
void preencheTurmas(Passei *p, Turmas *t, int numeroTurmas, int contaAprovados, int resto){
    int i, j, aux;

    // Se o resto for igual a zero significa que todas as turmas possuem 10 alunos
    // e, assim, posso preencher todas de forma igual
    if(resto == 0){
        // Loop que varre o vetor de structs
        for(i = 0; i < numeroTurmas; i++){
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
        for(i = 0; i < numeroTurmas; i++){
            // Condicional para verificar se nao é o último loop
            if(i < numeroTurmas - 1){
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
                for(j = 0; j < resto; j++){
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
}

void verificaEmpates(Bolsista *b, int numeroNota, int *bolsistas){
    int i, j;

    if(numeroNota > 5){
        // // se os 6 forem iguais
        // if(b[0].mF == b[1].mF && b[1].mF == b[2].mF && b[2].mF == b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF)
        // // se 2 - 6 for igual
        // if(b[0].mF != b[1].mF && b[1].mF == b[2].mF && b[2].mF == b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF){
        //     for(i = 0; i < 4; i++){
        //         printf("%s\n", b[0].nome);
        //     }
        // }
        // // se 3 - 6 for igual
        // if(b[1].mF != b[2].mF && b[2].mF == b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF){
        //     for(i = 0; i < 2; i++){
        //         printf("%s\n", b[i].nome);
        //     }

        // }
        // se 4 - 6 for igual
        if(b[2].mF != b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF){
            // Printa os 3 primeiros elementos
            for(i = 0; i < 3; i++){
                printf("%s\n", b[i].nome);
            }
            // Verifica se o 5 elemento é o menor
            if(b[4].mF < b[5].mF &&  b[4].mF < b[3].mF){
                printf("%s\n%s\n", b[3].mF, b[5].nome);            
            }
            // Verifica se o 4 elemento é o menor
            if(b[3].mF < b[5].mF &&  b[3].mF < b[4].mF){
                printf("%s\n%s\n", b[4].mF, b[5].nome);            
            }
            // Verifica se o 6 elemento é o menor
            if(b[5].mF < b[4].mF &&  b[5].mF < b[3].mF){
                printf("%s\n%s\n", b[3].mF, b[4].nome);            
            }
            
            if(b[5].mF == b[4].mF &&  b[5].mF <= b[3].mF){
                printf("%s\n%s\n%s\n", b[3].mF, b[4].nome, b[5].nome);            
            }

            if(b[5].mF == b[4].mF &&  b[5].mF > b[3].mF){
                printf("%s\n%s\n", b[4].nome, b[5].nome);            
            }

            if(b[3].mF == b[4].mF &&  b[3].mF <= b[5].mF){
                printf("%s\n%s\n%s\n", b[3].mF, b[4].nome, b[5].nome);            
            }

            if(b[3].mF == b[4].mF &&  b[3].mF > b[5].mF){
                printf("%s\n%s\n", b[3].nome, b[4].nome);            
            }

        }
        
        // se o 6 for menor
        if(b[4].mF != b[5].mF){
            for(i = 0; i < 5; i++){
                printf("%s\n", b[i].nome);
            }
        }

    } else{
        for(i = 0; i <  numeroNota; i++){
            printf("%s\n", b[i].nome);
        }
    }
}

/*
casos
    se os 6 forem iguais
        if(b[0].mF == b[1].mF && b[1].mF == b[2].mF && b[2].mF == b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF)
    se 2 - 6 for igual
        if(b[0].mF != b[1].mF && b[1].mF == b[2].mF && b[2].mF == b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF){
            for(i = 0; i < 4; i++){
                printf("%s\n", b[0].nome);
            }
        }
    se 3 - 6 for igual
        if(b[1].mF != b[2].mF && b[2].mF == b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF){
            for(i = 0; i < 2; i++){
                printf("%s\n", b[i].nome);
            }
        }
    se 4 - 6 for igual
        if(b[2].mF != b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF){
            for(i = 0; i < 3; i++){
                printf("%s\n", b[i].nome);
            }
        }
    se 5 - 6 for igual
        f(b[3].mF != b[4].mF && b[4].mF == b[5].mF){
            for(i = 0; i < 4; i++){
                printf("%s\n", b[i].nome);
            }
        }
    se o 6 for menor
        if(b[4].mF != b[5].mF){
            for(i = 0; i < 5; i++){
                printf("%s\n", b[i].nome);
            }
        }
*/

// Função que ordena por média final os possíveis bolsistas
void ordenaStruct(Bolsista *b, int numeroNota){
    int h, i;
    Aux a;

    // Primeiro preciso ordenar o struct pela média final
    // Loop vindo do último até o primeiro
    for(i = numeroNota - 1; i > 0; i--){
        // Loop vindo do último até o primeiro
        for(h = 0; h < i; h++){
            // Condicional para ver qual elemento é maior (dois em dois)
            if(b[h].mF > b[h + 1].mF){
                // Passa o primeiro elemento da comparacao para a auxiliar
                strcpy(a.nome, b[h].nome);
                a.mP = b[h].mP;
                a.mF = b[h].mF;

                // Passa o segundo elemento da comparacao para o primeiro
                strcpy(b[h].nome, b[h + 1].nome);
                b[h].mP = b[h + 1].mP;
                b[h].mF = b[h + 1].mF;

                // Passa a auxiliar para o segundo elemento
                strcpy(b[h + 1].nome, a.nome);
                b[h + 1].mP = a.mP;
                b[h + 1].mF = a.mF;
            }
        }
    }
    for(i = 0; i < numeroNota; i++){
        printf("ordenado: %i - %s p - %.2f f - %.2f\n", i, b[i].nome, b[i].mP, b[i].mF);
    }
}


void finalizaNota(Bolsista *b, int numeroNota){
    int bolsistas[100];

    ordenaStruct(b, numeroNota);
    verificaEmpates(b, numeroNota, bolsistas);
}

// Função que verifica dos que passaram os que estão acima de 9,4
int verificaNota(Passei *p, Bolsista *b, int contaAprovados){
    int i, j = 0;

    // Loop para percorrer todo o vetor de aprovados
    for(i = 0; i < contaAprovados; i++){
        // Condicional para armazenar apenas os acima de 9,4
        if(p[i].mediaFinal >= 9.5){
            // Copia o nome
            strcpy(b[j].nome, p[i].nome);
            // Copia a media parcial
            b[j].mP = p[i].mediaParcial;
            // Copia a media final
            b[j].mF = p[i].mediaFinal;
            // Aumenta o número do contador
            j++;
        }
    }

    for(i = 0; i < j; i++){
        printf("Alunos acima de 9,4: %s p-%.2f f-%.2f\n", b[i].nome, b[i].mP, b[i].mF);
    }

    return j;
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

void leArquivos(float *mP, float *mF, char nomes[30][100]){
    int i, j, count = 0;
    char nomeEntrada[20];
    FILE *entrada;
    Aluno a;

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
            
            count = j + i*10;

            // Chama a função que calcula a média da posição
            medias(a.p1, a.p2, a.p3, a.p4, a.pf, mP, mF, count);
            strcpy(nomes[count], a.nome);
        }



        // Fecha o arquivo e vai para o próximo loop
        fclose(entrada);
    }
}

void gerenciaBolsista(Passei *p, Bolsista *b, int contaAprovados){
    int numeroNota;
    // Função que retorna o número de notas acima de 9,4 e
    // armazena os mesmos num struct
    numeroNota = verificaNota(p, b, contaAprovados);

    // Condicional para verificar se há alunos com média acima de 9,4
    if(numeroNota == 0){
        printf("Nenhum aluno aprovado de PB alcaçou Média Final >= 9,5.\n");
    } else{
        finalizaNota(b, numeroNota);
    }
}


void gerenciaAprovados(int contaAprovados, int resto, int numeroTurmas, Passei *p, Bolsista *b){
    Turmas t[10]; // O número máximo de turmas é 10;

    // Condicional para verificar se há aprovados
    if(contaAprovados == 0){
        printf("Não foram geradas nenhuma turma de PA devido à falta de alunos aprovados em PB.\n");
    } else{
        // Condional para preencher o valor de numero de turmas
        if(resto != 0){
            numeroTurmas = contaAprovados/10 + 1;
        } else{
            numeroTurmas = contaAprovados/10 ;
        }

        gerenciaBolsista(p, b, contaAprovados);

        preencheTurmas(p, t, numeroTurmas, contaAprovados, resto);

        // for(i = 0; i < contaAprovados; i++){
        //     printf("fora do loop%i - %s\nmp:%.2f mf:%.2f\n", i, p[i].nome, p[i].mediaParcial, p[i].mediaFinal);
        // }
    }
}

void gerenciaFuncoes(float *mP, float *mF, char nomes[30][100], Passei *p, Bolsista *b){
    int contaAprovados, numeroTurmas, resto, numeroNota;
    Turmas t[10]; // O número máximo de turmas é 10;

    leArquivos(mP, mF, nomes);

    // Chama a função que preenche o struct de aprovados
    contaAprovados = verificaAprovados(nomes, mP, mF, p);

    resto = contaAprovados%10;

    gerenciaAprovados(contaAprovados, resto, numeroTurmas, p, b);
}




// Função principal
int main(){
    FILE *saida;
    Passei p[100]; // O númeiro máximo de alunos que podem passar é 100
    Bolsista b[100]; // O número máximo de alunos coma a média >= 9,5 é 100
    char nomes[30][100];
    float mP[100], mF[100];

    // Função que gerencia operaçoes
    gerenciaFuncoes(mP, mF, nomes, p, b);

    return 0;
}


/*
https://pt.stackoverflow.com/questions/72494/printar-strings-em-ordem-alfab%C3%A9tica

para estudo de ordem alfabética
- preciso revisar o funcionamento de bibliotecas.


-> LISTA DE AFAZERES
    . ver os que passaram, anotar o nome, a média parcial e a média final


teste1.txt teste2.txt teste3.txt teste4.txt teste5.txt teste6.txt teste7.txt teste8.txt teste9.txt teste10.txt
*/