#include <stdio.h>
#include <stdlib.h>

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
        quickSort(vetor, inicio, indicePivo - 1);
        quickSort(vetor, indicePivo + 1, fim);
    }
}

int main() {

    int vetor;

    printf("Digite o tamanho do vetor: ");
    scanf("%d", &vetor);

    int *vetorMalloc = (int *)malloc(vetor * sizeof(int));

    for(int i = 0; i < vetor; i++) {
        printf("Digite um numero para a posicao %d: ", i + 1);
        scanf("%d", &vetorMalloc[i]);
    }

    for(int i = 0; i < vetor; i++) {
        printf("[%d] ", vetorMalloc[i]);
    }

    printf("\n");
    quickSort(vetorMalloc, 0, vetor - 1);

    for(int i = 0; i < vetor; i++) {
        printf("[%d] ", vetorMalloc[i]);
    }

    free(vetorMalloc);

    return 0;
}
