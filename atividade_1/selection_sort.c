#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void selection_sort(int vetor[], int tamanho) {
    int menor, aux;

    for(int i = 0; i < (tamanho - 1); i++) {
        menor = i;
        for(int j = i + 1; j < tamanho; j++) {
            if(vetor[j] < vetor[menor]) {
                menor = j;
            }
        }

        if(i != menor) {
            aux = vetor[i];
            vetor[i] = vetor[menor];
            vetor[menor] = aux;
        }
    }
}

void imprimir_vetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho = 100000;

    clock_t inicio, fim;

    //int vetor[tamanho];
    
    // printf("Digite o tamanho do vetor:");
    // scanf("%d", &tamanho);

    // for(int i = 0; i < tamanho; i++) {
    //     printf("Digite o valor da posição %d: \n", i + 1);
    //     scanf("%d", &vetor[i]);
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

    printf("Vetor original: ");
    imprimir_vetor(vetor, tamanho);

    inicio = clock();

    selection_sort(vetor, tamanho);

    fim = clock();

    printf("Vetor ordenado: ");
    imprimir_vetor(vetor, tamanho);

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.3f segundos\n", tempo);

    free(vetor);
    return 0;
}