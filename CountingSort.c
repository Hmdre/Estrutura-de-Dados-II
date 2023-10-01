#include <stdio.h>
#include <stdlib.h>

void mostraVetor(int *Vet, int tamanho){
    
    printf("\n");

    for(int i = 0 ; i < tamanho ; i++){
        printf("[ ");
        printf("%d ", Vet[i]);
        printf("]");
    }
}

void countingSort(int *A, int tamanho){
    
    int B[tamanho], i, maiorValor = 0;

    for(i = 0 ; i < tamanho ; i++){
        if(A[i] > maiorValor) maiorValor = A[i];
    }

    int C[maiorValor+1];
 
    for(i = 0 ; i <= maiorValor ; i++){
        C[i] = 0;
    }
 
    for(i = 0 ; i < tamanho ; i++){
        C[A[i]]++;
    }
 
    for(i = 1 ; i <= maiorValor ; i++){
        C[i] = C[i]+C[i-1];
    }
 
    for(i = (tamanho-1) ; i >= 0 ; i--){
        B[C[A[i]]-1] = A[i];
        C[A[i]]--;
    }

    for(int i = 0 ; i < tamanho ; i++){
        A[i] = B[i];
    }
}

int main(){
    int Vet[10] = { 6, 2, 5, 3, 9, 8, 20, 40, 9, 0};

    int tamanhoV = sizeof(Vet)/sizeof(Vet[0]);

    printf("%d", tamanhoV);

    printf("\nVetor original: ");
    mostraVetor(Vet, tamanhoV);

    countingSort(Vet, tamanhoV);

    printf("\nVetor ordenado: ");
    mostraVetor(Vet, tamanhoV);

    return 0;
}