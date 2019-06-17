#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

void mediaAritmetica(float p1, float p2, int i, float *media){
    media[i] = (p1 + p2)/2;
}

int main(){
    int j;
    float p1, p2, media[10];

    for(j = 0; j < 10; j++){
        printf("Bota ae: ");
        scanf("%f %f", &p1, &p2);

        mediaAritmetica(p1, p2, j, media);
    }
    
    for(j = 0; j < 10; j++){
        printf("media %i: %.2f\n", j, media[j]);
    }
    return 0;
}