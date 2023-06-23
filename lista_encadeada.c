#include <stdio.h>
#include <stdlib.h>
#include "lista_encadeada.h"

void inicializar(Lista* l) {
    l->inicio = NULL;
    l->fim = NULL;
}

void inserir_inicio(Lista* l, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = l->inicio;
    l->inicio = novo;

    if (l->fim == NULL) {
        l->fim = novo;
    }
}

void inserir_fim(Lista* l, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;
    novo->proximo = NULL;

    if (l->inicio == NULL) {
        l->inicio = novo;
        l->fim = novo;
    } else {
        l->fim->proximo = novo;
        l->fim = novo;
    }
}

void inserir_posicao(Lista* l, int valor, int posicao) {
    if (posicao < 0) {
        return;
    }

    if (posicao == 0) {
        inserir_inicio(l, valor);
        return;
    }

    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;

    No* atual = l->inicio;
    int cont = 0;

    while (cont < posicao - 1 && atual != NULL) {
        atual = atual->proximo;
        cont++;
    }

    if (atual == NULL) {
        free(novo);
        return;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;

    if (atual == l->fim) {
        l->fim = novo;
    }
}

void ordenar_lista(Lista* l) {
    if (l->inicio == NULL || l->inicio->proximo == NULL) {
        return;
    }

    int trocou;
    No* atual;
    No* anterior = NULL;

    do {
        trocou = 0;
        atual = l->inicio;

        while (atual->proximo != NULL) {
            if (atual->valor > atual->proximo->valor) {
                if (anterior != NULL) {
                    anterior->proximo = atual->proximo;
                } else {
                    l->inicio = atual->proximo;
                }

                No* proximo = atual->proximo;
                atual->proximo = proximo->proximo;
                proximo->proximo = atual;

                if (atual == l->fim) {
                    l->fim = proximo;
                }

                atual = proximo;
                trocou = 1;
            }

            anterior = atual;
            atual = atual->proximo;
        }
    } while (trocou);
}

void inserir_em_ordem(Lista* l, int valor) {
    if (l->inicio == NULL || valor < l->inicio->valor) {
        inserir_inicio(l, valor);
        return;
    }

    No* novo = (No*)malloc(sizeof(No));
    novo->valor = valor;

    No* atual = l->inicio;

    while (atual->proximo != NULL && valor > atual->proximo->valor) {
        atual = atual->proximo;
    }

    novo->proximo = atual->proximo;
    atual->proximo = novo;

    if (atual == l->fim) {
        l->fim = novo;
    }
}

void exibir_lista(Lista* l) {
    No* atual = l->inicio;

    printf("Lista: ");

    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }

    printf("\n");
}

void exibir_lista_reversa(Lista* l) {
    exibir_no_reverso(l->inicio);
}

void exibir_no_reverso(No* atual) {
    if (atual == NULL) {
        return;
    }

    exibir_no_reverso(atual->proximo);
    printf("%d ", atual->valor);
}


void remover_inicio(Lista* l) {
    if (l->inicio == NULL) {
        return;
    }

    No* primeiro = l->inicio;
    l->inicio = l->inicio->proximo;

    if (l->inicio == NULL) {
        l->fim = NULL;
    }

    free(primeiro);
}

void remover_fim(Lista* l) {
    if (l->inicio == NULL) {
        return;
    }

    if (l->inicio == l->fim) {
        free(l->inicio);
        l->inicio = NULL;
        l->fim = NULL;
        return;
    }

    No* atual = l->inicio;
    No* anterior = NULL;

    while (atual->proximo != NULL) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = NULL;
    l->fim = anterior;
    free(atual);
}

void remover_posicao(Lista* l, int posicao) {
    if (posicao < 0 || l->inicio == NULL) {
        return;
    }

    if (posicao == 0) {
        remover_inicio(l);
        return;
    }

    No* atual = l->inicio;
    No* anterior = NULL;
    int cont = 0;

    while (cont < posicao && atual != NULL) {
        anterior = atual;
        atual = atual->proximo;
        cont++;
    }

    if (atual == NULL) {
        return;
    }

    anterior->proximo = atual->proximo;

    if (atual == l->fim) {
        l->fim = anterior;
    }

    free(atual);
}

void remover_valor(Lista* l, int valor) {
    No* atual = l->inicio;
    No* anterior = NULL;

    while (atual != NULL) {
        if (atual->valor == valor) {
            if (anterior != NULL) {
                anterior->proximo = atual->proximo;

                if (atual == l->fim) {
                    l->fim = anterior;
                }

                free(atual);
                atual = anterior->proximo;
            } else {
                remover_inicio(l);
                atual = l->inicio;
            }
        } else {
            anterior = atual;
            atual = atual->proximo;
        }
    }
}

int procurar(Lista* l, int valor) {
    No* atual = l->inicio;
    int posicao = 0;

    while (atual != NULL) {
        if (atual->valor == valor) {
            return posicao;
        }

        atual = atual->proximo;
        posicao++;
    }

    return -1;
}

int calcular_somatorio(Lista* l) {
    int somatorio = 0;
    No* atual = l->inicio;

    while (atual != NULL) {
        somatorio += atual->valor;
        atual = atual->proximo;
    }

    return somatorio;
}

int obter_tamanho(Lista* l) {
    int tamanho = 0;
    No* atual = l->inicio;

    while (atual != NULL) {
        tamanho++;
        atual = atual->proximo;
    }

    return tamanho;
}

void elevar_ao_quadrado(Lista* l) {
    No* atual = l->inicio;

    while (atual != NULL) {
        atual->valor *= atual->valor;
        atual = atual->proximo;
    }
}

void liberar_lista(Lista* l) {
    No* atual = l->inicio;
    No* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }

    l->inicio = NULL;
    l->fim = NULL;
}
