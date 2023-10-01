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

void bubbleSort(int *Vet, int tamanho){
    int aux;
    for(int i = 0 ; i < (tamanho-2) ; i++){
        for(int j = (tamanho-1) ;  j >= (i+1) ; j--){
            if(Vet[j] < Vet[j-1]){
                aux = Vet[j];
                Vet[j] = Vet[j-1];
                Vet[j-1] = aux;
            }
        }
    }
}

int main(){
    int Vet[10] = { 6, 2, 5, 3, 9, 8, 20, 40, 9, 0};
    int tamanhoV = sizeof(Vet)/sizeof(Vet[0]);

    printf("\nVetor original: ");
    mostraVetor(Vet, tamanhoV);

    bubbleSort(Vet, tamanhoV);
    
    printf("\nVetor ordenado: ");
    mostraVetor(Vet, tamanhoV);

    return 0;
}