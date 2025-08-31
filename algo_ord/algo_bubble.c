#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho - 1; i++) {
        for(int j = 0; j < tamanho - i - 1; j++) {
            if(vetor[j] > vetor[j + 1]) {
                int aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
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

    bubble_sort(vetor, tamanho);

    printf("Vetor ordenado: ");
    imprimir_vetor(vetor, tamanho);

    return 0;
}