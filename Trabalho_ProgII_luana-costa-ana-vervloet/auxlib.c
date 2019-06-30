#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "auxlib.h"

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


// Função que printa nos arquivos de saída ordenados alfabeticamente
void printaAlfabetica(char nome[30][10], int contador, FILE *saida){
    char aux[20];
    int j, i;


    // Loop que roda quantidade de palavras
    for (i = 1; i < contador; i++) { 
        for (j = 1; j < contador; j++) {
            // Verifica se tem que ser depois, se for troca de posição
            if (strcmp(nome[j - 1], nome[j]) > 0) {
                strcpy(aux, nome[j - 1]);
                strcpy(nome[j - 1], nome[j]);
                strcpy(nome[j], aux);
            }
        }
    }

    // Printa no arquivo de saída passado como parâmetro
    for (i = 0; i < 10; i++){
        fprintf(saida ,"%s\n", nome[i]);
    }

    
}


void printaSuplente(char suplente[30][100], int s){
    FILE *suplentes;
    int i;

    suplentes = fopen("suplentes", "w");

    fprintf(suplentes, "Lista de Suplentes:\n\n");
    for(i = 0; i < s; i++){
        fprintf(suplentes, "%s\n", suplente[i]);
    }

    fclose(suplentes);
}