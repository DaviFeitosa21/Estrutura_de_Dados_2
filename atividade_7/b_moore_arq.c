#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

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
    int contador = 0;
    int contador_comparacoes = 0;
    int tabela_pre_processamento[TAM_ALFABETO];

    pre_processamento(padrao, m, tabela_pre_processamento);
    
    int deslocamento = 0;

    while(deslocamento <= (n - m)) {
        int j = m - 1;

        while(j >= 0 && padrao[j] == texto[deslocamento + j]) {
            contador_comparacoes++;
            j--;
        }

        if(j >= 0) {
            contador_comparacoes++;
        }

        if(j < 0) {
            printf("padrão encontrado na posicão: %d\n", deslocamento);
            contador++;

            //Avança o deslocamento e continua a busca(evita loop)
            deslocamento += (deslocamento + m < n) ? m - tabela_pre_processamento[(unsigned char)texto[deslocamento + m]] : 1;
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

    printf("quantidade de comparações realizadas: %d\n", contador_comparacoes);
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

    const char *padrao = "abacdacabc";

    inicio = clock();
    int total = busca_boyer(texto, padrao);
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