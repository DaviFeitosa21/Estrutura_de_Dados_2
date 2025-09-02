#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct produto {
    int codigo;
    char nome[50];
    float preco;
}PRODUTOS;

void imprime_produto(PRODUTOS prod[], int quantidade) {
    for(int i = 0; i < quantidade; i++) {
        printf("Codigo: %d, Descricao: %s, Preco: R$%.2f\n", prod[i].codigo, prod[i].nome, prod[i].preco);
    }
}

void bubble_sort(PRODUTOS prod[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (prod[j].codigo > prod[j + 1].codigo) {
                PRODUTOS aux = prod[j];
                prod[j] = prod[j + 1];
                prod[j + 1] = aux;
            }
        }
    }
}

void buscaSequencial(PRODUTOS prod[], int quantidade, int chave) {
    int cont = -1;
    bool existe = false;

    for(int i = 0; i < quantidade; i++) {
        if(prod[i].codigo == chave) {
            existe = true;
            cont++;

            printf("\nProduto encontrado: Codigo: %d, Descricao: %s, Preco: R$%.2f\n", prod[i].codigo, prod[i].nome, prod[i].preco);
        }
    }

    if(!existe) {
        printf("Codigo nao encontrado!");
    }

}

void buscaBinaria(PRODUTOS prod[], int quantidade, int chave) {
    int inicio = 0;
    int fim = quantidade - 1;
    int meio;
    bool existe = false;
    
    while(inicio <= fim) {
        meio = (inicio + fim) / 2;
        if(chave == prod[meio].codigo) {
            printf("\nProduto encontrado: Codigo: %d, Descricao: %s, Preco: R$%.2f\n", prod[meio].codigo, prod[meio].nome, prod[meio].preco);
            existe = true;
            break;
        }
        else if(chave < prod[meio].codigo) {
            fim = meio - 1;
        }
        else {
            inicio = meio + 1;
        }
    }

    if(!existe) {
        printf("Codigo nao encontrado!");
    }
}

int main() {
    // PRODUTOS prod[3] = {
    //     {1, "Notebook Acer", 5000},
    //     {2, "MacBook", 8000},
    //     {3, "Samsung Galaxy S24", 3000}
    // };

    int quantidade;
    int valorChave;

    printf("Digite a quantidade de produtos:\n");
    scanf("%d", &quantidade);

    PRODUTOS *prod = malloc(quantidade * sizeof(PRODUTOS));

    for (int i = 0; i < quantidade; i++) {
        printf("\n-------PRODUTO %d-------\n", i + 1);
        printf("Codigo:\n");
        scanf("%d", &prod[i].codigo);

        printf("\nDescricao:\n");
        scanf(" %s", &prod[i].nome);

        printf("\nPreco:\n");
        scanf("%f", &prod[i].preco);
    }
    
    printf("---------------------------------------------------------------\n");

    printf("\nOrdenando Lista...\n");
    bubble_sort(prod, quantidade);

    printf("---------------------------------------------------------------\n");

    printf("\nInformacoes dos produtos:\n");
    imprime_produto(prod, quantidade);

    printf("---------------------------------------------------------------\n");

    printf("\nDigite o codigo de um produto para buscar:\n");
    scanf("%d", &valorChave);

    buscaBinaria(prod, quantidade, valorChave);

}