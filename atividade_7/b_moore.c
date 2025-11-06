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
    int contador = 0;
    int tabela_pre_processamento[TAM_ALFABETO];

    pre_processamento(padrao, m, tabela_pre_processamento);
    
    int deslocamento = 0;

    while(deslocamento <= (n - m)) {
        int j = m - 1;

        while(j >= 0 && padrao[j] == texto[deslocamento + j]) {
            j--;
        }

        if(j < 0) {
            printf("padrão encontrado na posição: %d\n", deslocamento);
            contador++;

            //avança o deslocamento e continua a busca(evita loop)
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

    return contador;
}

int main() {
    const char *texto = "algoritmo de busca boyer moore";
    const char *padrao = "e";

    int total = busca_boyer(texto, padrao);

    if(total >= 0) {
        printf("padrões encontrados: %d\n", total);
    }
    else {
        printf("padrao não encontrado");
    }

}