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


// Função LuanaAna Sort;
void funcaoOrdenacao(float *medias){

}

int main(){
    return 0;
}