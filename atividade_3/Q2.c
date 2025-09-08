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

void imprimir(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanhoV1, tamanhoV2;
    clock_t inicioV1, fimV1, inicioV2, fimV2, inicioVF, fimVF;

    printf("Digite o tamanho do primeiro vetor: ");
    scanf("%d", &tamanhoV1);

    int *vetor1 = (int *)malloc(tamanhoV1 * sizeof(int));

    for(int i = 0; i < tamanhoV1; i++) {
        printf("\nDigite os valores do vetor [V1 %d]: ", i + 1);
        scanf("%d", &vetor1[i]);     
    }

    printf("\nDigite o tamanho do segundo vetor: ");
    scanf("%d", &tamanhoV2);

    int *vetor2 = (int *)malloc(tamanhoV2 * sizeof(int));

    for(int i = 0; i < tamanhoV2; i++) {
        printf("\nDigite os valores do vetor [V2 %d]: ", i + 1);
        scanf("%d", &vetor2[i]);     
    }

    srand(time(NULL));

    printf("\nVETORES DESORDENADOS:\n");
    imprimir(vetor1, tamanhoV1);
    imprimir(vetor2, tamanhoV2);

    inicioV1 = clock();
    merge_sort(vetor1, 0, tamanhoV1 - 1);
    fimV1 = clock();

    inicioV2 = clock();
    merge_sort(vetor2, 0, tamanhoV2 - 1);
    fimV2 = clock();

    printf("\nVETORES ORDENADOS:\n");
    imprimir(vetor1, tamanhoV1);
    imprimir(vetor2, tamanhoV2);

    double tempoV1 = (double)(fimV1 - inicioV1) / CLOCKS_PER_SEC;
    printf("\nTempo de execução do vetor 1: %.3f segundos\n", tempoV1);

    double tempoV2 = (double)(fimV2 - inicioV2) / CLOCKS_PER_SEC;
    printf("\nTempo de execução do vetor 2: %.3f segundos\n", tempoV2);

    int *vetorFinal = (int *)malloc((tamanhoV1 + tamanhoV2)* sizeof(int));

    for (int i = 0; i < tamanhoV1; i++) {
        vetorFinal[i] = vetor1[i];
    }

    for(int j = 0; j < tamanhoV2; j++) {
        vetorFinal[tamanhoV1 + j] = vetor2[j];
    }

    printf("\nJUNÇÃO DOS VETORES DESORDENADOS: \n");
    imprimir(vetorFinal, tamanhoV1 + tamanhoV2);

    inicioVF = clock();
    merge_sort(vetorFinal, 0, (tamanhoV1 + tamanhoV2) - 1);
    fimVF = clock();

    printf("\nJUNÇÃO DOS VETORES ORDENADOS: \n");
    imprimir(vetorFinal, tamanhoV1 + tamanhoV2);

    double tempoVFinal = (double)(fimVF - inicioVF) / CLOCKS_PER_SEC;
    printf("\nTempo de execução do vetor final: %.3f segundos\n", tempoVFinal);
    
    free(vetor1);
    free(vetor2);
    free(vetorFinal);

    return 0;
}