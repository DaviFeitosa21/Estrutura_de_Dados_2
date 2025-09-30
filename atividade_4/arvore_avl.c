#include <stdio.h>
#include <stdlib.h>
#define tamanhoDoEspaco 10

typedef struct ITEM {
    int valor;
}tipoItem;

typedef struct NO
{
    tipoItem item;
    struct NO *esquerda;
    struct NO *direita;
    int altura;
    int fatorBalanceamento;
}tipoNo;

tipoNo *inicializar() {
    return NULL;
}

void imprimir(tipoNo *raiz, int espaco)  {
    if(raiz == NULL) { 
        return; 
    }
    else { 
        espaco += tamanhoDoEspaco; 

        imprimir(raiz->direita, espaco); 
   
        printf("\n"); 
        for (int i = tamanhoDoEspaco; i < espaco; i++) {
            printf(" "); 
        }

        printf("%d\n", raiz->item.valor); 
        imprimir(raiz->esquerda, espaco); 
	}
}

void apagarArvore(tipoNo *raiz) {
    if(raiz != NULL) {
        apagarArvore(raiz->direita);
        apagarArvore(raiz->esquerda);
        free(raiz);
        raiz = NULL;
    }
}

tipoNo *pesquisar(tipoNo *raiz, int valor) {
	if(raiz != NULL) {
		if(raiz->item.valor == valor) {
			return raiz;
		}
		else {
			if(valor > raiz->item.valor) {
			    return pesquisar(raiz->direita, valor);
			}
            else {
			    return pesquisar(raiz->esquerda, valor);
			}
		}

	}

	return NULL;

}

tipoItem criarItem(int valor) {
    tipoItem item;
    item.valor = valor;
    return item;
}

tipoItem *alocar() {
    tipoNo *novoNo = (tipoNo*)malloc(sizeof(tipoNo));

    if(novoNo != NULL) {
        return novoNo;
    }
    else {
        printf("Erro ao criar um novo nó!!!\n");
        exit(1);
    }
}

int alturaNoh(tipoNo *raiz) {
    if (raiz == NULL) {
        return -1;
    }
    else {
        return raiz->altura;
    }
}

int fatorBalanceamento(tipoNo *raiz) {
    return labs(alturaNoh(raiz->esquerda) - alturaNoh(raiz->direita));
}

int alturaArvore(tipoNo *raiz){
	int alturaDireita = 0;
	int alturaEsquerda = 0;

	if (raiz == NULL) {	
		return -1;
	}

	alturaEsquerda = alturaArvore(raiz->esquerda);
	alturaDireita = alturaArvore(raiz->direita);

	if (alturaEsquerda > alturaDireita) {
		return alturaEsquerda + 1;
	}
	else {
		return alturaDireita + 1;
	}
}

int contarNos(tipoNo *raiz){
	if (raiz == NULL) {
		return 0;
		
	}
    else {
		return contarNos(raiz->esquerda) + contarNos(raiz->direita) + 1; 
	}
}

int maior(int x, int y) {
	if (x > y) {
		return x;
	}
	else {
		return y;
	}
}

void rotacaoDireita(tipoNo **raiz) {
	tipoNo *noAux;

	noAux = (*raiz)->esquerda;
	(*raiz)->esquerda  = noAux->direita;
	noAux->direita = *raiz;

	(*raiz)->altura = maior(alturaNoh((*raiz)->esquerda), alturaNoh((*raiz)->direita)) + 1;
	noAux->altura = maior(alturaNoh(noAux->esquerda), (*raiz)->altura) + 1;

	*raiz = noAux;
}

void rotacaoEsquerda(tipoNo **raiz) {
	tipoNo *noAux;

	noAux  = (*raiz)->direita;
	(*raiz)->direita  = noAux->esquerda;
	noAux->esquerda = *raiz;

	(*raiz)->altura = maior(alturaNoh((*raiz)->esquerda), alturaNoh((*raiz)->direita)) + 1;
	noAux->altura = maior (alturaNoh(noAux->esquerda), (*raiz)->altura) + 1;

	*raiz = noAux;
}

void rotacaoEsquerdaDireita(tipoNo **raiz) {
	rotacaoEsquerda(&(*raiz)->esquerda);
	rotacaoDireita(raiz);
}

void rotacaoDireitaEsquerda(tipoNo **raiz) {
	rotacaoDireita(&(*raiz)->direita);
	rotacaoEsquerda(raiz);
}

tipoNo* procuraMenor(tipoNo **raiz) {
    tipoNo *noAux1;
    tipoNo *noAux2;

    noAux1 = (*raiz);
    noAux2 = (*raiz)->esquerda;

    while(noAux2 != NULL)
    {
        noAux1 = noAux2;
        noAux2 = noAux2->esquerda;
    }
    return noAux1;
}

int inserir(tipoNo **raiz, int valor) {
    int controle;

	if (*raiz == NULL) {
		tipoNo *noAux = alocar();
		noAux->item.valor = valor;
		noAux->altura = 0;
		noAux->esquerda  = NULL;
		noAux->direita = NULL;
        *raiz = noAux;
		return 1;
	}

	tipoNo *noAtual;

	noAtual = *raiz;

    if(valor < noAtual->item.valor) {
        if((controle = inserir(&(noAtual->esquerda),valor)) == 1) {
            if(fatorBalanceamento(noAtual) >= 2) {
                if(valor < (*raiz)->esquerda->item.valor) {
                    rotacaoDireita(raiz);
                }
                else {
                    rotacaoEsquerdaDireita(raiz);
                }
            }
        }
    }
    else {
        if(valor > noAtual->item.valor) {
            if ((controle = inserir(&(noAtual->direita),valor)) == 1) {
                if(fatorBalanceamento(noAtual) >= 2) {
                    if(valor > (*raiz)->direita->item.valor) {
                        rotacaoEsquerda(raiz);
                    }
                    else {
                        rotacaoDireitaEsquerda(raiz);
                    }
                }
            }
        }
        else {
            printf("\nValor Duplicado!\n");
            return 0;
        }
    }
    noAtual->altura = maior(alturaNoh(noAtual->esquerda),alturaNoh(noAtual->direita)) + 1; 
    return controle;
}

int remover(tipoNo **raiz,int valor) {
    int controle;

    if(*raiz == NULL) {
        printf("\nEste valor não existe\n");
        return 0;
    }

    if(valor < (*raiz)->item.valor) {
        if((controle = remover(&((*raiz)->esquerda),valor)) == 1) {
            if(fatorBalanceamento(*raiz) >= 2) {
                if(alturaNoh((*raiz)->direita->esquerda)<=alturaNoh((*raiz)->direita->direita)) {
                    rotacaoEsquerda(raiz);
                }
                else {
                    rotacaoEsquerdaDireita(raiz);
                }
            }
        }
    }

    if(valor > (*raiz)->item.valor) {
        if ((controle = remover(&((*raiz)->direita),valor)) == 1) {
            if(fatorBalanceamento(*raiz) >= 2) {
                if(alturaNoh((*raiz)->esquerda->direita) <= alturaNoh((*raiz)->esquerda->esquerda)) {
                    rotacaoDireita(raiz);
                }
                else {
                    rotacaoDireitaEsquerda(raiz);
                }
            }
        }
    }

    if((*raiz)->item.valor == valor) {
        if(((*raiz)->esquerda == NULL) || ((*raiz)->direita == NULL)) {
            tipoNo *noAux = *raiz;

            if((*raiz)->esquerda != NULL)
                *raiz=(*raiz)->esquerda;
            else
                *raiz=(*raiz)->direita;
            free(noAux);
            noAux = NULL;
            printf("\nNó removido com sucesso!\n");
        }
        else {
            tipoNo *noAux = procuraMenor(&(*raiz)->direita);
            (*raiz)->item.valor = noAux->item.valor;
            remover(&(*raiz)->direita,(*raiz)->item.valor);
            if(fatorBalanceamento(*raiz) >= 2) {
                if(alturaNoh((*raiz)->esquerda->direita) <= alturaNoh((*raiz)->esquerda->esquerda)) {
                    rotacaoDireita(raiz);
                }
                else {
                    rotacaoEsquerdaDireita(raiz);
                }
            }
        }
        return 1;
    }
    return controle;
}

int main() {
	tipoNo *raiz = inicializar();
	int opcao = -1;
	int valor = 0;

	while(opcao != 0){
		printf("\n---Arvore atual---\n");
		imprimir(raiz, tamanhoDoEspaco);

		valor = 0;
		printf("\n---------------MENU---------------\n");
		printf("1: Inserir \n");
		printf("2: Remover \n");
		printf("3: Pesquisar \n");
		printf("0: SAIR \n");
		scanf("%d", &opcao);

		switch(opcao){

			case 1:
			printf("\n------INSERINDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);
			inserir(&raiz, valor);
			break;

			case 2:
			printf("\n------REMOVENDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);
			remover(&raiz, valor);
			break;

			case 3:
			printf("\n------PESQUISANDO------\n");
			printf("Digite um valor\n");
			scanf("%d",&valor);

			tipoNo *noAux = pesquisar(raiz, valor);
			if(noAux == NULL) {
				printf("\nElemento nao encontrado!\n");
			}
            else {
				printf("\nElemento encontrado com sucesso! \n");
			}
			break;

			case 0:
			printf("\nTchau! Ate a proxima\n");
			break;

			default:
			printf("\nOpcao inválida! \n");
			break;
		}
	}
	apagarArvore(raiz);

	return 0;
}
