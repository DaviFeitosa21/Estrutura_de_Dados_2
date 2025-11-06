#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int busca_padrao(const char *texto, const char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);

    for (int i = 0; i <= n - m; i++) {
        int j;
        for (j = 0; j < m; j++) {
            if(texto[j + i] != padrao[j]) {
                break;
            }
        }
        if(j == m) {
            return i;
        }
    }
    return -1;
}

int main() {
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
    int pos =busca_padrao(texto, padrao);

    if (pos > 0) {
        printf("padrão encontrado na posicão: %d", pos);
    }
    else {
        printf("padrão não encontrado");
    }

    printf("\n\n");
    
    free(texto);
    return 0;
}