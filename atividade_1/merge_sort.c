#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int vetor[], int inicio, int meio, int fim) {
    int com1 = inicio, com2 = meio + 1, comAux = 0, tam = fim - inicio + 1;
    int *vetAux;
    vetAux = (int*)malloc(tam * sizeof(int));

    while(com1 <= meio && com2 <= fim) {
        if(vetor[com1] < vetor[com2]) {
            vetAux[comAux] = vetor[com1];
            com1++;
        } else {
            vetAux[comAux] = vetor[com2];
            com2++;
        }
        comAux++;
    }

    while(com1 <= meio) {
        vetAux[comAux] = vetor[com1];
        comAux++;
        com1++;
    }

    while(com2 <= fim) {
        vetAux[comAux] = vetor[com2];
        comAux++;
        com2++;
    }

    for(comAux = inicio; comAux <= fim; comAux++) {
        vetor[comAux] = vetAux[comAux - inicio];
    }
    
    free(vetAux);
}

void merge_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int meio = (fim + inicio) / 2;

        merge_sort(vetor, inicio, meio);
        merge_sort(vetor, meio + 1, fim);
        merge(vetor, inicio, meio, fim);
    }
}

int main() {
    int tamanho = 100000;

    clock_t inicio, fim;

    // int vetor;

    // printf("Digite o tamanho do vetor: ");
    // scanf("%d", &vetor);

    // int *vetorMalloc = (int *)malloc(vetor * sizeof(int));

    // for(int i = 0; i < vetor; i++) {
    //     printf("Digite um numero para a posicao %d: ", i + 1);
    //     scanf("%d", &vetorMalloc[i]);
    // }

    int *vetor = (int *)malloc(tamanho * sizeof(int));
    if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000000;
    }

    for(int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
    }

    printf("\n");
    inicio = clock();

    merge_sort(vetor, 0, tamanho - 1);

    fim = clock();

    for(int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
    }

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.3f segundos\n", tempo);

    free(vetor);
    return 0;
}