#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostraVetor(int *Vet, int tamanho){
    printf("\n");
    for(int i = 0 ; i<tamanho ; i++){
        printf("[ ");
        printf("%d ", Vet[i]);
        printf("]");
    }
}

void shellSort(int *Vet, int tamanho){
    int i, j, key, h = 1;

    while(h <= ((tamanho-1)/3)){
        h = 3*h+1;
    }

    while(h > 0){
        for(j = h ; j <= (tamanho-1) ; j++){
            key = Vet[j];
            i = j;
            while((i-h >= 0) && (key <= Vet[i-h])){
                Vet[i] = Vet[i-h];
                i = i-h;
            }
            Vet[i] = key;
        }
        h = (h-1)/3;
    }
}

int main(){
    int Vet[10] = { 6, 2, 5, 3, 9, 8, 20, 40, 9, 0};
    int tamanhoV = sizeof(Vet)/sizeof(Vet[0]);
 

    printf("\nVetor original: ");
    mostraVetor(Vet, tamanhoV);

    shellSort(Vet, tamanhoV);
    
    printf("\nVetor ordenado: ");
    mostraVetor(Vet, tamanhoV);

    return 0;
}