 // Trabalho Computacional de Programação II - 2019/1
// Ciência da Computação
//     Alunas:
//         Ana Carolina Vervloet dos Santos
//         Luana Gabriele de Sousa Costa

// Inclusão de bibliotecas
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxlib.h"




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
typedef struct bolsista Bolsista;
typedef struct auxiliar Aux;


// Função que preenche o struct de cada turma de PA;
void preencheTurmas(Passei *p, int numeroTurmas, int contaAprovados, int resto){
    int i, j, aux;
    char nomeSaida[20], nomes[30][10];
    FILE *saida;

    // Loop que roda a quantidade de turmas
    for(i = 0; i < numeroTurmas; i++){
        printf("Digite o nome do arquivo de saída da turma %i: ", i+1);
        // Armazena o nome do arquivo de saída
        scanf("%s", nomeSaida);

        // Abre o arquivo
        saida = fopen(nomeSaida, "w");

        // Printa o número da turma, apenas por organização
        fprintf(saida ,"Turma %i:\n\n", i + 1);

        // Se uma das turmas não estiver com o número máximo
        if(resto != 0 && i == numeroTurmas - 1){
            // No último loop (última turma formada), muda o parâmetro do for
            for(j = 0; j < resto; j++){
                aux = j + i * 10;
                strcpy(nomes[j], p[aux].nome); 
            }
            // Chama a função que printa e ordena alfabeticamente
            printaAlfabetica(nomes, resto, saida);
        // Caso contrário
        } else{
            // O loop percorre todas as turmas preenchendo com 10 alunos
            for(j = 0; j < 10; j++){
                aux = j + i * 10;
                strcpy(nomes[j], p[aux].nome); 
            }
            // Chama a função que printa e ordena alfabeticamente
            printaAlfabetica(nomes, 10, saida);

        }

        fclose(saida);
    }


}

// Função que ordena as médias parciais
void ordenaParcial(Aux *a, int contador){
    int i, h;
    Aux u;

    // Loop que percorre o vetor de struct
    for(i = contador - 1; i > 0; i--){
        // Loop vindo do último até o primeiro
        for(h = 0; h < i; h++){
            // Condicional para ver qual elemento é maior (dois em dois)
            if(a[h].mF > a[h + 1].mF){
                // Passa o primeiro elemento da comparacao para a auxiliar
                strcpy(u.nome, a[h].nome);
                u.mP = a[h].mP;
                u.mF = a[h].mF;

                // Passa o segundo elemento da comparacao para o primeiro
                strcpy(a[h].nome, a[h + 1].nome);
                a[h].mP = a[h + 1].mP;
                a[h].mF = a[h + 1].mF;

                // Passa a auxiliar para o segundo elemento
                strcpy(a[h + 1].nome, u.nome);
                a[h + 1].mP = u.mP;
                a[h + 1].mF = u.mF;
            }
        }
    }
}


void verificaEmpates(Bolsista *b, int numeroNota){
    int i, j = 0, suplentes, empates, vetorIndice[100];
    Aux a[100];


    printf("\nAlunos bolsistas:\n");

    // Se houverem mais de 5 alunos com média final maior que 9,4
    if(numeroNota > 5){
        printf("ola\n");
            // Condicional para ver se há empates depois do 5 elemento
            if(b[4].mF != b[5].mF){
                for(i = 0; i <  5; i++){
                    printf("%s\n", b[i].nome);
                }
                suplentes = numeroNota - 5;
                printf("%i\n", suplentes);
                    // Se a media final de i for igual à do quinto colocado 
                    // Como está ordenado estará do lado dele
            } else{ 
                for(i = 0; i < numeroNota; i++){
                    printf("to no loop se preocupa n\n");
                    if(b[i].mF == b[4].mF){
                        // Copia o igual
                        strcpy(a[j].nome, b[i].nome);
                        a[j].mF = b[i].mF;
                        a[j].mP = b[i].mP;

                        j++;
                    }
                }

            }

        for(i = 0; i < j; i++){
            printf("nome %s mP %.2f mF %.2f\n", a[i].nome, a[i].mP, a[i].mF);
        }

    // Se não houver printa todos e não há suplentes
    } else{
        // Loop que percorre todos os que tiveram média para bolsista
        for(i = 0; i <  numeroNota; i++){
            printf("%s\n", b[i].nome);
        }
    }

    printf("socorr\n"); 

}


// // Funcao auxiliar da funcao que verifica os empates
// void auxiliaVerifica(Aux *a, Bolsista *b, int posicao, int contador){
//     int i, j = 0, aux = 0;

//     // Loop que copia informaçoes de parte do struct de bolsistas para o auxiliar
//     for(i = posicao; i < contador; i++){
//         strcpy(a[j].nome, b[i].nome);
//         a[j].mF = b[i].mF;
//         a[j].mP = b[i].mP;
//         j++;
//     }
//     // Ordena pela média parcial
//     ordenaParcial(a, j);
    
//     // Printa os bolsistas que empataram
//     for(i = 4; i < contador; i++){
//         if(a[i].mP == a[4].mP){
//             printf("%s\n", a[i].nome);
//             aux++;
//         } // Obs: esse condicional sempre printará o primeiro elemento da lista ordenada
//     }

    
// }

// // Função que verifica os empates
// void verificaEmpates(Bolsista *b, int numeroNota){
//     int i, posicao = 0;
//     Aux a[10];


//     printf("\nAlunos bolsistas:\n");

//     // Se houverem mais de 5 alunos com média final maior que 9,4
//     if(numeroNota > 5){
//         // se os 6 forem iguais
//         if(b[0].mF == b[1].mF && b[1].mF == b[2].mF && b[2].mF == b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF){
//             // Chama função que desempata
//             auxiliaVerifica(a, b, posicao, numeroNota);
//         }

//         // se 2 - 6 for igual
//         if(b[0].mF != b[1].mF && b[1].mF == b[2].mF && b[2].mF == b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF){
//             for(i = 0; i < 4; i++){
//                 printf("%s\n", b[0].nome);
//             }

//             posicao = 1;
            
//             auxiliaVerifica(a, b, posicao, numeroNota);
//         }

//         // se 3 - 6 for igual
//         if(b[1].mF != b[2].mF && b[2].mF == b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF){
//             for(i = 0; i < 2; i++){
//                 printf("%s\n", b[i].nome);
//             }

//             posicao = 2;
            
//             auxiliaVerifica(a, b, posicao, numeroNota);

//         }

//         // se 4 - 6 for igual
//         if(b[2].mF != b[3].mF && b[3].mF == b[4].mF && b[4].mF == b[5].mF){
//             // Printa os 3 primeiros elementos
//             for(i = 0; i < 3; i++){
//                 printf("%s\n", b[i].nome);
//             }

//             posicao = 3;
            
//             auxiliaVerifica(a, b, posicao, numeroNota);
            

//         }

//         // se 5 - 6 for igual
//         if(b[4].mF == b[5].mF){
//             for(i = 0; i < 6; i++){
//                 printf("%s\n", b[i].nome);
//             }
//         }

//         // se o 6 for menor
//         if(b[4].mF != b[5].mF){
//             for(i = 0; i < 5; i++){
//                 printf("%s\n", b[i].nome);
//             }
//         }
//     // Se não houver printa todos e não há suplentes
//     } else{
//         // Loop que percorre todos os que tiveram média para bolsista
//         for(i = 0; i <  numeroNota; i++){
//             printf("%s\n", b[i].nome);
//         }
//     }

//     printf("\n"); 

// }


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
    
}

// Função que gerencia funções relacionadas a bolsistas
void finalizaNota(Bolsista *b, int numeroNota){
    // Chama função que ordena pela média final
    ordenaStruct(b, numeroNota);
    // Chama função que analisa os resultados
    verificaEmpates(b, numeroNota);
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


int gerenciaAprovados(int contaAprovados, int resto, Passei *p, Bolsista *b){
    int i, j, numeroTurmas;

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



    }

    return numeroTurmas;
}

void gerenciaFuncoes(float *mP, float *mF, char nomes[30][100], Passei *p, Bolsista *b){
    int contaAprovados, numeroTurmas, resto, numeroNota;

    leArquivos(mP, mF, nomes);

    // for(int i; i < 100; i++){
    //     printf("%.2f\n", mP[i]);
    // }

    // Chama a função que preenche o struct de aprovados
    contaAprovados = verificaAprovados(nomes, mP, mF, p);

    resto = contaAprovados%10;

    numeroTurmas = gerenciaAprovados(contaAprovados, resto, p, b);

    preencheTurmas(p, numeroTurmas, contaAprovados, resto);
}




// Função principal
int main(){
    Passei p[100]; // O númeiro máximo de alunos que podem passar é 100
    Bolsista b[100]; // O número máximo de alunos coma a média >= 9,5 é 100
    char nomes[30][100];
    float mP[100], mF[100];

    // Função que gerencia operaçoes
    gerenciaFuncoes(mP, mF, nomes, p, b);

    return 0;
}


/*

- preciso revisar o funcionamento de bibliotecas.

teste1.txt teste2.txt teste3.txt teste4.txt teste5.txt teste6.txt teste7.txt teste8.txt teste9.txt teste10.txt
pb1 pb2 pb3 pb4 pb5 pb6 pb7 pb8 pb9 pb10
pa1 pa2 pa3 pa4 pa5 pa6 pa7 pa8 pa9 pa10
*/