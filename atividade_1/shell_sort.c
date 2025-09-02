#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shell_sort(int vetor[], int tamanho) {
    int pivo;
    int h = 1;

    while(h < tamanho) {
        h = 3 * h + 1;
    }

    while(h > 0) {
        for(int i = h; i < tamanho; i++) {
            pivo = vetor[i];
            int j = i;

            while(j > h - 1 && pivo <= vetor[j - h]) {
                vetor[j] = vetor[j - h];
                j = j - h;
            }
            vetor[j] = pivo;
        }
        h = h / 3;
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

    shell_sort(vetor, tamanho);

    fim = clock();

    printf("Vetor ordenado: ");
    imprimir_vetor(vetor, tamanho);

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.3f segundos\n", tempo);

    free(vetor);
    return 0;
}