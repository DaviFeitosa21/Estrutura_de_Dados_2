#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int busca_padrao(const char *texto, const char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    int contador = 0;

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if(texto[j + i] != padrao[j]) {
                break;
            }
        }
        if(j == m) {
            printf("padrão encontrado na posicão: %d\n", i);
            contador++;
        }
    }
    return contador;
}

int main() {
    clock_t inicio, fim;
    double tempo_execucao;

    FILE *pont_arq;

    pont_arq = fopen("arquivo_palavras.txt", "r");

    if(pont_arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        exit(1);
    }

    fseek(pont_arq, 0, SEEK_END);
    long tamanho = ftell(pont_arq);
    rewind(pont_arq);

    char *texto = malloc(tamanho + 1);
    if(!texto) {
        printf("Erro na alocação de memoria!\n");
        fclose(pont_arq);
        return 1;
    }

    printf("\nLendo dados exibidos no arquivo...\n\n");

    fread(texto, 1, tamanho, pont_arq);
    texto[tamanho] = '\0';

    fclose(pont_arq);

    printf("Conteudo do arquivo:\n%s\n\n", texto);

    const char *padrao = "teste";

    inicio = clock();
    int total = busca_padrao(texto, padrao);
    fim = clock();

    if (total > 0) {
        printf("quantidade de padrões encontrados: %d\n", total);
    }
    else {
        printf("padrão não encontrado\n");
    }

    tempo_execucao = ((double)(fim - inicio)) / CLOCKS_PER_SEC;
    printf("tempo de execução: %.9f segundos\n", tempo_execucao);

    printf("\n\n");
    
    free(texto);
    return 0;
}