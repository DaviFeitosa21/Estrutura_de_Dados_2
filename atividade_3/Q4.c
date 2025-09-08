#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(float vetor[], int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - i - 1; j++) {
            if(vetor[j] > vetor[j + 1]) {
                float aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void bucket_sort(float vetor[], int tamanho) {
    int numBuckets = 10;

    float max = vetor[0];
    for (int i = 1; i < tamanho; i++) {
        if (vetor[i] > max) max = vetor[i];
    }

    float **buckets = (float **)malloc(numBuckets * sizeof(float *));
    int *bucketCount = (int *)calloc(numBuckets, sizeof(int));

    for(int i = 0; i < numBuckets; i++) {
        buckets[i] = (float *)malloc(tamanho * sizeof(float));
    }

    for (int i = 0; i < tamanho; i++) {
        int index = (vetor[i] / (max + 1)) * numBuckets; 
        if (index >= numBuckets) index = numBuckets - 1;
        buckets[index][bucketCount[index]++] = vetor[i];
    }

    int b = 0;
    for (int i = 0; i < numBuckets; i++) {
        bubble_sort(buckets[i], bucketCount[i]);
        for (int j = 0; j < bucketCount[i]; j++) {
            vetor[b++] = buckets[i][j];
        }
        free(buckets[i]);
    }

    free(buckets);
    free(bucketCount);
}

void imprimir(float vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("[%.2f] ", vetor[i]);
        if(i < tamanho - 1) {
            printf(" ");
        }
    }
    printf("\n");
}

int main() {

    int tamanho;
    clock_t inicio, fim;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    float *vetor = (float *)malloc(tamanho * sizeof(float));

    srand(time(NULL));

    for(int i = 0; i < tamanho; i++) {
        printf("\nDigite o valor do produto %d: ", i + 1);
        scanf("%f", &vetor[i]);
    }

    printf("\nVETOR DESORDENADO:\n");
    imprimir(vetor, tamanho);

    inicio = clock();
    bucket_sort(vetor, tamanho);
    fim = clock();

    printf("\nVETOR ORDENADO:\n");
    imprimir(vetor, tamanho);

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.3f segundos\n", tempo);

    free(vetor);
    return 0;

}