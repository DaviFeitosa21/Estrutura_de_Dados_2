#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int particionar(int *vetor, int inicio, int fim) {
    int randomPivo = inicio + rand() % (fim - inicio + 1); 

    int pivo = vetor[randomPivo];
    int i = inicio - 1;
    int j = fim + 1;

    while (1)
    {
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

    quick_sort(vetor, 0, tamanho - 1);

    fim = clock();

    for(int i = 0; i < tamanho; i++) {
        printf("[%d] ", vetor[i]);
    }

    double tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("\nTempo de execução: %.9f segundos\n", tempo);

    free(vetor);
    return 0;
}
