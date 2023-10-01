#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void mostraVetor(long int *Vet, int tamanho){
    printf("\n");
    for(int i = 0 ; i<tamanho ; i++){
        printf("[ ");
        printf("%d ", Vet[i]);
        printf("]");
    }
}

void preencheVetor(long int *vet, long int *vet2, long int *vet3, long int *vet4, int tamanho){
    srand(time(NULL));
    for(int i = 0 ; i < tamanho ; i++){
        vet[i] = rand()+1+rand()%17233;
        vet2[i] = vet[i];
        vet3[i] = vet[i];
        vet4[i] = vet[i];
    }
}

void countingSort(long int *A, long int tamanho){
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

void shellSort(long int *Vet, long int tamanho){
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

void bubbleSort(long int *Vet, long int tamanho){
    int aux, i, j;

    for(i = 0 ; i < (tamanho-2) ; i++){
        for(j = (tamanho-1) ;  j >= (i+1) ; j--){
            if(Vet[j] < Vet[j-1]){
                aux = Vet[j];
                Vet[j] = Vet[j-1];
                Vet[j-1] = aux;
            }
        }
    }
}

void teste(long int tamanho){
    long int Vet[tamanho], VetBubble[tamanho], VetShell[tamanho], VetCounting[tamanho];
    double tempo_trans;
    clock_t inicio, fim;
    FILE *arq;
    int i;

    //O vetor original é preenchido com valores aleatórios e é copiado nos vetores bubble, shell e counting.
    preencheVetor(Vet, VetBubble, VetShell, VetCounting, tamanho);

    //O vetor aleatoriamente preenchido é armazenado em um arquivo chamado "SaidaVetorOriginal.txt"
    arq = fopen("SaidaVetorOriginal.txt","w");
    fprintf(arq, "Vetor original Vet:\n");
    for(int i = 0 ; i < tamanho ; i++){
        fprintf(arq,"Elememto Vet[%d]= %ld\n", i, Vet[i]);
    }

    //A ordenação por BubbleSort é realizada aqui e o tempo de execução é registrado
    inicio = clock();
    bubbleSort(VetBubble, tamanho);
    fim = clock();
    tempo_trans = (double) ((fim-inicio)/(CLOCKS_PER_SEC/1000));
    printf("\nTempo gasto na execucao do BubbleSort   para %d elementos: %.0f milissegundos.", tamanho, tempo_trans); 
    
    //O vetor ordenado por BubbleSort é aramzenado em um aquivo chamado "SaidaBubble.txt"
    arq = fopen("SaidaBubble.txt","w");
    fprintf(arq, "Vetor \"Vet\" ordenado por BubbleSort:\n");
    for(i = 0 ; i < tamanho ; i++){
        fprintf(arq,"Elememto Vet[%d]= %ld\n", i, VetBubble[i]);
    }

    //A ordenação por ShellSort é realizada aqui e o tempo de execução é registrado
    inicio = clock();
    shellSort(VetShell, tamanho);
    fim = clock();
    tempo_trans = (double) ((fim-inicio)/(CLOCKS_PER_SEC/1000));
    printf("\nTempo gasto na execucao do ShellSort    para %d elementos: %.0f milissegundos.", tamanho, tempo_trans);
    
    //O vetor ordenado por ShellSort é aramzenado em um aquivo chamado "SaidaShell.txt"
    arq = fopen("SaidaShell.txt","w");
    fprintf(arq, "Vetor \"Vet\" ordenado por ShellSort:\n");
    for(i = 0 ; i < tamanho ; i++){
        fprintf(arq,"Elememto Vet[%d]= %ld\n", i, VetShell[i]);
    }

    //A ordenação por CountingSort é realizada aqui e o tempo de execução é registrado
    inicio = clock();
    countingSort(VetCounting, tamanho);
    fim = clock();
    tempo_trans = (double) ((fim-inicio)/(CLOCKS_PER_SEC/1000));
    printf("\nTempo gasto na execucao do CountingSort para %d elementos: %.0f milissegundos.", tamanho, tempo_trans);
    printf("\n");
    
    //O vetor ordenado por CountingSort é aramzenado em um aquivo chamado "SaidaCounting.txt"
    arq = fopen("SaidaCounting.txt","w");
    fprintf(arq, "Vetor \"Vet\" ordenado por CountingSort:\n");
    for(i = 0 ; i < tamanho ; i++){
        fprintf(arq,"Elememto Vet[%d]= %ld\n", i, VetCounting[i]);
    }
}

int main(){

    teste(10000);

    teste(50000);

    teste(90000);

    return 0;
}