#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM_ALFABETO 256

void pre_processamento(const char *padrao, int m, int tabela[]) {
    for(int i = 0; i < TAM_ALFABETO; i++) {
        tabela[i] = -1;
    }

    //Armazena a última posição de cada caractere do padrão
    for(int i = 0; i < m; i++) {
        tabela[(unsigned char)padrao[i]] = i;
    }
}

int busca_boyer(const char *texto, const char *padrao) {
    int n = strlen(texto);
    int m = strlen(padrao);
    int tabela_pre_processamento[TAM_ALFABETO];

    pre_processamento(padrao, m, tabela_pre_processamento);
    
    int deslocamento = 0;

    while(deslocamento <= (n - m)) {
        int j = m - 1;

        while(j >= 0 && padrao[j] == texto[deslocamento + j]) {
            j--;
        }

        if(j < 0) {
            return deslocamento;
        }
        else {
            int ultimo = tabela_pre_processamento[(unsigned char)texto[deslocamento + j]];
            int pulo = j - ultimo;

            if(pulo < 1) {
                pulo = 1;
            }

            deslocamento += pulo;
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
    int pos = busca_boyer(texto, padrao);

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