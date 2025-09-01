#include <stdio.h>
#include <stdlib.h>

void selection_sort(int vetor[], int tamanho) {
    int menor, aux;

    for(int i = 0; i < (menor - 1); i++) {
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

    selection_sort(vetor, tamanho);

    printf("Vetor ordenado: ");
    imprimir_vetor(vetor, tamanho);

    return 0;
}