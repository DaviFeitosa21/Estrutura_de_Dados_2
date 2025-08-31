#include <stdio.h>
#include <stdlib.h>

void selection_sort(int vetor[], int tamanho) {
    for(int i = 0; i < (tamanho - 1); i++) {
        int min = i;

        for(int j = (i + 1); j < tamanho; j++) {
            if(vetor[j] < vetor[min]) {
                min = j;
            }
        }
        if(i != min) {
            int aux = vetor[i];
            vetor[i] = vetor[min];
            vetor[min] = aux;
        }
    }
}

void imprimir_vetor(int vetor[], int tamanho) {
    for(int i = 0; i < tamanho; i++) {
        printf(" %d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    printf("--------------------------------------------------\n");
    printf("                  SELECTION SORT                  \n");
    printf("--------------------------------------------------\n");

    int tamanho; 

    printf("tamanho do vetor:\n");
    scanf("%d", &tamanho);

    int vetor[tamanho];

    for(int i = 0; i < tamanho; i++) {
        printf("valor da posição %d: \n", i + 1);
        scanf("%d", &vetor[i]);
    }
    
    printf("vetor original: ");
    imprimir_vetor(vetor, tamanho);

    selection_sort(vetor, tamanho);

    printf("vetor ordenado: ");
    imprimir_vetor(vetor, tamanho);

    return 0;
}