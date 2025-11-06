#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    const char *texto = "teste de busca de";
    const char *padrao = "de";

    int total = busca_padrao(texto, padrao);

    if (total > 0) {
        printf("padrões encontrados: %d", total);
    }
    else {
        printf("padrão não encontrado\n");
    }
    
}