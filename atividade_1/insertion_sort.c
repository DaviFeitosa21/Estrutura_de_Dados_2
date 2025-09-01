#include <stdio.h>
#include <stdlib.h>

void insertion_sort(int vetor[], int tamanho) {
    for(int i = 1; i < tamanho; i++) {
        int pivo = vetor[i];
        int j = i - 1;

        while (j >= 0 && vetor[j] > pivo) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }
        vetor[j + 1] = pivo;
    }
}

void imprimir_vetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int tamanho;
    int vetor[tamanho];
    
    printf("Digite o tamanho do vetor:");
    scanf("%d", &tamanho);

    for(int i = 0; i < tamanho; i++) {
        printf("Digite o valor da posição %d: \n", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("Vetor original: ");
    imprimir_vetor(vetor, tamanho);

    insertion_sort(vetor, tamanho);

    printf("Vetor ordenado: ");
    imprimir_vetor(vetor, tamanho);

    return 0;
}