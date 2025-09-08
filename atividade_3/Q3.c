#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int vetor[], int tamanho, int gaps[], int quantGap) {
    for(int g = 0; g < quantGap; g++) {
        int gap = gaps[g];

        for(int i = gap; i < tamanho; i++) {
            int pivo = vetor[i];
            int j = i;

            while(j >= gap && vetor[j - gap] > pivo) {
                vetor[j] = vetor[j - gap];
                j -= gap;
            }
            vetor[j] = pivo;
        }
    }
}

void imprimir(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
        if(i < tamanho - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {

    int tamanho, quantgap;
    clock_t inicio, fim;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < tamanho; i++) {
        printf("\nDigite o valor do vetor na posição %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nDigite a quantidade de gaps para este vetor: ");
    scanf("%d", &quantgap);
    
    int *gaps = (int *)malloc(quantgap * sizeof(int));

    for(int i = 0; i < quantgap; i++) {
        printf("\nDigite a sequência de gaps [%d]: ", i + 1);
        scanf("%d", &gaps[i]);
    }
    
    printf("\nVETOR DESORDENADO:\n");
    imprimir(vetor, tamanho);

    inicio = clock();
    shell_sort(vetor, tamanho, gaps, quantgap);
    fim = clock();

    printf("\nVETOR ORDENADO (COM O GAP):\n");
    imprimir(vetor, tamanho);

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.3f segundos\n", tempo);

    free(vetor);
    free(gaps);
    
    return 0;
}