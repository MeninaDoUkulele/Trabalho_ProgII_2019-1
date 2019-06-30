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

    printf("\n");
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
    for(i = contador; i > -1; i--){
        // Loop vindo do último até o primeiro
        for(h = 0; h < i; h++){
            // Condicional para ver qual elemento é maior (dois em dois)
            if(a[h].mF < a[h + 1].mF){
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


// Função que gerencia operações com bolsistas
void verificaEmpates(Bolsista *b, int numeroNota){
    int i, j = 0, s = 0, l = 0;
    Aux a[100];
    char bolsista[30][100], suplente[30][100];

    printf("\nAlunos bolsistas:\n");

    // Se houverem mais de 5 alunos com média final maior que 9,4
    if(numeroNota > 5){
            // Condicional para ver se há empates depois do 5 elemento
            if(b[4].mF != b[5].mF){
                // Preenche vetor com nomes dos bolsistas
                for(i = 0; i <  5; i++){
                    strcpy(bolsista[i], b[i].nome);
                }
                // Preenche o vetor com o nome dos suplentes
                for(i = 5; i < numeroNota; i++){
                    strcpy(suplente[s], b[i].nome);
                    s++;
                }

                for(i = 0; i < 5; i++){
                    printf("%s\n", bolsista[i]);
                }

                printaSuplente(suplente, s);
               
            // Se houverem empates na média final
            } else{ 
                // Loop percorre todas as notas acima de 9,4
                for(i = 0; i < numeroNota; i++){
                    // Se algum for igual ao 5 elemento
                    // Nota que se for igual será vizinho do 5 elemento
                    if(b[i].mF == b[4].mF){
                        // Copia o igual
                        strcpy(a[j].nome, b[i].nome);
                        a[j].mF = b[i].mF;
                        a[j].mP = b[i].mP;
                        // Contador para struct auxiliar
                        j++;
                    }

                    // Se não for igual e estiver numa posição anterior ao 5 elemento
                    if(b[i].mF != b[4].mF && i < 4){
                        // Copia para o vetor bolsista
                        strcpy(bolsista[l], b[i].nome);
                        // Contador do número de bolsistas
                        l++;
                    }

                    // Se não for igual e estiver numa posição posterior ao 5 elemento
                    if(b[i].mF != b[4].mF && i > 4){
                        // Copia para vetor suplente
                        strcpy(suplente[s], b[i].nome);
                        // Contador do número de suplentes
                        s++;
                    }
                }

                // Chama função que ordena pela média parcial
                ordenaParcial(a, j);

                // Loop para separação dos empatados
                for(i = 0; i < j; i++){
                    // Se o elemento for igual ao primeiro
                    // Nota: como está ordenado o primeiro sempre será o maior
                    if(a[i].mP == a[0].mP){
                        // Copia para o vetor bolsista
                        strcpy(bolsista[l], a[i].nome);
                        // Contador de bolsistas
                        l++;

                    // Se não for igual
                    } else{
                        // Copia para o vetor suplente
                        strcpy(suplente[s], a[i].nome);
                        // Contador de suplentes
                        s++;
                    }
                }

                for(i = 0; i < l; i++){
                    printf("%s\n", bolsista[i]);
                }

                printaSuplente(suplente, s);
            }

    // Se não houver printa todos e não há suplentes
    } else{
        // Loop que percorre todos os que tiveram média para bolsista
        for(i = 0; i <  numeroNota; i++){
            printf("%s\n", b[i].nome);
        }
    }

}


// Função que ordena por média final os possíveis bolsistas
void ordenaStruct(Bolsista *b, int numeroNota){
    int h, i;
    Aux a;

    // Primeiro preciso ordenar o struct pela média final
    // Loop vindo do último até o primeiro
    for(i = numeroNota; i > -1; i--){
        // Loop vindo do último até o primeiro
        for(h = 0; h < i; h++){
            // Condicional para ver qual elemento é maior (dois em dois)
            if(b[h].mF < b[h + 1].mF){
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