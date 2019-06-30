void verificaEmpates(Bolsista *b, int numeroNota){
    int i, j = 0, suplentes, empates, vetorIndice[100];
    Aux a[100];


    printf("\nAlunos bolsistas:\n");

    // Se houverem mais de 5 alunos com média final maior que 9,4
    if(numeroNota > 5){
        // Loop percorrendo o vetor do último ao primeiro
        for(i = numeroNota; i < 0; i--){
            // Condicional para ver se há empates depois do 5 elemento
            // Se tiver o programa sai do loop
            if(b[4].mF != b[5].mF){
                for(i = 0; i <  5; i++){
                    printf("%s\n", b[i].nome);
                }
                suplentes = numeroNota - 5;
                break;
                    // Se a media final de i for igual à do quinto colocado 
                    // Como está ordenado estará do lado dele
            } else{ if(b[i].mF == b[4].mF){
                        // Copia o igual
                        strcpy(a.[j].nome, b[i].nome);
                        a[j].mF = b[i].mF;
                        a[j].mP = b[i].mP;
                        // Pega a posição
                        vetorIndice[j] = i;

                    }
            }

        }

        empates = numeroNota - aux;

        if(empates < 5){

        }
    // Se não houver printa todos e não há suplentes
    } else{
        // Loop que percorre todos os que tiveram média para bolsista
        for(i = 0; i <  numeroNota; i++){
            printf("%s\n", b[i].nome);
        }
    }

    printf("\n"); 

}
