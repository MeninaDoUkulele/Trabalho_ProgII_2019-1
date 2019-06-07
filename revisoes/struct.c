#include <stdio.h>
#include <stdlib.h>


struct aluno{
    char nome[30];
    int matricula;
    int p1;
    int p2;
    int p3;
};


int main(){
    struct aluno a;
    
    printf("Nome do aluno: ");
    fgets(a.nome, sizeof(a.nome), stdin);
    scanf("%i", &a.p1);

    if(a.p1 >= 7){
        printf("Go for it!\n");
    } else{
        printf("Hey dude, don't cry...\n");
    }
    return 0;
}