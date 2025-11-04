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
    const char *texto = "teste de busca";
    const char *padrao = "busca";
    int pos = busca_padrao(texto, padrao);

    if (pos > 0) {
        printf("padrao encontrado na posicao: %d", pos);
    }
    else {
        printf("padrao nao encontrado");
    }
    
}