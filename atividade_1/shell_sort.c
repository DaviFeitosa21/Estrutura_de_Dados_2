#include <stdio.h>
#include <stdlib.h>

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

    shell_sort(vetor, tamanho);

    printf("Vetor ordenado: ");
    imprimir_vetor(vetor, tamanho);

    return 0;
}