#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particionar(int *vetor, int inicio, int fim) {
    int randomPivo = inicio + rand() % (fim - inicio + 1);

    int pivo = vetor[randomPivo];
    int i = inicio - 1;
    int j = fim + 1;

    while (1) {
        for(i = i + 1; vetor[i] < pivo; i++);

        for(j = j - 1; vetor[j] > pivo; j--);

        if(i >= j) {
            return j;
        }

        int aux = vetor[i];
        vetor[i] = vetor[j];
        vetor[j] = aux;
    }
}

void quick_sort(int *vetor, int inicio, int fim) {
    if(inicio < fim) {
        int indicePivo = particionar(vetor, inicio, fim);
        quick_sort(vetor, inicio, indicePivo - 1);
        quick_sort(vetor, indicePivo + 1, fim);
    }
}

void imprimir(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;
    clock_t inicio, fim;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);

    int *vetor = (int *)malloc(tamanho * sizeof(int));

    srand(time(NULL));

    for(int i = 0; i < tamanho; i++) {
        do {
            printf("\nDigite o indice de popularidade da banda %d: ", i + 1);
            scanf("%d", &vetor[i]);

            if(vetor[i] < 0 || vetor[i] > 100) {
                printf("\nValor inválido, digite valores entre 0 e 100!\n");
            }
        } while (vetor[i] < 0 || vetor[i] > 100);
    }

    printf("\nVETOR DESORDENADO:\n");
    imprimir(vetor, tamanho);

    inicio = clock();

    quick_sort(vetor, 0, tamanho - 1);

    fim = clock();

    printf("\nVETOR ORDENADO:\n");
    imprimir(vetor, tamanho);

    int mediana = vetor[(tamanho - 1) / 2];
    printf("\nMediana da popularidade das bandas: %d\n", mediana);

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.3f segundos\n", tempo);

    free(vetor);
    return 0;
}